#ifndef SUBSTRINGS_H
#define SUBSTRINGS_H

/*
  Substrings Header File

  Contains utilities to find similarities between two strings.
  
  Last Update: 30/Oct/2023
*/

#include <string>
#include <vector>
#include <optional>

namespace p1 {
  std::vector<int> preprocessing(const std::string &pattern) {
      int n = pattern.length();

      std::vector<int> V(n);
      int j = 0;
      int i = 1;
      V[0] = 0;

      while (i < n) {
          if (pattern[i] == pattern[j]) {
              V[i] = j + 1;
              i++;
              j++;
          } else {
              if (j == 0) {
                  V[i] = 0;
                  i++;
              } else {
                  j = V[j - 1];
              }
          }
      }

      return V;
  }

  std::optional<int> isSubstring(const std::string &text, const std::string &pattern) {
    int n = text.length();
    int m = pattern.length();

    std::vector<int> V = preprocessing(pattern);
    int pos = 0;
    int j = 0;
    int i = 0;

    while (i < n) {
      if (text[i] == pattern[j]) {
        i++;
        j++;
        // Slight modification to return starting index of the substring
        if (j == m)
          return i - m + 1;
      } else {
        if (j == 0) {
          i++;
          pos = i;
        } else {
          pos = i - V[j - 1];
          j = V[j - 1];
        }
      }
    }

    return {};
  }
}

#endif