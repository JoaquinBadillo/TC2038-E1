#ifndef SUBSTRINGS_H
#define SUBSTRINGS_H

/*
  Substrings Header File

  Contains utilities to find similarities between two strings.
  
  Last Update: 30/Oct/2023
*/

#include <string>
#include <vector>

namespace p1 {
  // Function to preprocess a pattern string and return a vector of integers
  std::vector<int> preprocessing(const std::string &pattern) {
    // Find the length of the pattern
      int n = pattern.length();

      // Create a vector with the size of the pattern length
      std::vector<int> V(n);
      // Initialize two pointers for processing the pattern
      int j = 0;
      int i = 1;
      // Base condition for the first character of the pattern
      V[0] = 0;

      // Loop through the pattern to create the preprocessing table
      while (i < n) {
          if (pattern[i] == pattern[j]) { // If the characters match, update the preprocessing table
              V[i] = j + 1;
              i++;
              j++;
          } else {
              if (j == 0) { // If no match and j is at the beginning, reset the table entry
                  V[i] = 0;
                  i++;
              } else { // If no match, update j to the last known match
                  j = V[j - 1];
              }
          }
      }

      return V;
  }
  // Function to check if a pattern string is a substring of a text string
  bool isSubstring(const std::string &text, const std::string &pattern) {
    // Find the lengths of the text and the pattern
    int n = text.length();
    int m = pattern.length();

    std::vector<int> V = preprocessing(pattern);
    // Initialize pointers for both text and pattern
    int pos = 0;
    int j = 0;
    int i = 0;
    // Loop through the text to find the pattern
    while (i < n) {
      if (text[i] == pattern[j]) { // If the current characters match, increment pointers
        i++;
        j++;

        if (j == m) { // If we have reached the end of the pattern, return true
          return true;
        }
      } else { // If no match and j is at the beginning, increment i
        if (j == 0) { 
          i++;
          pos = i;
        } else { // If no match, update i and j based on the preprocessing table
          pos = i - V[j - 1];
          j = V[j - 1];
        }
      }
    }
    // If the pattern was not found in the text, return false
    return false;
  }
}

#endif