#include <iostream>
#include <string>
#include "VirtualMachine.hpp"
#include "ErrorCode.hpp"

/**
 * Print the usage into cerr
 */
void printUsage()
{
  std::cerr << "USAGE\n\n"
            << "./corewar [-dump nbr_cycle] [[-n prog_number] [-a load_address] prog_name] ...\n\n"
            << "DESCRIPTION\n\n"
            << ""
            << "-dump nbr_cycle  "
            << "dumps the memory after the nbr_cycle execution (if the round isn't already over) with the following format: 32 bytes/line in hexadecimal (A0BCDEFE1DD3...)\n"
            << ""
            << "-n prog_number   "
            << "sets the next program's number. By default, the first free number in the parameter order\n"
            << ""
            << "-a load_address  "
            << "sets the next program's loading address. When no address is specified, optimize the addresses so that the processes are as far way from each other as possible. The addresses are MEM_SIZE modulo \n\n";
}

/**
 * Validate the command line before going any further
 *
 * @param int Passthrough of main function argc input
 * @param char* Passthrough of main function argv input
 * @return 0 if the command line is valid, an error code otherwise
 */
ErrorCode parseCommandLine(int argc, const char *const argv[], VirtualMachine &vm)
{
  auto atLeastOneChampionDefined = false;
  auto nextProgamNumber = 0;
  std::vector<unsigned char> programNumbers;

  for (auto i = 1; i < argc; ++i)
  {
    const std::string &arg = argv[i];
    const auto isLastArgument = (i == argc - 1);
    const auto isKnownArgument = arg == "-dump" || arg == "-n" || arg == "-a";

    // Check if arguments have a value defined after
    if (isKnownArgument && isLastArgument)
    {
      std::cerr << "[ERR ] Argument '" << arg << "' requires a value\n\n";
      printUsage();
      return ErrorCode::MISSING_ARG_VALUE;
    }
    // Check a valid value if provided for the argument
    if (isKnownArgument)
    {
      try
      {
        const auto value = std::stoi(argv[i + 1]);
        // Now, actually treat the command
        if (arg == "-dump")
        {
          vm.setDumpMemoryCycle(value);
        }
        else if (arg == "-n") {
          nextProgamNumber = (unsigned char)value;
          if (std::find(programNumbers.begin(), programNumbers.end(), nextProgamNumber) != programNumbers.end())
          {
            std::cerr << "[ERR ] [VM] Cannot assign program number " << nextProgamNumber << ", already assigned\n";
            return ErrorCode::INVALID_ARG_VALUE;
          }
        }
      }
      catch (...)
      {
        std::cerr << "[ERR ] Argument '" << arg << "' requires a valid integer value. Provided '" << argv[i + 1] << "' is not valid\n\n";
        printUsage();
        return ErrorCode::INVALID_ARG_VALUE;
      }
    }
    // Load an additional champion
    if (arg.ends_with(".cor"))
    {
      atLeastOneChampionDefined = true;
      auto code = vm.addChampion(arg, nextProgamNumber);
      if (code != ErrorCode::OK)
      {
        return code;
      }
      programNumbers.push_back(nextProgamNumber);
    }
  }

  if (!atLeastOneChampionDefined)
  {
    std::cout << "[INFO] [VM] Nothing to run, you did not provide any '.cor' in the command line\n\n";
    printUsage();
  }

  return ErrorCode::OK;
}

int main(int argc, char *argv[])
{
  try
  {
    VirtualMachine vm;

    ErrorCode errorCode = parseCommandLine(argc, argv, vm);
    if (errorCode != ErrorCode::OK)
    {
      return (int)errorCode;
    }
  }
  catch (const std::exception &e)
  {
    std::cerr << "[ERR ] " << e.what();
    return (int)ErrorCode::UNKNOWN_ERROR;
  }

  return 0;
}
