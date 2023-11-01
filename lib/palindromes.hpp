//By: Gabriel Rodriguez, Joaquin Badilla, Iker Garcia
// Date: 01/11/2023
// Description: This file contains the function longestPalindrome which takes a string and returns the longest palindrome in the string.

#include <iostream>
#include <string>
#include <vector>

using namespace std; // Using standard namespace


// function: finds the longest palindrome using the Manacher's algorithm
// parameters: string text (string to find the longest palindrome)
// returns: string (longest palindrome in the string)
// computational complexity: O(n)
string manacherPalindrome(const string &text) {
    int n = text.size() * 2 + 1;

    // Cinverts the string to a even length string with # in between each character.
    string proString = "#";
    for (char c : text) {
        proString += c;
        proString += '#';
    }

    vector<int> PalindromeArr(n, 0);  // Array store palindrome length for each index.
    int center = 0;  // Current cener of the last palindrome found
    int palindromeLength = 0;   // End of the last palindrome found

    for (int i = 0; i < n; i++) {
        int mirror = 2 * center - i;  // Find the mirror of the current index.

    
        if (i < palindromeLength) {
            PalindromeArr[i] = min(palindromeLength - i, PalindromeArr[mirror]);
        }

        // Expand around the current character to find a longer palindrome.
        int j = i + (1 + PalindromeArr[i]);
        int k = i - (1 + PalindromeArr[i]);
        while (j <= n-1 && k >= 0 && proString[j] == proString[k]) 
        {
            PalindromeArr[i]++;
            j++;
            k--;
        }

        // If the expanded palindrome expands beyond the right boundary, update the center and right boundary.
        if (i + PalindromeArr[i] > palindromeLength) {
            center = i;
            palindromeLength = i + PalindromeArr[i];
        }
    }

    // Find the maximum length palindrome and its center.

    int max = 0;
    for (int i = 0; i < n; i++) {
        if (PalindromeArr[i] > PalindromeArr[max]) {
            max = i;
        }
    }

    int start = (max - PalindromeArr[max]) / 2;  // Starting index of the longest palindrome.
    int end = PalindromeArr[max];  // Ending index of the longest palindrome.

    // Extract and return the longest palindromic substring from the processed string.
    return start, end;
}
