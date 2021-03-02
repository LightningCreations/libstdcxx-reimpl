project(stdc++)
cmake_minimum_required(VERSION 3.1.9)

include(CheckCXXCompilerFlag)

if(NOT DEFINED HAS_STDLIB_LIBSTDCXX)
    check_cxx_compiler_flag("-stdlib=libstdc++" HAS_STDLIB_LIBSTDCXX)
endif()

if(HAS_STDLIB_LIBSTDCXX)
    add_compile_options("-stdlib=libstdc++")
endif()

enable_testing()
add_subdirectory(test)



set(CMAKE_VERBOSE_MAKEFILE TRUE)
add_link_options(-nodefaultlibs)
add_library(stdc++ SHARED src/cxxabi.cpp src/exception.cpp src/future.cpp src/istream.cpp src/ios.cpp src/ios_base.cpp src/iostream.cpp src/list.cpp src/locale.cpp src/memory.cpp src/mutex.cpp src/new.cpp src/ostream.cpp src/random.cpp src/sstream.cpp src/stdexcept.cpp src/stl_tree.cpp src/streambuf.cpp src/string.cpp src/system_error.cpp src/thread.cpp)
target_link_libraries(stdc++ PRIVATE c)
set_target_properties(stdc++ PROPERTIES SOVERSION 6)

target_link_options(stdc++ PRIVATE "-Wl,--version-script" "${CMAKE_CURRENT_SOURCE_DIR}/src/symver.ld")
set_target_properties(stdc++ PROPERTIES LINK_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/symver.ld")


