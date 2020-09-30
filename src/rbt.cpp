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
    rbt_node *my_node = new rbt_node();
    int status = rbt_search(value, my_node);
    delete my_node;
    my_node = nullptr;

    return status == rbt_error_codes::RBT_SUCCESS;
}

std::shared_ptr<rbt_node> rbt::rotate_left(std::shared_ptr<rbt_node> node)
{
    // Se declara una variable puntero tipo nodo, se iguala a un nodo vacio y se le reserva espacio
    std::shared_ptr<rbt_node> node_aux(new rbt_node());

    // Guarda el hijo izquierdo en el papá de la variable temporal
    node_aux->rc_node = node->rc_node->lc_node;

    // Se guarda el tio
    node_aux->lc_node = node->lc_node;

    // Se guarda el dato
    node_aux->value = node->value;
    node_aux->color = rbt_color_codes::RBT_COLOR_RED;

    // Número del papá va al numero del abuelo.
    node->value = node->rc_node->value;

    // Conectamos node_aux al nuevo abuelo
    node->lc_node = node_aux;

    // El hijo derecho pasa a ser el papá
    node->rc_node = node->rc_node->rc_node;

    return node;
}

std::shared_ptr<rbt_node> rbt::rotate_right(std::shared_ptr<rbt_node> node)
{
    // Se declara una variable puntero tipo nodo, se iguala a un nodo vacio y se le reserva espacio
    std::shared_ptr<rbt_node> node_aux(new rbt_node());

    // Guarda el hijo derecho en el papá de la variable temporal
    node_aux->lc_node = node->lc_node->rc_node;

    // Se guarda el tio
    node_aux->rc_node = node->rc_node;

    // Se guarda el dato
    node_aux->value = node->value;
    node_aux->color = rbt_color_codes::RBT_COLOR_RED;

    // Número del papá va al numero del abuelo.
    node->value = node->lc_node->value;

    // Conectamos node_aux al nuevo abuelo
    node->rc_node = node_aux;

    // El hijo izquierdo pasa a ser el papá
    node->lc_node = node->lc_node->lc_node;

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

    // caso 1
    if (is_red(node->rc_node) && !is_red(node->lc_node))
        node = rotate_left(node);

    // caso 2
    if (is_red(node->lc_node) && is_red(node->lc_node->lc_node))
        node = rotate_right(node);

    // caso 3
    if (is_red(node->lc_node) && is_red(node->rc_node))
        flip_colors(node);

    return node;
}

std::shared_ptr<rbt_node> rbt::rbt_node_search_recursive(std::shared_ptr<rbt_node> node,
                                                         float num)
{
    //si el arbol esta vacio o llegó a una hoja
    if (node == nullptr)
        return nullptr;

    //si el nodo actual tiene un valor mayor al buscado
    if (num < node->value)
        node = rbt_node_search_recursive(node->lc_node, num);

    //si el nodo actual tiene un valor menor al buscado
    if (num > node->value)
        node = rbt_node_search_recursive(node->rc_node, num);

    //si el nodo actual tiene el valor buscado
    if (num == node->value)
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

int rbt::rbt_search(float num,
                    rbt_node *found_node)
{
    std::shared_ptr<rbt_node> my_node = rbt_node_search_recursive(root, num);

    if (my_node == nullptr)
        return rbt_error_codes::RBT_NOT_FOUND;

    found_node->lc_node = my_node->lc_node;
    found_node->rc_node = my_node->rc_node;
    found_node->value = my_node->value;
    found_node->color = my_node->color;

    return rbt_error_codes::RBT_SUCCESS;
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
