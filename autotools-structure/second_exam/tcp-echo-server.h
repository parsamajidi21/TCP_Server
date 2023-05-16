/* 
 * [2019] Signet Lab - Programming for ICT
 * All Rights Reserved.
 * 
 * Authors Filippo Campagnaro and Michele Polese 
 */

/**
 * @file tcp-server.h
 * @author Filippo Campagnaro
 * @version 1.0.0
 * @brief Socket TCP server class.
 */

#ifndef H_TCP_SERVER_FS
#define H_TCP_SERVER_FS

#include "ethernet-connector.h"



/**
 * Class TcpEchoServer
 */
class TcpEchoServer : public Ethernet
{
public:
  /**
   * Class constructor.
   * @param port_num integer with the port number
   */
  TcpEchoServer(int port_num);

  /**
   * Class destructor.
   */
  virtual ~TcpEchoServer();

  /**
   * Accept a new connection and store the IP.
   * @return false if accept fails
   */
  bool acceptConn();

  /**
   * Receive data from remote host.
   * @param buf the buffer where the received data is stored
   * @return number of bytes received (-1 if error occurred)
   */
  int receive(MyBuffer& buf) override;

  /**
   * Send data to remote host.
   * @param buf the buffer where the data to be sent is stored
   * @return number of bytes sent (-1 if error occurred)
   */
  int transmit(MyBuffer& buf) override;

  /**
   * Print the tcp server to the ostream
   * @param out a ostream
   */
  void printObject(std::ostream& out) const override;

private:
  int l_sock_fd; /**< listener socket file descriptor */
  int sock_fd; /**< data socket file descriptor */

  /** counter of the number of connections*/
  size_t connections_count;

  /**
   * Set the socket options and bind.
   * @return false as soon as any of the operations it performs fails
   */
  bool optionsAndBind();

};

#endif /* H_TCP_SERVER_FS */
