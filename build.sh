#!/bin/bash
find . -name "*.cpp" -o -name "*.hpp" | grep -v build | xargs clang-format -i -style=WebKit
cmake -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
cmake --build build --parallel
cppcheck --project=build/compile_commands.json
