#include <iostream>
#include "Champion.hpp"
#include "ChampionReader.hpp"

Champion::Champion() : state(ChampionState::NONE)
{
}

Champion::~Champion()
{
}

/**
 * Read a program from "path" and save its binary content into a char buffer
 */
ErrorCode Champion::load(const std::filesystem::path &path)
{
  this->path = path;

  std::vector<char> buffer;
  ChampionReader reader(path);
  auto res = reader.readProgram(buffer);
  if (res != ErrorCode::OK)
  {
    std::cerr << "[ERR ] Unable to load champion at path " << path << "\n";
    return res;
  }

  this->state = ChampionState::READY;
  return ErrorCode::OK;
}

/**
 * Set the program number. If it's 0, ignore it.
 */
void Champion::setProgramNumber(unsigned char programNumber)
{
  if (programNumber == 0) {
    return;
  }
  std::cout << "[INFO] [VM] Champion at path " << this->path << " is assigned to program number " << (int)programNumber << "\n";
  this->programNumber = programNumber;
}