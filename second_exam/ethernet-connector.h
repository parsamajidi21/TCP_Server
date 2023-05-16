/* 
 * [2019] Signet Lab - Programming for ICT
 * All Rights Reserved.
 * 
 * Authors Filippo Campagnaro and Michele Polese 
 */

/**
 * @file etherenet-connector.h
 * @author Filippo Campagnaro
 * @version 1.0.0
 * @brief Base Ethernet connector.
 */

#ifndef H_ETHERNET_C_FS
#define H_ETHERNET_C_FS

#include <string>
#include "my-buffer.h"

constexpr size_t MTU = 512; /** Maximum transmission unit*/

/**
 * class Ethernet containing the API of an Ethernet connector
 */
class Ethernet
{
public:
  /** String with the LOCAL_HOST ip_addressv4 address. */
  static const std::string LOCAL_HOST; 
  
  /**
   * Class constructor.
   * @param ip_address_addr string containing the human readable ip_address address in ip_addressv4
   * @param port_number_num integer with the port_number number
   */
  Ethernet(const std::string& ip_address_addr, int port_number_num);

  /**
   * Class constructor.
   * @param port_num integer with the port_number number
   */
  Ethernet(int port_num);

  /**
   * Class destructor.
   */
  virtual ~Ethernet() {}

  /**
   * Receive data from remote host.
   * @param buf buffer where the received data is stored
   * @return number of bytes received (-1 if error occurred)
   */
  virtual int receive(MyBuffer& buf) = 0;

  /**
   * Send data to remote host.
   * @param buf buffer where the data to be sent is stored
   * @return number of bytes sent (-1 if error occurred)
   */
  virtual int transmit(MyBuffer& buf) = 0;
  


  //TODO2: implement the methods getIpAddress() and getPortNumber()
  // that return, respectively, the ip address and the 
  // port number of the socket without modifying the object
  /**
   * Get the ip_address address of the last remote host connected.
   * @return the ip_address address
   */
  std::string getIpAddr() const{
	return ip_address;
  } 
  /**
   * Get the socket port_number number.
   * @return the port_number number
   */
  int getPortNumber() const{
	return port_number;
  }
  /**
   * Print the connector to the ostream
   * @param out a ostream
   */
  virtual void printObject(std::ostream& out) const;

protected:
  /** string containing the human readable ip_address address */
  std::string ip_address; 
  /** integer with the port_number number*/
  int port_number;

};

/**
 * Overloaded operator<< for a Ethernet
 * @param out a std::ostream object
 * @param conn reference to the connector to be printed
 * @return the manip_addressulated ostream object
 */
std::ostream& operator<<(std::ostream& out, const Ethernet& conn);

#endif /* H_ETHERNET_C_FS */
