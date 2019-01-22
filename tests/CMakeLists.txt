cmake_minimum_required (VERSION 3.10.0)
project (groupmebot)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra -Wno-missing-field-initializers")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANADARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(BotTest testmain.cpp test_rapidjson.cpp)
target_include_directories(BotTest PRIVATE ../include)

add_executable(TestPistache test_pistache.cpp)
target_link_libraries(TestPistache pistache)
