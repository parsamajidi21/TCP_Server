/* 
 * [2019] Signet Lab - Programming for ICT
 * All Rights Reserved.
 * 
 * Authors Filippo Campagnaro and Michele Polese 
 */

#include <tcp-echo-server.h>
#include <string.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <iostream>

TcpEchoServer::TcpEchoServer(int port_num)
:
Ethernet(port_num),
l_sock_fd(-1),
sock_fd(-1),
connections_count(0)
{
  l_sock_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (l_sock_fd < 0){ 
    std::cout << "ERROR: OPEN SOCKET" << std::endl;
    close(l_sock_fd);
    return;
  }
  if(!optionsAndBind()) {
  	std::cout << "ERROR: BIND" << std::endl;
    close(l_sock_fd);
    return;
  }
}

TcpEchoServer::~TcpEchoServer() {
  if(l_sock_fd >= 0) {
    close(l_sock_fd);
  }
  if(sock_fd >= 0) {
    close(sock_fd);
  }
}

bool TcpEchoServer::optionsAndBind() 
{
  int option(1);
  if(setsockopt(l_sock_fd, SOL_SOCKET, SO_REUSEADDR, 
                  (char*)&option, sizeof(option)) < 0) {
    std::cout << "ERROR: setsockopt FAILED, HOWEVER, THE PROGRAM WILL NOT STOP" 
              << std::endl;
  }
  struct sockaddr_in my_addr = {0}; // set all elements of the struct to 0
  my_addr.sin_family = AF_INET; // address family is AF_INET (IPV4)

  // convert listener_port to network number format
  my_addr.sin_port = htons(port_number); 
  // accept connection from all interfaces of the Network Interface Card (NIC)
  my_addr.sin_addr.s_addr = htonl(INADDR_ANY); 
  // bind the socket to the port
  if (bind(l_sock_fd,(struct sockaddr*)&my_addr, sizeof(my_addr)) < 0) { 
    std::cout << "ERROR: BIND SOCKET" << std::endl;
    close(l_sock_fd);
    return false;
  }

  // Accept at max 1 client at a time.
  if (listen(l_sock_fd, 1) < 0) { 
    std::cout << "ERROR: LISTEN SOCKET" << std::endl;
    close(l_sock_fd);
    return false;
  //ERR
  }
  return true;
}

bool TcpEchoServer::acceptConn() 
{
  struct sockaddr_in client_addr;
  socklen_t addr_l = sizeof(client_addr);
  sock_fd = accept(l_sock_fd, (struct sockaddr*) &client_addr, &addr_l);
  if(sock_fd < 0) {
    std::cout << "ERROR: ACCEPT CONNECTION" << std::endl;
    return false;
  }
  // The next line prints the client address, converting to char* 
  // the network address (inet_ntoa)
  std::cout << "New connection from " << inet_ntoa(client_addr.sin_addr) << std::endl; 
  ip_address = inet_ntoa(client_addr.sin_addr);
  connections_count++;
  return true;
}


int TcpEchoServer::receive(MyBuffer& buf)  
{
  // TODO 5: implement this method, which has to perform the following operations.
  // 1- It receives data from the TCP data socket in the buffer embedded in buf 
  //    SUGGESTION: check the code and the comments in my-buffer.h
  // 2- It checks if the receive operation was successful, if not, closes the socket and 
  //    returns a negative number.
  // 3- It sets the buf variable reppresenting the "number of bytes stored"  with 
  //    the received size.
  // 4- It returns the received size.
   int rx_size = read(sock_fd,buf.dataAccess(),buf.getMaxSize());
   if(rx_size < 0){
	std::cout << "ERROR: RECEIVED" << std::endl;
	close(sock_fd);
	return -1;
   }
   return rx_size;
}


int TcpEchoServer::transmit(MyBuffer& buf) 
{
    // TODO 4: implement this method, which has to perform the following operations.
  // 1- It transmits data in the buffer embedded in buf to the TCP data socket 
  //    SUGGESTION: check the code and the comments in my-buffer.h
  // 2- It checks if the transmit operation was successful, if not, closes the socket and 
  //    returns a negative number.
  // 3- It sets a local variable tx_size to the size transmitted with the TCP socket
  // 4- It returns the transmitted size.
   int tx_size = send(sock_fd, buf.dataAccess(), buf.getMaxSize(), 0);
   if(tx_size < 0){
	std::cout << "ERROR: TRANSMITTED" << std::endl;
	close(sock_fd);
	return -1;
   } 
   return tx_size;
}

void TcpEchoServer::printObject(std::ostream& out) const
{
  // TODO 1: implement this method, which will print
  // relevant information on this class (i.e., all its
  // private data members and the protected members of 
  // its the base class).
  out <<"listener socket file descriptor"<< l_sock_fd <<"data socket file des: " << sock_fd << " Num Connections: " << connections_count << std::endl;
}
