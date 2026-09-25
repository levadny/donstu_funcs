cmake_minimum_required(VERSION 3.16)

project(math_funcs LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(math_funcs main.cpp
    functemplate.h
    funcline.h
funcfastosc.h
funcdamped.h)

include(GNUInstallDirs)
install(TARGETS math_funcs
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
