#include <iostream>
#include <memory>
#include <vector>

#include "rbt.h"
#include "rbt_node.h"
#include "rbt_debug.h"

rbt_debug::rbt_debug()
{
}

rbt_debug::~rbt_debug()
{
}

void rbt_debug::update_leaves(std::shared_ptr<rbt> tree)
{
    leaves.clear();
    update_leaves_recursive(tree->root);
    std::cout << "Number of leaves: " << leaves.size() << std::endl;
}

void rbt_debug::update_leaves_recursive(std::shared_ptr<rbt_node> node)
{
    if (node == nullptr)
    {
        return;
    }

    if (node->lc_node == nullptr && node->rc_node == nullptr)
    {
        leaves.push_back(node);
        return;
    }

    update_leaves_recursive(node->lc_node);
    update_leaves_recursive(node->rc_node);
}

int rbt_debug::count_black_nodes_to_leaf(std::shared_ptr<rbt_node> node, float value)
{
    int black_counter = 0;
    while (node != nullptr)
    {
        if (node->color == rbt_color_codes::RBT_COLOR_BLACK)
            black_counter++;

        if (value < node->value)
            node = node->lc_node;

        else if (value > node->value)
            node = node->rc_node;

        else
            break;
    }
    return black_counter;
}

bool rbt_debug::test_black_nodes_count(std::shared_ptr<rbt> tree)
{
    update_leaves(tree);
    int black_nodes = -1;
    for (auto &it : leaves)
    {
        int current_black_nodes = count_black_nodes_to_leaf(tree->root, it->value);
        if (black_nodes != -1 && current_black_nodes != black_nodes)
        {
            std::cout << "Error: violation occured" << std::endl;
            return false;
        }

        if (black_nodes == -1)
        {
            black_nodes = current_black_nodes;
        }
        std::cout << "Black depth: " << current_black_nodes << std::endl;
    }
    std::cout << "Leaves have same black node depth" << std::endl;
    return true;
}
