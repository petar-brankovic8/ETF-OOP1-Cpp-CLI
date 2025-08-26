cmake_minimum_required(VERSION 3.15)

project (ETF-OOP1-Cpp-CLI LANGUAGES CXX)

add_executable(ETF-OOP1-Cpp-CLI "src/main.cpp" "src/core/controller.cpp" "src/utils/reader.cpp" "src/utils/translator.cpp" "src/utils/writer.cpp" "src/core/commandline.cpp")

target_include_directories(ETF-OOP1-Cpp-CLI PRIVATE src/core src/utils)