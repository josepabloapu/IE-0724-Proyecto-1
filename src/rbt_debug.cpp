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

bool rbt_debug::is_red(std::shared_ptr<rbt_node> node)
{
    if (node == nullptr)
        return false;

    return node->color == rbt_color_codes::RBT_COLOR_RED;
}

void rbt_debug::update_leaves(std::shared_ptr<rbt> tree)
{
    leaves.clear();
    update_leaves_recursive(tree->root);
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
            std::cout << "Alert at node: " << it->value << std::endl;
            std::cout << "Black depth: " << current_black_nodes << std::endl;
            std::cout << "Error. Violation occured" << std::endl;
            return false;
        }

        if (black_nodes == -1)
        {
            black_nodes = current_black_nodes;
        }
    }
    std::cout << "Black depth: " << black_nodes << std::endl;
    std::cout << "Leaves have same black node depth" << std::endl;
    return true;
}

void rbt_debug::detect_consecutive_red_nodes(std::shared_ptr<rbt> tree)
{
    std::shared_ptr<rbt_node> bad_node = detect_consecutive_red_nodes_recursive(tree->root);
    if (bad_node != nullptr)
        std::cout << "Error. Violation occured." << std::endl;
    else
        std::cout << "No consecutive red nodes found " << std::endl;
}

std::shared_ptr<rbt_node> rbt_debug::detect_consecutive_red_nodes_recursive(std::shared_ptr<rbt_node> node)
{
    if (node == nullptr)
        return nullptr;

    if (is_red(node))
    {
        if (is_red(node->lc_node))
        {
            std::cout << "Alert at node: " << node->value << std::endl;
            return node;
        }

        if (is_red(node->rc_node))
        {
            std::cout << "Alert at node: " << node->value << std::endl;
            return node;
        }
    }

    std::shared_ptr<rbt_node> lc_node = detect_consecutive_red_nodes_recursive(node->lc_node);
    if (lc_node != nullptr)
        return node;

    std::shared_ptr<rbt_node> rc_node = detect_consecutive_red_nodes_recursive(node->rc_node);
    if (rc_node != nullptr)
        return node;

    return nullptr;
}
