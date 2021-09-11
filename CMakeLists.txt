project(stdc++)
cmake_minimum_required(VERSION 3.1.9)

include(CheckCXXCompilerFlag)

if(NOT DEFINED HAS_STDLIB_LIBSTDCXX)
    check_cxx_compiler_flag("-stdlib=libstdc++" HAS_STDLIB_LIBSTDCXX)
endif()

if(HAS_STDLIB_LIBSTDCXX)
    add_compile_options("-stdlib=libstdc++")
endif()

option(LIBSTDCXX_REIMPL_VALGRIND_TESTS "Run additional tests under valgrind" OFF)

if(LIBSTDCXX_REIMPL_VALGRIND_TESTS)
    message(CHECK_START "Searching for valgrind")
    find_program(VALGRIND valgrind)

    if(VALGRIND STREQUAL "VALGRIND-NOTFOUND")
        message(CHECK_FAIL "not found")
        set(LIBSTDCXX_REIMPL_VALGRIND_TESTS OFF)
        message(WARNING "Valgrind tests were requested, but valgrind was not found")
    else()
        message(CHECK_PASS "${VALGRIND}")
    endif()
endif()





set(LIBSTDCXX_REIMPL_SANITIZE "" CACHE STRING "Enables Sanitizers on builds")

if(LIBSTDCXX_REIMPL_SANITIZE)
    if(NOT _LIBSTDCXX_REIMPL_TESTED_SANITIZERS STREQUAL LIBSTDCXX_REIMPL_SANITIZE)
        try_compile(
            _LCNIX_TEST_SANITIZERS_RESULT
            ${CMAKE_CURRENT_BINARY_DIR}/sanitizers-test
            ${CMAKE_CURRENT_SOURCE_DIR}/try_compile.c
            COMPILE_DEFINITIONS "-fsanitize=${LIBSTDCXX_REIMPL_SANITIZE}"
            LINK_OPTIONS "-fsanitize=${LIBSTDCXX_REIMPL_SANITIZE}"
        )
        if(NOT _LCNIX_TEST_SANITIZERS_RESULT)
            message(FATAL_ERROR "Requested sanitizer ${LIBSTDCXX_REIMPL_SANITIZE} did not compile")
        endif()
        set(_LIBSTDCXX_REIMPL_TESTED_SANITIZERS ${LIBSTDCXX_REIMPL_SANITIZE} CACHE INTERNAL "")
    endif()
    if(LIBSTDCXX_REIMPL_VALGRIND_TESTS)
        message(WARNING "Valgrind tests may not operate correctly when built with sanitizers")
    endif()
    message(STATUS "Building with the sanitizer ${LIBSTDCXX_REIMPL_SANITIZE}")
    add_compile_options("$<$<NOT:$<CONFIG:Release>>:-fsanitize=${LIBSTDCXX_REIMPL_SANITIZE}>")
    add_link_options("$<$<NOT:$<CONFIG:Release>>:-fsanitize=${LIBSTDCXX_REIMPL_SANITIZE}>")
endif()


enable_testing()
add_subdirectory(test)

set(CMAKE_VERBOSE_MAKEFILE TRUE)
set(CMAKE_CXX_STANDARD 20)
add_link_options(-nodefaultlibs)
add_library(stdc++ SHARED src/atomic.cpp src/chrono.cpp src/cxxabi.cpp src/exception.cpp src/fstream.cpp src/future.cpp src/istream.cpp src/ios.cpp src/ios_base.cpp src/iostream.cpp src/list.cpp src/locale.cpp src/memory.cpp src/mutex.cpp src/new.cpp src/ostream.cpp src/random.cpp src/sstream.cpp src/stdexcept.cpp src/stl_tree.cpp src/streambuf.cpp src/string.cpp src/system_error.cpp src/thread.cpp)
target_link_libraries(stdc++ PRIVATE c)
set_target_properties(stdc++ PROPERTIES SOVERSION 6)

target_link_options(stdc++ PRIVATE "-Wl,--version-script" "${CMAKE_CURRENT_SOURCE_DIR}/src/symver.ld")
set_target_properties(stdc++ PROPERTIES LINK_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/symver.ld")


