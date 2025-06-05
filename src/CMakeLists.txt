add_library(future INTERFACE)

target_sources(future PUBLIC
  FILE_SET HEADERS
  FILES future.hpp
)

add_library(future_compiler_flags INTERFACE)
target_compile_options(future_compiler_flags
  INTERFACE
  -fcoroutines)


target_link_libraries(future INTERFACE future_compiler_flags)

