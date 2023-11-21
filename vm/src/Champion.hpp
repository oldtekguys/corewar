#ifndef CHAMPION
#define CHAMPION

#include <filesystem>
#include "ErrorCode.hpp"

enum class ChampionState
{
  NONE,
  READY,
  RUNNING,
  DEAD,
};

class Champion
{
public:
  Champion();
  ~Champion();

  ErrorCode load(const std::filesystem::path &);
  ChampionState getState() const { return state; }
  void setProgramNumber(unsigned char programNumber);

private:
  std::filesystem:: path path;
  ChampionState state;
  unsigned char programNumber = 0;
};

#endif