#include "Blockchain.h"

int main() {
  Blockchain blockChain = Blockchain(6);

  std::cout << "Mining a block 1" << std::endl;
  blockChain.AddBlock(Block(1, "Block 1 Data"));

  std::cout << "Mining a block 2" << std::endl;
  blockChain.AddBlock(Block(2, "Block 2 Data"));

  std::cout << "Mining a block 3" << std::endl;
  blockChain.AddBlock(Block(3, "Block 3 Data"));

  return 0;
}
