#include "gtest/gtest.h"
#include "test_rbt.cpp"
#include "test_rbt_remove.cpp"
#include "test_rbt_node.cpp"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
