#include <iostream>
#include "VirtualMachine.hpp"

VirtualMachine::VirtualMachine() {
  std::cout << "[VM] Setting up\n";
}

VirtualMachine::~VirtualMachine() {

}

void VirtualMachine::setDumpMemoryCycle(unsigned int dumpMemoryCycle) {
  this->dumpMemoryCycle = dumpMemoryCycle;
  std::cout << "[VM] Memory will be dumped after " << dumpMemoryCycle << " cycles\n";
}