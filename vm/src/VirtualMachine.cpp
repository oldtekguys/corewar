#include <iostream>
#include "VirtualMachine.hpp"
#include "ErrorCode.hpp"

VirtualMachine::VirtualMachine() : champions(4)
{
  std::cout << "[INFO] [VM] Setting up\n";
}

VirtualMachine::~VirtualMachine()
{
}

void VirtualMachine::setDumpMemoryCycle(unsigned int dumpMemoryCycle)
{
  this->dumpMemoryCycle = dumpMemoryCycle;
  std::cout << "[INFO] [VM] Memory will be dumped after " << dumpMemoryCycle << " cycles\n";
}

int VirtualMachine::getChampionCount()
{
  int count = 0;
  for (const auto &champion : this->champions)
  {
    if (champion.getState() != ChampionState::NONE)
    {
      ++count;
    }
  }
  return count;
}

ErrorCode VirtualMachine::addChampion(const std::filesystem::path &path, unsigned char programNumber)
{
  if (this->getChampionCount() >= 4)
  {
    std::cerr << "[ERR ] [VM] Cannot load additional champion, the maximum is 4 and all slots are already taken. Try again with less champions.\n";
    return ErrorCode::TOO_MANY_CHAMPION;
  }

  for (auto &champion : this->champions)
  {
    if (champion.getState() == ChampionState::NONE) // Find a free slot
    {
      std::cout << "[INFO] [VM] Attempting to load champion at " << path.string() << "\n";
      auto res = champion.load(path);
      if (res != ErrorCode::OK)
      {
        return res;
      }
      champion.setProgramNumber(programNumber);
      std::cout << "[INFO] [VM] Successfully loaded champion at " << path.string() << "\n";
      return ErrorCode::OK;
    }
  }

  // We already checked previously that we don't already have more than 4 loaded champions, so
  // we should never reach this piece of code. So we return a special error code.
  return ErrorCode::TOO_MANY_CHAMPION_UNEXPECTED;
}