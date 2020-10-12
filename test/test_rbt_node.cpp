#include "rbt_node.h"
#include "rbt.h"
#include "gtest/gtest.h"


TEST(RedBlackTree_Node, Positive_Constructor)
{
    std::shared_ptr<rbt_node> node(new rbt_node(1, rbt_color_codes::RBT_COLOR_BLACK));
    
    EXPECT_EQ(node->lc_node, nullptr);
    EXPECT_EQ(node->rc_node, nullptr);
    EXPECT_EQ(node->value, 1);
    EXPECT_EQ(node->color, rbt_color_codes::RBT_COLOR_BLACK);
}

TEST(RedBlackTree_Node, Positive_AddChildNode)
{
    std::shared_ptr<rbt_node> node1(new rbt_node(5, rbt_color_codes::RBT_COLOR_BLACK));
    std::shared_ptr<rbt_node> node2(new rbt_node(1, rbt_color_codes::RBT_COLOR_RED));
    std::shared_ptr<rbt_node> node3(new rbt_node(10, rbt_color_codes::RBT_COLOR_RED));
    node1->lc_node = node2;
    node1->rc_node = node3;
    EXPECT_EQ(node1->value, 5);
    EXPECT_EQ(node1->lc_node->value, 1);
    EXPECT_EQ(node1->rc_node->value, 10);
}

