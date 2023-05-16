/* 
 * [2019] Signet Lab - Programming for ICT
 * All Rights Reserved.
 * 
 * Authors Filippo Campagnaro and Michele Polese 
 */

#include <basic-utilities.h>

bool BasicUtils::zeroPadding(const std::string& input_sting, 
  size_t total_length, std::string& output_sting)
{
  if(total_length < input_sting.size()) {
    return false;
  }
  output_sting = input_sting;
  while(output_sting.size() != total_length) {
    // THIS IS THE INEFFICIENT WAY TO DO THAT, BUT IT IS JUST A BASIC EXAMPLE
    output_sting += "0";
  }
  return true;
}
