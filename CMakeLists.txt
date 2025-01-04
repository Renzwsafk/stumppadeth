cmake_minimum_required(VERSION 3.16)

project(stumppadeth LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(stumppadeth main.cpp
    renderer.h
    renderer.cpp
)

include(GNUInstallDirs)
install(TARGETS stumppadeth
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
