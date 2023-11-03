#include <string>
#include <vector>
#include <iostream>

#include "./lib/reader.hpp"
#include "./lib/substrings.hpp"
#include "./lib/longest_substring.hpp"
#include "./lib/palindromes.hpp" 

int main (int argc, char *argv[]) {
  // Initialize vectors to hold the contents of the transmissions and malicious codes.
  std::vector<std::string> transmissions;
  std::vector<std::string> maliciousCodes;

   // Read in the transmission text files.
  for (int i = 0; i < 2; ++i) {
    std::stringstream ss;
    ss << "transmission" << i + 1 << ".txt";
    transmissions.push_back(reader(ss.str()));
  }
  // Read in the malicious code text files.
  for (int i = 0; i < 3; ++i) {
    std::stringstream ss;
    ss << "mcode" << i + 1 << ".txt";
    maliciousCodes.push_back(reader(ss.str()));
  }


  // Part 1 - Checking for malicious codes
  std::cout << "Parte 1" << std::endl;
  for (auto transmission = transmissions.begin(); transmission != transmissions.end(); ++transmission) {
    for (auto maliciousCode = maliciousCodes.begin(); maliciousCode != maliciousCodes.end(); ++maliciousCode) {
      // Check if the malicious code is a substring of the transmission.
      std::optional<int> res = p1::isSubstring(*transmission, *maliciousCode);
      if (res.has_value())
        // If a malicious code is found, print true and the index.
        std::cout << " true " << res.value() << std::endl;
      else
        // If not found, print false.
        std::cout << " false" << std::endl;
    }
  }

  // Part 2
  std::cout << "Parte 2" << std::endl;
  for (auto transmission = transmissions.begin(); transmission != transmissions.end(); ++transmission) { // Use Manacher's algorithm to find the longest palindromic substring.
    std::pair<int, int> res = p2::manacherPalindrome(*transmission);
    // Print the start and end indices of the longest palindrome.
    std::cout << " " << res.first << " " << res.second << std::endl;
  }

  // Part 3 - Checking similarities between transmissions
  std::cout << "Parte 3" << std::endl;

  // Get indexes on the first transmission
  p3::Result res = p3::longest_substring(transmissions[0], transmissions[1]);

  if (res.has_value())
    // If a common substring is found, print the starting index and length.
    std::cout << " " << res.value().first << " " << res.value().second << std::endl;
  else
    // If no common substring is found, print a message indicating no match.
    std::cout << " Ninguna coincidencia" << std::endl;
  
  return 0;
}
