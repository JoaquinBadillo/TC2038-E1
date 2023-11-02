# TC2038-E1

First Project for Tec de Monterrey's B.S. in Computer Science and Technology TC2038 course:
Analysis and Design of Advanced Algorithms.

## Description

Write a C++ program that reads 5 text files (with fixed names, not provided by the user)
containing only characters from 0 to 9, characters between A and F, and line breaks:

* `transmission1.txt`
* `transmission2.txt`
* `mcode1.txt`
* `mcode2.txt`
* `mcode3.txt`

The transmission files contain text characters representing the data transmission from one device to another.
The `mcodeX.txt` files represent malicious code that can be found within a transmission.

The program should analyze whether the content of `mcode1.txt`, `mcode2.txt`, and `mcode3.txt` files is contained
within `transmission1.txt` and `transmission2.txt` files and display `true` or `false` if the character sequences are
contained or not. If it's `true,` it should display `true,` followed by exactly one space, followed by the position
in the `transmissionX.txt` file where `mcodeY.txt` begins.

Assuming that the malicious code is always "mirrored" (character palindromes), it would be a good idea to search for
this type of code in a transmission. The program should then search for mirrored code within the transmission files
(character-level palindromes, not at the bit level). The program should display, on a single line, two integers
separated by a space, corresponding to the starting and ending positions (starting from 1) of the longest mirrored
code (palindrome) for each transmission file. It can be assumed that this type of code will always be found.

Finally, the program analyzes how similar the transmission files are and should display the starting and ending
positions (starting from 1) of the first file where the longest common substring between both transmission files
is found.

## Usage

Compile using C++ 17; for instance, if you are using g++, execute:

```{console}
$ g++ --std=c++17 main.cpp
```

Then execute the file:

```{console}
$ ./a.out
```
