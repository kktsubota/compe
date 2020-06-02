cmake_minimum_required(VERSION 3.1)
project(compe CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall")

find_package(GTest REQUIRED)
add_executable(sample lib/cpp/sample.cpp test/cpp/test_sample.cpp)
target_link_libraries(sample
  PRIVATE
    GTest::GTest
    GTest::Main # run test automatically
)
