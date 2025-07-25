#include <iostream>
#include <string>

#include "console.h"
#include "init.h"
#include "position.h"
#include "search.h"
#include "uci.h"

int main(int argc, char *argv[]) {
  initAll();

  Position pos;
  searchInfo info;
  initHashTable(pos.hashTable, 128);

  std::cout << "Welcome to " << name
            << " made by Lokesh\nType 'wuttang' for console mode...\n";
  std::string input;

  while (true) {
    std::cin.sync();
    std::getline(std::cin, input);

    if (input == "uci") {
      UCI_loop(pos, info);
    } else if (input == "wuttang") {
      Console_loop(pos, info);
    } else if (input == "quit") {
      info.quit = true;
    } else {
      std::cout << "Unknown command\n";
    }
    if (info.quit) {
      break;
    }
  }

  delete[] pos.hashTable.pTable;

  return 0;
}
