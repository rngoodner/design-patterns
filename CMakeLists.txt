cmake_minimum_required(VERSION 3.10)
project(design-patterns CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(-Wall -Wextra -Wpedantic -Werror)

add_executable(strategy strategy/main.cpp strategy/strategy.cpp)
add_executable(observer observer/main.cpp observer/observer.cpp)
add_executable(decorator decorator/main.cpp decorator/decorator.cpp)
add_executable(factory-method factory-method/main.cpp factory-method/factory-method.cpp)
add_executable(abstract-factory abstract-factory/main.cpp abstract-factory/abstract-factory.cpp)
