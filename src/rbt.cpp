#include <iostream>
#include <cmath>

#include "rbt.h"

/**
 * Helper Functions
 */

bool _isEmpty(struct rbt_node *root)
{
    return root->value == NULL;
}

bool _isRed(struct rbt_node *node)
{
    return node->color == rbt_color_codes::RBT_COLOR_RED;
}

bool _contains(struct rbt_node root,
               float num)
{
    rbt_node found_node{};
    int status = rbt_search(root,
                            num,
                            &found_node);

    return found_node.value != NULL;
}

struct rbt_node *_rotateLeft(struct rbt_node *node)
{
    // Add code
}

struct rbt_node *_rotateRight(struct rbt_node *node)
{
    // Add code
}

void _flipColors(struct rbt_node *node)
{
    // Add code
}

struct rbt_node *_moveRedLeft(struct rbt_node *node)
{
    // Add code
}

struct rbt_node *_moveRedRight(struct rbt_node *node)
{
    // Add code
}

struct rbt_node *_balance(struct rbt_node *node)
{
    // Add code
}

struct rbt_node *_remove_min(struct rbt_node *root)
{
    if (_isRed(root->lc_node) && !_isRed(root->rc_node))
        root->color = rbt_color_codes::RBT_COLOR_RED;

    root = _remove_min_recursive(root);

    if (!_isEmpty(root))
        root->color = rbt_color_codes::RBT_COLOR_BLACK;

    return root;
}

struct rbt_node *_remove_min_recursive(struct rbt_node *root)
{
    // Add code
}

struct rbt_node *_remove_max(struct rbt_node *root)
{
    if (_isRed(root->lc_node) && !_isRed(root->rc_node))
        root->color = rbt_color_codes::RBT_COLOR_RED;

    root = _remove_max_recursive(root);

    if (!_isEmpty(root))
        root->color = rbt_color_codes::RBT_COLOR_BLACK;

    return root;
}

struct rbt_node *_remove_max_recursive(struct rbt_node *root)
{
    // Add code
}

struct rbt_node *_rbt_node_add_recursive(struct rbt_node *node,
                                         struct rbt_node *new_node)
{
    // Add code
}

struct rbt_node *_rbt_node_remove_recursive(struct rbt_node *node,
                                            struct rbt_node *node_to_remove)
{
    // Add code
}

struct rbt_node *_rbt_node_search_recursive(struct rbt_node *node,
                                            float num)
{
    // Add code
}

/**
 * Interface Functions
 */
int rbt_create(std::vector<float> in_number_list,
               struct rbt_node *new_root_node)
{
    std::cout << "rbt_create()" << std::endl;
    rbt_node root{nullptr,
                  nullptr,
                  NULL,
                  rbt_color_codes::RBT_COLOR_BLACK};

    for (auto iterator = in_number_list.begin();
         iterator != in_number_list.end();
         iterator++)
    {
        // Add code
    }

    // Add code
    return rbt_error_codes::RBT_SUCCESS;
}

int rbt_node_add(struct rbt_node in_root,
                 struct rbt_node new_node,
                 struct rbt_node *new_root)
{
    std::cout << "rbt_node_add" << std::endl;
    if (std::isnan(new_node.value))
        return rbt_error_codes::RBT_INVALID_PARAM;

    new_root = _rbt_node_add_recursive(&in_root, &new_node);
    new_root->color = rbt_color_codes::RBT_COLOR_BLACK;
    return rbt_error_codes::RBT_SUCCESS;
}

int rbt_node_remove(struct rbt_node in_root,
                    struct rbt_node node_to_remove,
                    struct rbt_node *new_root)
{
    std::cout << "rbt_node_remove" << std::endl;
    if (std::isnan(node_to_remove.value))
        return rbt_error_codes::RBT_INVALID_PARAM;

    if (!_contains(in_root, node_to_remove.value))
        return rbt_error_codes::RBT_NOT_FOUND;

    if (_isRed(in_root.lc_node) && !_isRed(in_root.rc_node))
        in_root.color = rbt_color_codes::RBT_COLOR_RED;

    new_root = _rbt_node_remove_recursive(&in_root, &node_to_remove);

    if (!_isEmpty(new_root))
        new_root->color = rbt_color_codes::RBT_COLOR_BLACK;

    return rbt_error_codes::RBT_SUCCESS;
}

int rbt_search(struct rbt_node in_root,
               float num,
               struct rbt_node *found_node)
{
    std::cout << "rbt_node_remove" << std::endl;
    // Add code
    return rbt_error_codes::RBT_SUCCESS;
}

int rbt_max_get(struct rbt_node in_root,
                struct rbt_node *max_node)
{
    std::cout << "rbt_max_get" << std::endl;
    // Add code
    return rbt_error_codes::RBT_SUCCESS;
}

int rbt_min_get(struct rbt_node in_root,
                struct rbt_node *min_node)
{
    std::cout << "rbt_min_get" << std::endl;
    // Add code
    return rbt_error_codes::RBT_SUCCESS;
}

int rbt_print(struct rbt_node in_root)
{
    std::cout << "rbt_print" << std::endl;
    // Add code
    return rbt_error_codes::RBT_SUCCESS;
}
