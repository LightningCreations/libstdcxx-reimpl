project(stdc++)
set(CMAKE_VERBOSE_MAKEFILE TRUE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -nodefaultlibs")
add_library(stdc++ SHARED src/cxxabi.cpp src/exception.cpp src/istream.cpp src/ios.cpp src/ios_base.cpp src/iostream.cpp src/locale.cpp src/mutex.cpp src/new.cpp src/ostream.cpp src/streambuf.cpp src/system_error.cpp src/thread.cpp)
target_link_libraries(stdc++ PUBLIC c)
set_target_properties(stdc++ PROPERTIES SOVERSION 6)

target_link_options(stdc++ PRIVATE "-Wl,--version-script" "${CMAKE_CURRENT_SOURCE_DIR}/src/symver.ld")
set_target_properties(stdc++ PROPERTIES LINK_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/symver.ld")
