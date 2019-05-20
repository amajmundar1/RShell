CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(rshell
    src/main.cpp
    src/Parser.cpp
    src/Add.cpp
    src/Or.cpp
    src/Semi.cpp
    src/Command.cpp
)

ADD_EXECUTABLE(test
    unit_tests/test.cpp
    src/Parser.cpp
    src/Add.cpp
    src/Or.cpp
    src/Semi.cpp
    src/Command.cpp
)
