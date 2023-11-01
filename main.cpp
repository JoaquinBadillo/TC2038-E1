#include <string>
#include <vector>
#include <iostream>

#include "./lib/reader.hpp"
#include "./lib/substrings.hpp"
#include "./lib/longest_substring.hpp"

int main (int argc, char *argv[]) {
  std::vector<std::string> transmissions;
  std::vector<std::string> maliciousCodes;

  for (int i = 0; i < 2; ++i) {
    std::stringstream ss;
    ss << "transmission" << i + 1 << ".txt";
    transmissions.push_back(reader(ss.str()));
  }

  for (int i = 0; i < 3; ++i) {
    std::stringstream ss;
    ss << "mcode" << i + 1 << ".txt";
    maliciousCodes.push_back(reader(ss.str()));
  }


  // Part 1 - Checking for malicious codes
  std::cout << "Parte 1" << std::endl;
  for (auto transmission = transmissions.begin(); transmission != transmissions.end(); ++transmission) {
    for (auto maliciousCode = maliciousCodes.begin(); maliciousCode != maliciousCodes.end(); ++maliciousCode) {
      std::cout 
        << " "
        << (p1::isSubstring(*transmission, *maliciousCode) ? "true" : "false")
        << std::endl;
    }
  }

  // Part 2
  std::cout << "Parte 2" << std::endl;
  /* Palindromes */

  // Part 3 - Checking similarities between transmissions
  std::cout << "Parte 3" << std::endl;

  // Use the longest substring as the main string
  p3::Result res;
  if (transmissions[0].length() > transmissions[1].length())
    res = p3::longest_substring(transmissions[0], transmissions[1]);
  else
   res = p3::longest_substring(transmissions[1], transmissions[0]);

  // Prints the starting and ending indices (in the longest string) of the longest substring
  if (res.has_value())
    std::cout << " " << res.value().first << " " << res.value().second << std::endl;
  else
    std::cout << " Ninguna coincidencia" << std::endl;
  
  
  return 0;
}
