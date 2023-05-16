/* 
 * [2019] Signet Lab - Programming for ICT
 * All Rights Reserved.
 * 
 * Authors Filippo Campagnaro and Michele Polese 
 */

#include <tcp-echo-server.h>
#include <basic-utilities.h>
#include <queue>
#include <thread>
#include <atomic>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <string.h>
#include <iostream>
#include <cctype>

std::queue<MyBuffer> q; /**< queue to store data chunks to transmit**/
std::mutex q_mutex; /**<mutex to access the queue in thread safe way**/
std::atomic<bool> finish_flag{false}; /**<Exit flag to terminate the thread**/
std::atomic<TestResult> transmission_result{TestResult::FAILED}; /**<Last transmission result**/
std::condition_variable q_cv; /**<condition variable to wait for data**/

/**
 * Method used to accept a new connection from an opened echo_server
 * @param echo_server pointer to an Ethernet, that points to a Tcpecho_server
 * @return false if the object is not a Tcpecho_server or if the accept fails
 */
bool acceptTcpConn(std::shared_ptr<Ethernet> echo_server) 
{
  auto casted_echo_server = std::dynamic_pointer_cast<TcpEchoServer>(echo_server);
  if(casted_echo_server != nullptr && casted_echo_server->acceptConn()) {
    std::cout << "echo_server accepted client " << casted_echo_server->getIpAddr() << std::endl;
    return true;
  }
  return false;
}

/**
 * Method used continuosly transmit data stored in the queue to the socket.
 * If no data is available within a certain time, it prints 
 * to the socket to provide some data.
 * @param pointer to an Ethernet pointing to the echo_server
 * @param timeout timeout in milliseconds
 */
void consumer(std::shared_ptr<Ethernet> echo_server, 
  std::chrono::milliseconds timeout) 
{
  while(!finish_flag) {
    std::unique_lock<std::mutex> lck(q_mutex);
    q_cv.wait_for(lck, timeout, [&](){
      return finish_flag || !q.empty();
    });
    if(!q.empty()) {
      MyBuffer buffer = q.front();
      q.pop();
      lck.unlock();
      if(echo_server->transmit(buffer) < 0) {
        transmission_result = TestResult::FAILED;
      } else {
        transmission_result = TestResult::PASSED;
      }
    } else if(!finish_flag) {
      lck.unlock();
      MyBuffer buffer(150);
      std::string message = "Waiting data from user\n";
      std::cout << message ;
      memcpy(buffer.dataAccess(), message.c_str(), message.size());
      buffer.n_bytes = message.size();
      if(echo_server->transmit(buffer) < 0) {
        transmission_result = TestResult::FAILED;
      } else {
        transmission_result = TestResult::PASSED;
      }
    }
  }
}

int main(int argc, char** argv) 
{

  const int listen_port = 55555;
  std::shared_ptr<Ethernet> echo_server = std::make_shared<TcpEchoServer>(listen_port);
  
  if(!acceptTcpConn(echo_server)) {
    return (int)TestResult::FAILED;
  }
std::queue<MyBuffer> q;
  // TODO 3a: dispatch a thread running the consumer method, using a variable 
  // called consumer_thr and passing server and 45 milliseconds as function
  // parameters.
  std::thread consumer_thr(consumer,echo_server,std::chrono::milliseconds(4500));
  consumer_thr.detach();
  //producer
  for(int i = 0; i < 15; i++) {
    MyBuffer buffer(MTU);

    int rx_size = echo_server->receive(buffer);
    if(rx_size>0) {
      std::cout << "received = " << buffer.dataAccess() 
                << ", buffer.n_bytes = " << buffer.n_bytes << std::endl;
    } else {
      return (int)TestResult::FAILED;
    }

    // TODO 6: push buffer into the queue q in thread-safe way, and
    // notify it to one of the threads waiting for data.
    std::unique_lock< std::mutex> lk2(q_mutex);
    q.push(buffer.buf);
    lk2.unlock();
    cv.notify_one();
  }  

  std::cout << *echo_server << std::endl;
  finish_flag = true;
  q_cv.notify_one();
  // TODO 3b: join the thread, if possible.
  if(consumer_thr.joinable()){
	  consumer_thr.join();
  }
  return (int)transmission_result.load();

}
