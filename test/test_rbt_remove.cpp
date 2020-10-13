#include "rbt.h"
#include "rbt_node.h"
#include "rbt_debug.h"
#include "gtest/gtest.h"
#include <iostream>

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

TEST(RedBlackTreeRemove, Remove_node_scenario_1)
{
    std::vector<float> in_number_list{0.05, 0.52, 0.12, 0.16, 0.25, 0.36, 0.18,
                                      0.37, 0.27, 0.51, 0.68, 0.4, 0.2, 0.03, 0.48,
                                      0.57, 0.6, 0.19, 0.33, 0.41, 0.06, 0.22, 0.58,
                                      0.13, 0.15, 0.43, 0.28, 0.63, 0.64, 0.59, 0.31,
                                      0.39, 0.14, 0.38, 0.04, 0.55, 0.56, 0.65, 0.1,
                                      0.23, 0.67, 0.24, 0.21, 0.35, 0.02, 0.11, 0.32,
                                      0.01, 0.47, 0.42, 0.66, 0.29, 0.53, 0.44, 0.17,
                                      0.61, 0.5, 0.08, 0.45, 0.26, 0.3, 0.62, 0.07,
                                      0.46, 0.54, 0.49, 0.09, 0.34};
    std::shared_ptr<rbt> my_tree(new rbt());
    my_tree->rbt_create(in_number_list);
    rbt_node *node_to_remove = new rbt_node();
    std::shared_ptr<rbt_debug> my_debug(new rbt_debug());

    bool status;
    std::vector<float> values_to_remove{0.52, 0.68, 0.6, 0.13, 0.65, 0.23, 0.01, 0.61, 0.49};
    for (auto value : values_to_remove)
    {
        node_to_remove->value = value;
        my_tree->rbt_node_remove(node_to_remove);

        status = my_debug->test_red_black_tree(my_tree);
        if (status == false)
        {
            std::cout << "La violacion ocurrió removiendo: " << value << std::endl;
            break;
        }
    }

    EXPECT_TRUE(status);
}

TEST(RedBlackTreeRemove, Remove_node_scenario_2)
{
    std::vector<float> in_number_list{0.05, 0.52, 0.12, 0.16, 0.25, 0.36, 0.18,
                                      0.37, 0.27, 0.51, 0.68, 0.4, 0.2, 0.03, 0.48,
                                      0.57, 0.6, 0.19, 0.33, 0.41, 0.06, 0.22, 0.58,
                                      0.13, 0.15, 0.43, 0.28, 0.63, 0.64, 0.59, 0.31,
                                      0.39, 0.14, 0.38, 0.04, 0.55, 0.56, 0.65, 0.1,
                                      0.23, 0.67, 0.24, 0.21, 0.35, 0.02, 0.11, 0.32,
                                      0.01, 0.47, 0.42, 0.66, 0.29, 0.53, 0.44, 0.17,
                                      0.61, 0.5, 0.08, 0.45, 0.26, 0.3, 0.62, 0.07,
                                      0.46, 0.54, 0.49, 0.09, 0.34};
    std::shared_ptr<rbt> my_tree(new rbt());
    my_tree->rbt_create(in_number_list);
    rbt_node *node_to_remove = new rbt_node();
    std::shared_ptr<rbt_debug> my_debug(new rbt_debug());

    bool status;
    std::vector<float> values_to_remove{0.05, 0.27, 0.19, 0.43, 0.38, 0.24, 0.42, 0.08, 0.22};
    for (auto value : values_to_remove)
    {
        node_to_remove->value = value;
        my_tree->rbt_node_remove(node_to_remove);

        status = my_debug->test_red_black_tree(my_tree);
        if (status == false)
        {
            std::cout << "La violacion ocurrió removiendo: " << value << std::endl;
            break;
        }
    }

    EXPECT_TRUE(status);
}

