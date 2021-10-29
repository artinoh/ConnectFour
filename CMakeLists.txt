cmake_minimum_required(VERSION 3.20)
project(ConnectFour)

set(CMAKE_CXX_STANDARD 14)

add_executable(ConnectFour main.cpp Board.cpp Board.h ComputerPlayer.cpp ComputerPlayer.h HumanPlayer.cpp HumanPlayer.h Player.cpp Player.h Game.cpp Game.h Square.cpp Square.h)
