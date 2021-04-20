add_executable(hello hello.cpp)
set_target_properties(hello PROPERTIES BUILD_RPATH "$<TARGET_FILE_DIR:stdc++>")

add_test(hello hello)

if(LIBSTDCXX_REIMPL_VALGRIND_TESTS)
    add_test(NAME valgrind-hello COMMAND ${VALGRIND} $<TARGET_FILE:hello>)
endif()
