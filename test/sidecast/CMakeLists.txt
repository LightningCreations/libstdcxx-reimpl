add_executable(sidecast sidecast.cpp sidecast-noopt.cpp)
set_target_properties(sidecast PROPERTIES BUILD_RPATH "$<TARGET_FILE_DIR:stdc++>")

add_test(sidecast sidecast)

if(LIBSTDCXX_REIMPL_VALGRIND_TESTS)
    add_test(NAME valgrind-sidecast COMMAND ${VALGRIND} $<TARGET_FILE:sidecast>)
endif()