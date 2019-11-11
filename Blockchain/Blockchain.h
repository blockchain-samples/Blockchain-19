#ifndef _BC_BLOCKCHAIN
#define _BC_BLOCKCHAIN

#include <vector>

#include "Block.h"

class Blockchain {
 public:
  Blockchain(uint32_t difficulty = 1);
  void AddBlock(Block newBlock);

 private:
  uint32_t m_Difficulty;
  std::vector<Block> m_Chain;
  Block GetLastBlock() const;
};
#endif  // !_BC_BLOCKCHAIN
