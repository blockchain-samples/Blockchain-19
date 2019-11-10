#include "Blockchain.h"

Blockchain::Blockchain() {
  m_Chain.emplace_back(Block(0, "Initial Block"));
  m_Difficulty = 6;
}

void Blockchain::AddBlock(Block newBlock) {
  newBlock.prevHash = GetLastBlock().GetHash();
  newBlock.MineBlock(m_Difficulty);
  m_Chain.push_back(newBlock);
}

Block Blockchain::GetLastBlock() const { return m_Chain.back(); }
