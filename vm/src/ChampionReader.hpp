#ifndef CHAMPION_READER
#define CHAMPION_READER

#include <filesystem>
#include "ErrorCode.hpp"

class ChampionReader {
  public:
    ChampionReader(const std::filesystem::path&);
    ~ChampionReader();

    ErrorCode readProgram(std::vector<char>&);

  private:
    std::filesystem::path championPath;
};

#endif