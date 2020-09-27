#include <algorithm>
#include <iostream>
#include <cmath>
#include <stdexcept>
#include "rbt.h"

rbt::rbt()
{
    root = nullptr;
}

rbt::~rbt()
{
}

bool rbt::is_empty() const
{
    return root == nullptr;
}

bool rbt::is_red(std::shared_ptr<rbt_node> node)
{
    if (node == nullptr)
        return false;

    return node->color == rbt_color_codes::RBT_COLOR_RED;
}

bool rbt::contains(float value)
{
    int status = rbt_search(root, value, nullptr);
    return status == rbt_error_codes::RBT_SUCCESS;
}

std::shared_ptr<rbt_node> rbt::rotate_left(std::shared_ptr<rbt_node> node)
{
    // Add code
    return node;
}

std::shared_ptr<rbt_node> rbt::rotate_right(std::shared_ptr<rbt_node> node)
{
    // Add code
    return node;
}

void rbt::flip_colors(std::shared_ptr<rbt_node> node)
{   
    
    node->color = !node->color;
    node->lc_node->color = !node->lc_node->color;
    node->rc_node->color = !node->rc_node->color;
    
}


std::shared_ptr<rbt_node> rbt::move_red_left(std::shared_ptr<rbt_node> node)
{
    // Add code
    return node;
}

std::shared_ptr<rbt_node> rbt::move_red_right(std::shared_ptr<rbt_node> node)
{
    // Add code
    return node;
}

std::shared_ptr<rbt_node> rbt::balance(std::shared_ptr<rbt_node> node)
{
    // Add code
    return node;
}

std::shared_ptr<rbt_node> rbt::rbt_node_add_recursive(std::shared_ptr<rbt_node> node,
                                                      std::shared_ptr<rbt_node> new_node)
{
    if (node == nullptr)
        return new_node;

    if (new_node->value <= node->value)
        node->lc_node = rbt_node_add_recursive(node->lc_node, new_node);

    if (new_node->value > node->value)
        node->rc_node = rbt_node_add_recursive(node->rc_node, new_node);

    // Add code
    // caso 1
    if (is_red(node->rc_node) && !is_red(node->lc_node))
    {
        node = rotate_left(node);
    }

    // caso 2
    if (is_red(node->lc_node) && !is_red(node->lc_node->lc_node))
    {
        node = rotate_right(node);
    }   

    //caso 3
    if (is_red(node->lc_node) && is_red(node->rc_node))
    {
        flip_colors(node);
    }

    return node;
}

void rbt::rbt_print_recursive(std::shared_ptr<rbt_node> node) const
{
    if (node == nullptr)
        return;

    std::cout << node->to_string() << std::endl;

    rbt_print_recursive(node->lc_node);
    rbt_print_recursive(node->rc_node);
}

/**
 * Interface Functions
 */
int rbt::rbt_create(std::vector<float> in_number_list)
{
    for (auto iterator = in_number_list.begin();
         iterator != in_number_list.end();
         iterator++)
    {
        std::shared_ptr<rbt_node> new_node(
            new rbt_node(*iterator, rbt_color_codes::RBT_COLOR_RED));
        int status = rbt_node_add(new_node);
        if (status != rbt_error_codes::RBT_SUCCESS)
            return status;
    }
    return rbt_error_codes::RBT_SUCCESS;
}

int rbt::rbt_node_add(std::shared_ptr<rbt_node> new_node)
{
    if (std::isnan(new_node->value))
        return rbt_error_codes::RBT_INVALID_PARAM;

    root = rbt_node_add_recursive(root, new_node);
    root->color = rbt_color_codes::RBT_COLOR_BLACK;
    return rbt_error_codes::RBT_SUCCESS;
}

int rbt::rbt_node_remove(std::shared_ptr<rbt_node> node_to_remove)
{
    // Add code
    return rbt_error_codes::RBT_FUNCT_NOT_IMPLEMENTED;
}

int rbt::rbt_search(std::shared_ptr<rbt_node> node,
                    float num,
                    std::shared_ptr<rbt_node> found_node)
{
    //si el arbol esta vacio
    if (node == nullptr)
    {
      return rbt_error_codes::RBT_NOT_FOUND;  
    }

    //si el nodo actual tiene el valor buscado
    if (num == node->value)
    {
        found_node = node;
        return rbt_error_codes::RBT_SUCCESS; 
    }

    //si el nodo actual tiene un valor mayor al buscado
    if (num < root->value)
    {
       rbt_search(root->lc_node, num, found_node);
    }
    
    if (num > root->value)
    {
        rbt_search(root->rc_node, num, found_node);
    }

}

int rbt::rbt_max_get(std::shared_ptr<rbt_node> max_node)
{
    //Add code
    return rbt_error_codes::RBT_FUNCT_NOT_IMPLEMENTED;
}

int rbt::rbt_min_get(std::shared_ptr<rbt_node> min_node)
{
    //Add code
    return rbt_error_codes::RBT_FUNCT_NOT_IMPLEMENTED;
}

int rbt::rbt_print()
{
    rbt_print_recursive(root);
    return rbt_error_codes::RBT_SUCCESS;
}


