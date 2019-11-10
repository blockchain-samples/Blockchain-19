#ifndef _BC_BLOCKCHAIN
#define _BC_BLOCKCHAIN

#include <vector>

#include "Block.h"

class Blockchain {
 public:
  Blockchain();
  void AddBlock(Block newBlock);

 private:
  uint32_t m_Difficulty;
  std::vector<Block> m_Chain;
  Block GetLastBlock() const;
};
#endif  // !_BC_BLOCKCHAIN
