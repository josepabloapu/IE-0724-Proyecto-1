#include "rbt.h"
#include "rbt_node.h"
#include "gtest/gtest.h"

TEST(RedBlackTreeSearch, Positive_GetMax)
{
    std::vector<float> vector{5, 6, 1, 9, 3, 4, 6, 8, 7};
    std::shared_ptr<rbt> tree(new rbt());
    tree->rbt_create(vector);

    rbt_node *my_max_node = new rbt_node();
    tree->rbt_max_get(my_max_node);
    EXPECT_EQ(my_max_node->value, 9);
}

TEST(RedBlackTreeSearch, Positive_GetMin)
{
    std::vector<float> vector{5, 6, 1, 9, 3, 4, 6, 8, 7};
    std::shared_ptr<rbt> tree(new rbt());
    tree->rbt_create(vector);

    rbt_node *my_min_node = new rbt_node();
    tree->rbt_min_get(my_min_node);
    EXPECT_EQ(my_min_node->value, 1);
}
