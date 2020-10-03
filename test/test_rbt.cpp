#include "rbt.h"
#include "rbt_node.h"
#include "gtest/gtest.h"

int status = 0;

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
    delete my_max_node;
}

TEST(RedBlackTree, Negative_Interface_rbt_max_get)
{   
    std::shared_ptr<rbt> tree(new rbt());
    rbt_node *my_max_node = new rbt_node();
    status = tree->rbt_max_get(my_max_node);

    EXPECT_EQ(status, rbt_error_codes::RBT_EMPTY);
    delete my_max_node; 
}

TEST(RedBlackTree, Positive_Interface_rbt_min_get)
{
    std::vector<float> vector{5, 6, 1, 9, 3, 4, 6, 8, 7};
    std::shared_ptr<rbt> tree(new rbt());
    tree->rbt_create(vector);

    rbt_node *my_min_node = new rbt_node();
    tree->rbt_min_get(my_min_node);

    EXPECT_EQ(my_min_node->value, 1);
    delete my_min_node;
}

TEST(RedBlackTree, Negative_Interface_rbt_min_get)
{   
    std::shared_ptr<rbt> tree(new rbt());
    rbt_node *my_min_node = new rbt_node();
    status = tree->rbt_max_get(my_min_node);

    EXPECT_EQ(status, rbt_error_codes::RBT_EMPTY);
    delete my_min_node; 
}


TEST(RedBlackTree, Positive_rbt_search)
{
    std:std::vector<float> vector{7, 3, 5, 1, 2, 8, 9};
    std::shared_ptr<rbt> tree(new rbt());
    tree->rbt_create(vector);

    rbt_node *looked_node = new rbt_node();
    float looked_value = 2;
    status = tree->rbt_search(looked_value, looked_node);


    EXPECT_EQ(status, rbt_error_codes::RBT_SUCCESS);
    delete looked_node;

}


TEST(RedBlackTree, Negative_rbt_search)
{
    int status = 0;
    std:std::vector<float> vector{7, 3, 5, 1, 2, 8, 9};
    std::shared_ptr<rbt> tree(new rbt());
    tree->rbt_create(vector);

    rbt_node *looked_node = new rbt_node();
    float looked_value = 12;
    status = tree->rbt_search(looked_value, looked_node);

   
    EXPECT_EQ(status, rbt_error_codes::RBT_NOT_FOUND);

    delete looked_node;
}


TEST(RedBlackTree, Positive_rbt_node_add)
{

  std::shared_ptr<rbt> tree(new rbt());
  std::shared_ptr<rbt_node> node(new rbt_node(4, rbt_color_codes::RBT_COLOR_RED));
  status = tree->rbt_node_add(node);

  EXPECT_EQ(status, rbt_error_codes::RBT_SUCCESS);
}

/*
TEST(RedBlackTree, Negative_rbt_node_add)
{
 
  std::shared_ptr<rbt> tree(new rbt());
  std::shared_ptr<rbt_node> node(new rbt_node(6, rbt_color_codes::RBT_COLOR_RED));
  status = tree->rbt_node_add(node);

  EXPECT_EQ(status, rbt_error_codes::RBT_INVALID_PARAM);
}
*/


