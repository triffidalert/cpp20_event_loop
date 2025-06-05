#include <cassert>
#include <iostream>
#include <coroutine>
#include "gtest/gtest.h"

#include "generator.hpp"
#include "future.hpp"


//event_loop::Future<int> my_future{};

/*
generator f() { co_yield 1; co_await my_future; co_yield 2; }

int main()
{
  auto g = f();
  g.move_next();
  assert( g.current_value() == 1 );
  g.move_next();
  assert( g.current_value() == 1 );
  try
   { g.move_next(); }
  catch(std::runtime_error e)
   {}
}
*/

/*
int main()
{
  std::coroutine_handle<> null_handle{nullptr};
  
  assert( !my_future.is_done() );
  assert( my_future.await_suspend(null_handle) );
  assert( !my_future.await_ready() );
  
  try
    {
      my_future.await_resume();
    }
  catch (std::runtime_error)
    {}
    
	       
  my_future.set_done(22);

  assert( my_future.is_done() );
  assert( my_future.is_done() );
  assert ( my_future.await_resume() == 22 );

  return 0;
}
*/
TEST(future, future_construct){
  event_loop::Future<int> my_future{};
  std::coroutine_handle<> null_handle{nullptr};
  
  ASSERT_FALSE( my_future.is_done() );
  ASSERT_TRUE( my_future.await_suspend(null_handle) );
  ASSERT_FALSE( my_future.await_ready() );
}


