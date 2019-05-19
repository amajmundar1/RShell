CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(Project
	./Source/main.cpp
	./Source/Parser.cpp
	./Source/Add.cpp
	./Source/Or.cpp
	./Source/Semi.cpp
	./Source/Command.cpp
)
