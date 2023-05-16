/* 
 * [2019] Signet Lab - Programming for ICT
 * All Rights Reserved.
 * 
 * Authors Filippo Campagnaro and Michele Polese 
 */

/**
 * @file my-buffer.h
 * @author Filippo Campagnaro
 * @version 1.0.0
 * @brief Struct MyBuffer.
 */
#ifndef H_MY_BUFF
#define H_MY_BUFF

#include <vector>
#include <memory>

struct MyBuffer {
  /** Shared Pointer to the Buffer where the data will be stored **/
  std::shared_ptr<std::vector<char>> buf; 
  /** 
   * Number of Bytes stroed in the buffer, to be set  
   * manually after storing new data in the buffer 
   */
  size_t n_bytes; 

  /** 
   * Struct constructor
   * @param buffer_max_size with the maximum size of the buffer
   */
  MyBuffer(size_t buffer_max_size) 
  : 
    buf(std::make_shared<std::vector<char>>(buffer_max_size)), 
    n_bytes(0) 
  {

  }
  
  /** 
   * Method to direct access the underlying C array, that can be used to 
   * store and read data into the buffer e.g., 
   *   read(sock_fd,buf.dataAccess(),buf.getMaxSize());
   * @return the pointer to the underlying C array
   */
  char* dataAccess() const {
    return buf->data();
  }

  /** 
   * Method to return the maximum size, in Bytes, that can be stored 
   * into the buffer
   * @return the maximum size that can be stored into the buffer
   */
  size_t getMaxSize() const {
    return buf->size();
  }

};

#endif /* H_MY_BUFF */
