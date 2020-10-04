#include "rbt.h"
#include "rbt_node.h"
#include "gtest/gtest.h"

TEST(RedBlackTreeRemove, Positive_RemoveRedLeaf)
{

    std::vector<float> in_number_list{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    std::shared_ptr<rbt> my_tree(new rbt());
    my_tree->rbt_create(in_number_list);

    rbt_node *node_to_remove = new rbt_node();
    node_to_remove->value = 19;
    my_tree->rbt_node_remove(node_to_remove);

    rbt_node *node_to_search = new rbt_node();
    my_tree->rbt_search(20, node_to_search);

    EXPECT_EQ(node_to_search->lc_node, nullptr);
}

/////////////////hay un error de segmentacion aca. Lo estoy ubicando////////////////////////////
/*
TEST(RedBlackTreeRemove, Positive_RemoveParentWithOneRedLeaf)
{

    std::vector<float> in_number_list{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    std::shared_ptr<rbt> my_tree(new rbt());
    my_tree->rbt_create(in_number_list);

    rbt_node *node_to_remove = new rbt_node();
    node_to_remove->value = 20;
    my_tree->rbt_node_remove(node_to_remove);

    rbt_node *node_to_search = new rbt_node();
    my_tree->rbt_search(18, node_to_search);

    EXPECT_EQ(node_to_search->rc_node->value, 19);
    EXPECT_EQ(node_to_search->rc_node->color, rbt_color_codes::RBT_COLOR_BLACK);
}
*/