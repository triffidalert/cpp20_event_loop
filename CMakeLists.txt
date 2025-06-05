cmake_minimum_required(VERSION 3.10)
project(event-loop VERSION 1.0)



add_library(tutorial_compiler_flags INTERFACE)
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_20)

# add compiler warning flags just when building this project via
# the BUILD_INTERFACE genex
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(tutorial_compiler_flags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused;>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)


add_subdirectory(src)
add_subdirectory(tests)

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  #URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
  URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
  DOWNLOAD_EXTRACT_TIMESTAMP true
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
#  add_executable(example example.cpp)
#  target_link_libraries(example gtest_main)
#  add_test(NAME example_test COMMAND example)


enable_testing()
