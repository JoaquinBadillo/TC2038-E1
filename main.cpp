#include <string>
#include <vector>
#include <iostream>

#include "./lib/reader.hpp"
#include "./lib/substrings.hpp"
#include "./lib/palindromes.hpp"
#include "./lib/longest_substring.hpp"


int main (int argc, char *argv[]) {
  std::cout 
    << reader("transmission1.txt") 
    << std::endl;

  /*

  std::vector<std::string> transmissions;
  std::vector<std::string> maliciousCodes;

  for (int i = 1; i < 3; ++i)
    transmissions.push_back(reader("./transmission" + i + ".txt"))
  
  for (int i = 1; i < 4; ++i)
    maliciousCodes.push_back(reader("./mcode1.txt"));
  
  */

  /* ToDo:
    Part 1 Logs
    Part 2 Logs
    Part 3 Logs
  */
  
  return 0;
}
