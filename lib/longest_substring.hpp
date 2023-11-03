#ifndef LONGEST_SUBSTRING_H
#define LONGEST_SUBSTRING_H

/* 
  Longest Substring Header File

  Contains utilities to find the longest substring between two strings.
  
  ** Requires C++ 17: Please compile with --std=c++17

  Last Update: 31/Oct/2023
*/


#include <optional> 
#include <utility>
#include <string>
#include <iostream>

// Enclose everything in a namespace to prevent name collisions
namespace p3 {
  // Using an optional type for the result.
  // This means the result can either hold a value of type pair<int, int> or no value at all.
  typedef std::optional<std::pair<int, int>> Result;

  // Returns the longest substring between s1 and s2
  Result longest_substring(const std::string &s1, const std::string &s2) {
    int n = s1.length();
    int m = s2.length();

    // 2D memoization table
    int memo[n + 1][m + 1];
    int max = 0;
    int end = -1;
    
    // Initialize the matrix with 0s in the first row and col
    for (int i = 0; i < n + 1; ++i)
      memo[i][0] = 0;

    for (int j = 0; j < m; ++j)
      memo[0][j] = 0;
    
    // Fill the DP matrix
    for (int i = 1; i < n + 1; i++) {
      for (int j = 1; j < m + 1; j++) {
        // If characters match, consider it as part of the substring
        if (s1[i - 1] == s2[j - 1]) {
          memo[i][j] = memo[i - 1][j - 1] + 1;
          // If current substring is longer than max, update max and end
          if (memo[i][j] > max) {
            max = memo[i][j];
            end = i - 1;
          }
        } 
        else {
          // If characters do not match, reset current cell to 0
          memo[i][j] = 0;
        }
      }
    }
    
    // If no common substring was found, return an empty optional
    if (end == -1) 
      return {};

    // Construct result using the max length and the end position
    std::pair<int, int> res = std::make_pair(end - max + 1, end);
    return res;
  }
}

#endif
