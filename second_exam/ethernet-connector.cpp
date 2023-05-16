/* 
 * [2019] Signet Lab - Programming for ICT
 * All Rights Reserved.
 * 
 * Authors Filippo Campagnaro and Michele Polese 
 */

#include <ethernet-connector.h>
#include <iostream>

const std::string Ethernet::LOCAL_HOST = "127.0.0.1";

Ethernet::Ethernet(const std::string& ip_address_addr, int port_number_num)
:
ip_address(ip_address_addr),
port_number(port_number_num)
{

}

Ethernet::Ethernet(int port_num)
:
ip_address(Ethernet::LOCAL_HOST),
port_number(port_num)
{

}

void Ethernet::printObject(std::ostream& out) const
{
  // TODO 1: implement this method, which will print
  // relevant information on this class (i.e., all its
  // protected members).
  out << "Ip addr: " << ip_address << "port_num: " << port_number << std::endl;

}

std::ostream& operator<<(std::ostream& out, const Ethernet& conn) 
{
	// TODO 1: implement this method so that is works correctly when 
  // Ethernet is overloaded.
  conn.printObject(out);
  return out;
}
