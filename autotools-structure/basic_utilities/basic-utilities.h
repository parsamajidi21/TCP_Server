/* 
 * [2019] Signet Lab - Programming for ICT
 * All Rights Reserved.
 * 
 * Authors Filippo Campagnaro and Michele Polese 
 */

/**
 * @file basic-utilities.h
 * @author Filippo Campagnaro
 * @version 1.0.0
 * @brief Name space for binding sockets and set common options.
 */

#ifndef BASIC_UTIL
#define BASIC_UTIL

#include <string>

/**Define the results of the test.*/
enum class TestResult : int {
  PASSED = 0,
  FAILED = 1
};

/**
 * Namespace BasicUtils containing basic utilities methods that are so useful
 */
namespace BasicUtils
{

  /**
   * Method provides a string padded with zeros up to a fixed size.
   * @param input_string string containing the input to be "padded"
   * @param total_length overall length of the output string 
   * @param output_sting output parameter containing the "padded" string
   * @return true if the operation succeeded, false if the original sting size > total_length.
   */
  bool zeroPadding(const std::string& input_sting, 
    size_t total_length, std::string& output_sting);

};

#endif /* BASIC_UTIL */
