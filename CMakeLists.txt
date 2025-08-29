cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project (ETF-OOP1-Cpp-CLI LANGUAGES CXX)

add_library (myProject STATIC 
		"src/core/controller.cpp"
		"src/utils/translator.cpp"
		"src/core/commandline.cpp"
		"src/commands/command.cpp"
		"src/commands/iscommand.cpp"
		"src/commands/oscommand.cpp" 
		"src/commands/echo.cpp" 
		"src/commands/prompt.cpp" 
		"src/commands/time.cpp" 
		"src/commands/date.cpp" 
		"src/commands/touch.cpp" 
		"src/commands/truncate.cpp" 
		"src/commands/rm.cpp" 
		"src/commands/wc.cpp" 
		"src/commands/tr.cpp" 
		"src/commands/head.cpp" 
		"src/commands/batch.cpp")

target_include_directories(myProject PUBLIC src/)

add_executable(ETF-OOP1-Cpp-CLI "src/main.cpp")
target_link_libraries(ETF-OOP1-Cpp-CLI PRIVATE myProject)