#include <vector>
#include <random>
#include <chrono>

#include "test_rbt.cpp"
#include "test_rbt_node.cpp"
#include "gtest/gtest.h"

using namespace std;

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
