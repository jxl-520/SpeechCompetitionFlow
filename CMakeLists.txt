cmake_minimum_required(VERSION 3.23)
project(SpeechCompetitionFlow)

set(CMAKE_CXX_STANDARD 14)

add_executable(SpeechCompetitionFlow main.cpp speechManager.cpp speaker.cpp)
add_executable(test test.cpp)