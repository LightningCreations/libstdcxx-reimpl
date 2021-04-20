add_executable(throw throw.cpp)
set_target_properties(throw PROPERTIES BUILD_RPATH "$<TARGET_FILE_DIR:stdc++>")

add_test(throw throw)

if(LIBSTDCXX_REIMPL_VALGRIND_TESTS)
    add_test(NAME valgrind-throw COMMAND ${VALGRIND} $<TARGET_FILE:throw>)
endif()
