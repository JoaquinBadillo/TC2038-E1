#ifndef READER_H
#define READER_H

/*
  Reader Header File

  Contains utilities to read the contents of files.
  
  Last Update: 30/Oct/2023
  Author: Joaquín Badillo
*/

#include <string>
#include <fstream>
#include <sstream>

std::string reader(const std::string& inFile) {
  std::ifstream file;
  std::stringstream stream;
  
  try {
    file.open(inFile);
  } catch (const std::exception&) {
    return "";
  }
  
  if (file.is_open()) {
    stream << file.rdbuf();
    file.close();
  }
  
  return stream.str();
}


#endif
