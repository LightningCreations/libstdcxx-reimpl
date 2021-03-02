add_executable(throw throw.cpp)
set_target_properties(throw PROPERTIES BUILD_RPATH "$<TARGET_FILE_DIR:stdc++>")

add_test(throw throw)
