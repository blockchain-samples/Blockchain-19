#ifndef _BC_BLOCK
#define _BC_BLOCK

#include <cstdint>
#include <iostream>

class Block {
 public:
  std::string prevHash;
  Block(std::uint32_t indexIn, const std::string& dataIn);
  std::string GetHash();
  void MineBlock(uint32_t difficulty);

 private:
  uint32_t m_Index;
  int64_t m_Nonce;
  std::string m_Data;
  std::string m_Hash;
  time_t m_Time;

  std::string CalculateHash() const;
};
#endif  // !_BC_BLOCK
