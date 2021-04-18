/*
  +-----------------------------------------------+
  |                                               |
  |   @file timer.h                               |
  |                                               |
  |   @brief run a function at given interval or  |
  |       after delay                             |
  |                                               |
  +-----------------------------------------------+
*/

#ifndef __TIMER__
#define __TIMER__

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
// Includes
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
#include <thread>
#include <chrono>

class Timer {
private:
  bool m_clear = false;

public:
  /**
   * Call function after given delay
   * 
   * @param Function - function to run
   * @param int - delay in milliseconds
   */
  template<typename Function> 
  void setTimeout(Function function, int delay)
  {
    this->m_clear = false;
    std::thread t([=]() {
      if(this->m_clear) return;
      std::this_thread::sleep_for(std::chrono::milliseconds(delay));
      if(this->m_clear) return;
      function();
    });
    t.detach();
  }
  
  /**
   * Repeat a function at every given time interval
   * 
   * @param Function - function to repeat
   * @param int - interval in milliseconds
   */
  template<typename Function>
  void setInterval(Function function, int interval)
  {
    this->m_clear = false;
    std::thread t([=]() {
      while(true) {
        if(this->m_clear) return;
        std::this_thread::sleep_for(std::chrono::milliseconds(interval));
        if(this->m_clear) return;
        function();
      }
    });
    t.detach();
  }
  
  /**
   * Stop timer
   */
  void stop() 
  {
    this->m_clear = true;
  }
};

#endif // !__TIMER__