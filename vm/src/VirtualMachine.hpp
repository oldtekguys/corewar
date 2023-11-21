#ifndef VIRTUAL_MACHAINE
#define VIRTUAL_MACHINE

#include "Champion.hpp"

class VirtualMachine {
  public:
    VirtualMachine();
    ~VirtualMachine();

    void setDumpMemoryCycle(unsigned int);
    ErrorCode addChampion(const std::filesystem::path&, unsigned char);

  private:
    int getChampionCount();

  private:
    unsigned int dumpMemoryCycle = -1;
    std::vector<Champion> champions;
};

#endif