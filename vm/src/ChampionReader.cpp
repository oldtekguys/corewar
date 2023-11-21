#include <iostream>
#include <fstream>
#include "ChampionReader.hpp"

ChampionReader::ChampionReader(const std::filesystem::path &championPath)
    : championPath(championPath)
{
}

ChampionReader::~ChampionReader()
{
}

/**
 * Read the program binary code into ChampionReader::handle
 * @throw
 */
ErrorCode ChampionReader::readProgram(std::vector<char> &buffer)
{
  std::ifstream handler;
  handler.open(this->championPath, std::ios::in | std::ios::binary);

  if (!handler.good())
  {
    std::cerr << "[ERR ] [ChampionReader] Cannot open champion program at " + this->championPath.string() << "\n";
    return ErrorCode::INVALID_ARG_VALUE;
  }

  // Get file size
  handler.seekg(0, handler.end);
  std::streampos length = handler.tellg();
  handler.seekg(0, handler.beg);

  if (length <= 0)
  {
    std::cerr << "[ERR ] [ChampionReader] Cannot get champion binary program length for " + this->championPath.string() << "\n";
    return ErrorCode::INVALID_PROGRAM_LENGTH;
  }

  buffer.resize(length);
  handler.read(buffer.data(), length);

  std::cout << "[INFO] [ChampionReader] Read " << length << " bytes from champion at " << this->championPath.string() << "\n";

  return ErrorCode::OK;
}