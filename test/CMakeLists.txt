include(FetchContent)
FetchContent_Declare(googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip)
FetchContent_MakeAvailable(googletest)
add_executable(core_test gnome_test.cpp world_test.cpp)
target_link_libraries(core_test PRIVATE GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(core_test)