#ifndef VIRTUAL_MACHAINE
#define VIRTUAL_MACHINE

class VirtualMachine {
  public:
    VirtualMachine();
    ~VirtualMachine();

    void setDumpMemoryCycle(unsigned int);

  private:
    unsigned int dumpMemoryCycle = -1;
};

#endif