cmake_minimum_required(VERSION 3.16)

project(math_funcs LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ==========================================
# Основная программа
# ==========================================

add_executable(math_funcs
    main.cpp
    functemplate.h
    funcline.h
    funcHyperbola.h
)

# ==========================================
# Google Test
# ==========================================

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# ==========================================
# Тесты
# ==========================================

enable_testing()

add_executable(funcTest
    funcTest.cpp
)

target_link_libraries(funcTest
    PRIVATE
        GTest::gtest_main
)

target_include_directories(funcTest
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

include(GoogleTest)

gtest_discover_tests(funcTest)