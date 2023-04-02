cmake_minimum_required(VERSION 3.21)
project(project)

set(CMAKE_CXX_STANDARD 11)

add_executable(project main.cpp array.h tests.cpp tests.h User.cpp User.h Network.cpp Network.h Node.h Dictionary.h UI.cpp UI.h Message.cpp Message.h Friendship.cpp Friendship.h RepoInMemory.cpp RepoInMemory.h)
