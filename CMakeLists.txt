CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(rshell
    src/main.cpp
    src/Parser.cpp
    src/Add.cpp
    src/Or.cpp
    src/Semi.cpp
    src/Command.cpp
    src/test.cpp
    src/ConstructTree.cpp
    src/AppendOutput.cpp
    src/RedirectInput.cpp
    src/RedirectOutput.cpp
    src/Pipe.cpp
)

ADD_EXECUTABLE(test
    unit_tests/test.cpp
    src/Parser.cpp
    src/Add.cpp
    src/Or.cpp
    src/Semi.cpp
    src/Command.cpp
    src/test.cpp
    src/ConstructTree.cpp
    src/AppendOutput.cpp
    src/RedirectInput.cpp
    src/RedirectOutput.cpp
    src/Pipe.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
