#include <coroutine>

namespace event_loop {
  
  template<class T=void>
  struct Awaitable;

  template<>
  struct Awaitable<>{
    Awaitable(): ready{0} {}
    
    bool await_ready(){ return ready; }
    bool await_suspend(std::coroutine_handle<>& h);
    void await_resume();

    void toggle_ready(){ ready ^= 1; }
    bool is_ready() const { return ready; }

  private:
    int ready;
  };
  
  
}//namespace event_loop


