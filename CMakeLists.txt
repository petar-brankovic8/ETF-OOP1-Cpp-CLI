cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project (ETF-OOP1-Cpp-CLI LANGUAGES CXX)

add_library (myProject STATIC 
		"src/core/controller.cpp"
		"src/utils/reader.cpp"
		"src/utils/translator.cpp"
		"src/utils/writer.cpp"
		"src/core/commandline.cpp"
		"src/commands/command.cpp"
		"src/commands/iscommand.cpp"
		"src/commands/oscommand.cpp")

target_include_directories(myProject PUBLIC src/)

add_executable(ETF-OOP1-Cpp-CLI "src/main.cpp")
target_link_libraries(ETF-OOP1-Cpp-CLI PRIVATE myProject)