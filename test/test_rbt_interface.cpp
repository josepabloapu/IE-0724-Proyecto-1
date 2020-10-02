#include "rbt.h"
#include "rbt_node.h"
#include "gtest/gtest.h"

TEST(RedBlackTree_Interface, Positive_rbt_max_get)
{
    std::vector<float> vector{5, 6, 1, 9, 3, 4, 6, 8, 7};
    std::shared_ptr<rbt> tree(new rbt());
    tree->rbt_create(vector);

    rbt_node *my_max_node = new rbt_node();
    int status = tree->rbt_max_get(my_max_node);
    EXPECT_EQ(status, rbt_error_codes::RBT_SUCCESS);
    EXPECT_EQ(my_max_node->value, 9);
}

TEST(RedBlackTree_Interface, Negative_rbt_max_get)
{
    std::shared_ptr<rbt> tree(new rbt());
    rbt_node *my_max_node = new rbt_node();
    int status = tree->rbt_max_get(my_max_node);
    EXPECT_NE(status, rbt_error_codes::RBT_SUCCESS);
    EXPECT_EQ(status, rbt_error_codes::RBT_EMPTY);
}

TEST(RedBlackTree_Interface, Positive_rbt_min_get)
{
    std::vector<float> vector{5, 6, 1, 9, 3, 4, 6, 8, 7};
    std::shared_ptr<rbt> tree(new rbt());
    tree->rbt_create(vector);

    rbt_node *my_min_node = new rbt_node();
    int status = tree->rbt_min_get(my_min_node);
    EXPECT_EQ(status, rbt_error_codes::RBT_SUCCESS);
    EXPECT_EQ(my_min_node->value, 1);
}

TEST(RedBlackTree_Interface, Negative_rbt_min_get)
{
    std::shared_ptr<rbt> tree(new rbt());
    rbt_node *my_min_node = new rbt_node();
    int status = tree->rbt_min_get(my_min_node);
    EXPECT_NE(status, rbt_error_codes::RBT_SUCCESS);
    EXPECT_EQ(status, rbt_error_codes::RBT_EMPTY);
}
