/*
 * [2019] Signet Lab - Programming for ICT
 * All Rights Reserved.
 * 
 * Authors Filippo Campagnaro and Michele Polese 
*/

#include <basic-utilities.h>
#include <string.h>

#include <iostream>

int main(int argc, char* argv[])
{

  std::string input = "HELLO WORLD!";
  std::string output;
  size_t length = 16;
  bool result = BasicUtils::zeroPadding(input, 
  length, output);
  std::cout << output << std::endl;

  if(result) {
  	return (int)TestResult::PASSED;
  }
  return (int)TestResult::FAILED;
}
