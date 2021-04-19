add_executable(sidecast sidecast.cpp sidecast-noopt.cpp)
set_target_properties(sidecast PROPERTIES BUILD_RPATH "$<TARGET_FILE_DIR:stdc++>")

add_test(sidecast sidecast)
