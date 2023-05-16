/*
 * [2019] Signet Lab - Programming for ICT
 * All Rights Reserved.
 * 
 * Authors Filippo Campagnaro and Michele Polese 
*/

#ifndef H_CONC_QUEUE
#define H_CONC_QUEUE

#include <queue>
#include <chrono>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <atomic>

/**
 * This template class represents a thread safe queue 
 */
template<typename T>
class ConcQueue {
private:
  std::queue<T> queue; /**< queue to be accessed in thread safe way */
  std::mutex mutex_q; /**< mutex for the queue */
  /** condition variable to wait for data in the queue */
  std::condition_variable cv_q; 
  std::atomic<bool> exit_flag; /**< set to true to force quit*/

public:
  // type value for the template
  // this makes the type T accessible also from the outside,
  // using the alias value_type
  using value_type = T;
  
  /**
   * Default constructor
   */
  ConcQueue() :
    queue{}, 
    mutex_q{},
    cv_q{},
    exit_flag{false}
  {

  };

  /**
   * Destructor
   */
  ~ConcQueue()
  {
    exit_flag.store(true);
    cv_q.notify_all();
  };

  /**
   * Push data to queue
   * @param element to push 
   */
  void push(T element) 
  {
    std::unique_lock<std::mutex> lck{mutex_q};
    queue.push(element);
    lck.unlock();
    exit_flag.store(false);
    cv_q.notify_one();
  }

  /**
   * Pop data from queue, if available, and get the front
   * @param element output parameter where to store the front of the queue, 
   *        if available
   * @return false if the queue is empty
   */
  bool pop(T& element) 
  {
    std::unique_lock<std::mutex> lck{mutex_q};
    if(queue.empty()) {
      return false;
    }
    element = queue.front();
    queue.pop();
    return true;
  }

  /**
   * Get the front element from queue, if available
   * @param element output parameter where to store the front of the queue, 
   *        if available
   * @return false if the queue is empty
   */
  bool front(T& element) 
  {
    std::unique_lock<std::mutex> lck{mutex_q};
    if(queue.empty()) {
      return false;
    }
    element = queue.front();
    return true;
  }

  /**
   * Wait and pop data from queue, when available, and get the front
   * @param element output parameter where to store the front of the queue, 
   *        if available
   * @return false if the operation is interrupted with forceExit() method
   */
  bool wPop(T& element) 
  {
    std::unique_lock<std::mutex> lck{mutex_q};
    cv_q.wait(lck,[&](){
      return !queue.empty() || exit_flag;
    });
    if(queue.empty()) {
      return false;
    }
    element = queue.front();
    queue.pop();
    return true;
  }

  /**
   * Wait and front data from queue, when available
   * @param element output parameter where to store the front of the queue, 
   *        if available
   * @return false if the queue is empty after the forceExit() method is called
   */
  bool wFront(T& element) 
  {
    std::unique_lock<std::mutex> lck{mutex_q};
    cv_q.wait(lck,[&](){
      return !queue.empty() || exit_flag;
    });
    if(queue.empty()) {
      return false;
    }
    element = queue.front();
    return true;
  }

  /**
   * Wait up to a max timeout to pop data from queue, if available, 
   * and to get the front
   * @param element output parameter where to store the front of the queue, 
   *        if available
   * @param t_o maximum timeout to wait, in milliseconds
   * @return false if the queue is empty after timeout or forceExit()
   */
  bool wTPop(T& element, std::chrono::milliseconds t_o) 
  {
    std::unique_lock<std::mutex> lck{mutex_q};
    cv_q.wait_for(lck,t_o,[&](){
      return !queue.empty() || exit_flag;
    });
    if(queue.empty()) {
      return false;
    }
    element = queue.front();
    queue.pop();
    return true;
  }


  /**
   * Wait up to a max timeout to front data from queue, if available
   * @param element output parameter where to store the front of the queue, 
   *        if available
   * @param t_o maximum timeout to wait, in milliseconds
   * @return false if the queue is empty after timeout or forceExit()
   */
  bool wTFront(T& element, std::chrono::milliseconds t_o) 
  {
    std::unique_lock<std::mutex> lck{mutex_q};
    cv_q.wait_for(lck,t_o,[&](){
      return !queue.empty() || exit_flag;
    });
    if(queue.empty()) {
      return false;
    }
    element = queue.front();
    return true;
  }


  /**
   * Force all blocked methods to exit
   */
  void forceExit() 
  {
    exit_flag.store(true);
    cv_q.notify_all();
  }

};



#endif // H_CONC_QUEUE