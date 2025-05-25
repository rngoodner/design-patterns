cmake_minimum_required(VERSION 3.10)
project(design-patterns CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Compiler warnings
add_compile_options(-Wall -Wextra -Wpedantic -Werror)

# Add strategy program
add_executable(strategy strategy/main.cpp strategy/strategy.cpp)

# Add observer program
add_executable(observer observer/main.cpp observer/observer.cpp)
