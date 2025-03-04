#include <gtest/gtest.h>

#include "include/include.h"

TEST(ProjectBasicTest, Test1)
{
    hello();
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
