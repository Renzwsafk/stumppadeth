cmake_minimum_required(VERSION 3.16)

project(stumppadeth LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

set(GLFW_VERSION 3.4)

if(MINGW)
FetchContent_Declare(
        glfw3
        URL https://github.com/glfw/glfw/releases/download/${GLFW_VERSION}/glfw-${GLFW_VERSION}.bin.WIN64.zip
        FIND_PACKAGE_ARGS ${GLFW_VERSION}
    )

elseif(MINGW AND WIN32)
    FetchContent_Declare(
        glfw3
        URL https://github.com/glfw/glfw/releases/download/${GLFW_VERSION}/glfw-${GLFW_VERSION}.bin.WIN32.zip
        FIND_PACKAGE_ARGS ${GLFW_VERSION}
    )
endif()

set(BUILD_EXAMPLES OFF CACHE INTERNAL "")
FetchContent_MakeAvailable(glfw3)

add_executable(stumppadeth main.cpp
    vbo.h
    vbo.cpp
    vao.h
    vao.cpp
    default.vert
    default.frag
    shader.h
    shader.cpp
    #renderer.h
    #renderer.cpp
)

target_link_libraries(stumppadeth glfw3)

include(GNUInstallDirs)
install(TARGETS stumppadeth
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
