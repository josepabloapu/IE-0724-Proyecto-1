#include "rbt.h"
#include "rbt_node.h"
#include "gtest/gtest.h"

TEST(RedBlackTree, Positive_Constructor)
{
    std::shared_ptr<rbt> tree(new rbt());
    EXPECT_EQ(tree->root, nullptr);
}

TEST(RedBlackTree, Positive_RotateLeft)
{
    std::vector<float> vector{1, 2, 3, 4, 5, 6};
    std::shared_ptr<rbt> tree(new rbt());
    tree->rbt_create(vector);
    EXPECT_EQ(tree->root->value, 4);
    EXPECT_EQ(tree->root->color, rbt_color_codes::RBT_COLOR_BLACK);
    EXPECT_EQ(tree->root->lc_node->value, 2);
    EXPECT_EQ(tree->root->lc_node->color, rbt_color_codes::RBT_COLOR_RED);
    EXPECT_EQ(tree->root->rc_node->value, 6);
    EXPECT_EQ(tree->root->rc_node->color, rbt_color_codes::RBT_COLOR_BLACK);
    EXPECT_EQ(tree->root->lc_node->lc_node->value, 1);
    EXPECT_EQ(tree->root->lc_node->lc_node->color, rbt_color_codes::RBT_COLOR_BLACK);
    EXPECT_EQ(tree->root->lc_node->rc_node->value, 3);
    EXPECT_EQ(tree->root->lc_node->rc_node->color, rbt_color_codes::RBT_COLOR_BLACK);
    EXPECT_EQ(tree->root->rc_node->lc_node->value, 5);
    EXPECT_EQ(tree->root->rc_node->lc_node->color, rbt_color_codes::RBT_COLOR_RED);
}

TEST(RedBlackTree, Positive_RotateRight)
{
    std::vector<float> vector{6, 5, 4, 3, 2, 1};
    std::shared_ptr<rbt> tree(new rbt());
    tree->rbt_create(vector);
    EXPECT_EQ(tree->root->value, 5);
    EXPECT_EQ(tree->root->color, rbt_color_codes::RBT_COLOR_BLACK);
    EXPECT_EQ(tree->root->lc_node->value, 3);
    EXPECT_EQ(tree->root->lc_node->color, rbt_color_codes::RBT_COLOR_RED);
    EXPECT_EQ(tree->root->rc_node->value, 6);
    EXPECT_EQ(tree->root->rc_node->color, rbt_color_codes::RBT_COLOR_BLACK);
    EXPECT_EQ(tree->root->lc_node->lc_node->value, 2);
    EXPECT_EQ(tree->root->lc_node->lc_node->color, rbt_color_codes::RBT_COLOR_BLACK);
    EXPECT_EQ(tree->root->lc_node->rc_node->value, 4);
    EXPECT_EQ(tree->root->lc_node->rc_node->color, rbt_color_codes::RBT_COLOR_BLACK);
    EXPECT_EQ(tree->root->lc_node->lc_node->lc_node->value, 1);
    EXPECT_EQ(tree->root->lc_node->lc_node->lc_node->color, rbt_color_codes::RBT_COLOR_RED);
}

TEST(RedBlackTree, Positive_FlipColors_1)
{
    std::vector<float> vector{5, 2, 8};
    std::shared_ptr<rbt> tree(new rbt());
    tree->rbt_create(vector);
    EXPECT_EQ(tree->root->value, 5);
    EXPECT_EQ(tree->root->color, rbt_color_codes::RBT_COLOR_BLACK);
    EXPECT_EQ(tree->root->lc_node->value, 2);
    EXPECT_EQ(tree->root->rc_node->color, rbt_color_codes::RBT_COLOR_BLACK);
    EXPECT_EQ(tree->root->rc_node->value, 8);
    EXPECT_EQ(tree->root->rc_node->color, rbt_color_codes::RBT_COLOR_BLACK);
}

TEST(RedBlackTree, Positive_FlipColors_2)
{
    std::vector<float> vector{5, 2, 8, 1, 3};
    std::shared_ptr<rbt> tree(new rbt());
    tree->rbt_create(vector);
    EXPECT_EQ(tree->root->value, 5);
    EXPECT_EQ(tree->root->color, rbt_color_codes::RBT_COLOR_BLACK);
    EXPECT_EQ(tree->root->lc_node->value, 2);
    EXPECT_EQ(tree->root->lc_node->color, rbt_color_codes::RBT_COLOR_RED);
    EXPECT_EQ(tree->root->rc_node->value, 8);
    EXPECT_EQ(tree->root->rc_node->color, rbt_color_codes::RBT_COLOR_BLACK);
    EXPECT_EQ(tree->root->lc_node->lc_node->value, 1);
    EXPECT_EQ(tree->root->lc_node->lc_node->color, rbt_color_codes::RBT_COLOR_BLACK);
    EXPECT_EQ(tree->root->lc_node->rc_node->value, 3);
    EXPECT_EQ(tree->root->lc_node->rc_node->color, rbt_color_codes::RBT_COLOR_BLACK);
}

TEST(RedBlackTree, Positive_Interface_rbt_max_get)
{
    std::vector<float> vector{5, 6, 1, 9, 3, 4, 6, 8, 7};
    std::shared_ptr<rbt> tree(new rbt());
    tree->rbt_create(vector);

    rbt_node *my_max_node = new rbt_node();
    tree->rbt_max_get(my_max_node);
    EXPECT_EQ(my_max_node->value, 9);
}

TEST(RedBlackTree, Positive_Interface_rbt_min_get)
{
    std::vector<float> vector{5, 6, 1, 9, 3, 4, 6, 8, 7};
    std::shared_ptr<rbt> tree(new rbt());
    tree->rbt_create(vector);

    rbt_node *my_min_node = new rbt_node();
    tree->rbt_min_get(my_min_node);
    EXPECT_EQ(my_min_node->value, 1);
}
