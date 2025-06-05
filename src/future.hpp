#include <coroutine>
#include <stdexcept>

namespace event_loop {

  struct event_loop_base_error : std::runtime_error{};
  struct future_resumed_when_not_done_error : event_loop_base_error{};
  
  
  template<class T>
  class Future
  {
  public:
    
    bool await_ready(){ return done; }
    bool await_suspend(std::coroutine_handle<>& h){ return true; }
    T await_resume()
    {
      if( !done )
	throw std::runtime_error("");
      else
	return result;
    }
    
    auto operator co_await(){ return *this; }
    Future(): done{false}, result{} {}
    bool is_done() const { return done; }
    void set_done(T res){ result = res; done = true; }

  private:
    bool done;
    T result;
  };
}//namespace event_loop


