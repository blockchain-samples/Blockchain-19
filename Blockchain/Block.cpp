#include "Block.h"

#include <ctime>
#include <sstream>

#include "vendor/sha256.h"

Block::Block(std::uint32_t indexIn, const std::string& dataIn)
    : m_Index(indexIn), m_Data(dataIn) {
  m_Nonce = -1;
  m_Time = std::time(nullptr);
}

std::string Block::GetHash() { return m_Hash; }

void Block::MineBlock(uint32_t difficulty) {
  char* cstr = new char[difficulty + 1];

  // Fill number of starting zeros for hash.
  for (uint32_t i = 0; i < difficulty; i++) {
    cstr[i] = '0';
  }
  cstr[difficulty] = '\0';

  std::string str(cstr);

  // Calculate hash and check if it is available to be mined.
  do {
    m_Nonce++;
    m_Hash = CalculateHash();
  } while (m_Hash.substr(0, difficulty) != str);

  std::cout << "Block mined:" << m_Hash << std::endl;
}

// inline to cutdown on method calls
inline std::string Block::CalculateHash() const {
  std::stringstream ss;
  ss << m_Index << m_Time << m_Data << m_Nonce << prevHash;
  return sha256(ss.str());
}
