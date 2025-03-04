find_package(GTest REQUIRED)

set(TEST_SRCS
    test.cpp
)

add_executable(JsonParser_test
    ${TEST_SRCS}
)

target_link_libraries(JsonParser_test PRIVATE
    GTest::gtest
    JsonParser_static
)