TEST(RedBlackTreeRemove, Remove_node_scenario_3)
{
    std::vector<float> in_number_list{0.05, 0.52, 0.12, 0.16, 0.25, 0.36, 0.18,
                                      0.37, 0.27, 0.51, 0.68, 0.4, 0.2, 0.03, 0.48,
                                      0.57, 0.6, 0.19, 0.33, 0.41, 0.06, 0.22, 0.58,
                                      0.13, 0.15, 0.43, 0.28, 0.63, 0.64, 0.59, 0.31,
                                      0.39, 0.14, 0.38, 0.04, 0.55, 0.56, 0.65, 0.1,
                                      0.23, 0.67, 0.24, 0.21, 0.35, 0.02, 0.11, 0.32,
                                      0.01, 0.47, 0.42, 0.66, 0.29, 0.53, 0.44, 0.17,
                                      0.61, 0.5, 0.08, 0.45, 0.26, 0.3, 0.62, 0.07,
                                      0.46, 0.54, 0.49, 0.09, 0.34};
    std::shared_ptr<rbt> my_tree(new rbt());
    my_tree->rbt_create(in_number_list);
    rbt_node *node_to_remove = new rbt_node();
    std::shared_ptr<rbt_debug> my_debug(new rbt_debug());

    bool status;
    std::vector<float> values_to_remove{0.18, 0.48, 0.58, 0.31, 0.1, 0.32, 0.17, 0.07, 0.34, 0.24};
    for (auto value : values_to_remove)
    {
        node_to_remove->value = value;
        my_tree->rbt_node_remove(node_to_remove);

        status = my_debug->test_red_black_tree(my_tree);
        if (status == false)
        {
            std::cout << "La violacion ocurrió removiendo: " << value << std::endl;
            break;
        }
    }

    EXPECT_TRUE(status);
}

TEST(RedBlackTreeRemove, Remove_node_scenario_4)
{
    std::vector<float> in_number_list{0.05, 0.52, 0.12, 0.16, 0.25, 0.36, 0.18,
                                      0.37, 0.27, 0.51, 0.68, 0.4, 0.2, 0.03, 0.48,
                                      0.57, 0.6, 0.19, 0.33, 0.41, 0.06, 0.22, 0.58,
                                      0.13, 0.15, 0.43, 0.28, 0.63, 0.64, 0.59, 0.31,
                                      0.39, 0.14, 0.38, 0.04, 0.55, 0.56, 0.65, 0.1,
                                      0.23, 0.67, 0.24, 0.21, 0.35, 0.02, 0.11, 0.32,
                                      0.01, 0.47, 0.42, 0.66, 0.29, 0.53, 0.44, 0.17,
                                      0.61, 0.5, 0.08, 0.45, 0.26, 0.3, 0.62, 0.07,
                                      0.46, 0.54, 0.49, 0.09, 0.34};
    std::shared_ptr<rbt> my_tree(new rbt());
    my_tree->rbt_create(in_number_list);
    rbt_node *node_to_remove = new rbt_node();
    std::shared_ptr<rbt_debug> my_debug(new rbt_debug());

    bool status;
    std::vector<float> values_to_remove{0.25, 0.38, 0.47, 0.61, 0.34, 0.02, 0.31, 0.03, 0.67, 0.23};
    for (auto value : values_to_remove)
    {
        node_to_remove->value = value;
        my_tree->rbt_node_remove(node_to_remove);

        status = my_debug->test_red_black_tree(my_tree);
        if (status == false)
        {
            std::cout << "La violacion ocurrió removiendo: " << value << std::endl;
            break;
        }
    }

    EXPECT_TRUE(status);
}

TEST(RedBlackTreeRemove, Remove_node_scenario_5)
{
    std::vector<float> in_number_list{0.05, 0.52, 0.12, 0.16, 0.25, 0.36, 0.18,
                                      0.37, 0.27, 0.51, 0.68, 0.4, 0.2, 0.03, 0.48,
                                      0.57, 0.6, 0.19, 0.33, 0.41, 0.06, 0.22, 0.58,
                                      0.13, 0.15, 0.43, 0.28, 0.63, 0.64, 0.59, 0.31,
                                      0.39, 0.14, 0.38, 0.04, 0.55, 0.56, 0.65, 0.1,
                                      0.23, 0.67, 0.24, 0.21, 0.35, 0.02, 0.11, 0.32,
                                      0.01, 0.47, 0.42, 0.66, 0.29, 0.53, 0.44, 0.17,
                                      0.61, 0.5, 0.08, 0.45, 0.26, 0.3, 0.62, 0.07,
                                      0.46, 0.54, 0.49, 0.09, 0.34};
    std::shared_ptr<rbt> my_tree(new rbt());
    my_tree->rbt_create(in_number_list);
    rbt_node *node_to_remove = new rbt_node();
    std::shared_ptr<rbt_debug> my_debug(new rbt_debug());

    bool status;
    std::vector<float> values_to_remove{0.54, 0.5, 0.42, 0.35, 0.56, 0.63, 0.33, 0.4, 0.05};
    for (auto value : values_to_remove)
    {
        node_to_remove->value = value;
        my_tree->rbt_node_remove(node_to_remove);

        status = my_debug->test_red_black_tree(my_tree);
        if (status == false)
        {
            std::cout << "La violacion ocurrió removiendo el valor: " << value << std::endl;
            break;
        }
    }

    EXPECT_TRUE(status);
}
