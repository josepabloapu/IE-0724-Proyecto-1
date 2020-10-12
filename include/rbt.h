#ifndef RBT_H
#define RBT_H

#include <memory>
#include <vector>

#include "rbt_node.h"

enum rbt_error_codes
{
    RBT_SUCCESS = 0,
    RBT_INVALID_PARAM = -1,
    RBT_OUT_OF_RANGE = -2,
    RBT_TIMEOUT = -3,
    RBT_NOT_FOUND = -4,
    RBT_EMPTY = -5,
    RBT_FUNCT_NOT_IMPLEMENTED = -6,
};

class rbt
{
private:
    bool is_empty() const;
    bool is_red(std::shared_ptr<rbt_node> node);
    bool contains(float value);
    std::shared_ptr<rbt_node> rotate_left(std::shared_ptr<rbt_node> node);
    std::shared_ptr<rbt_node> rotate_right(std::shared_ptr<rbt_node> node);
    void flip_colors(std::shared_ptr<rbt_node> node);
    std::shared_ptr<rbt_node> move_red_left(std::shared_ptr<rbt_node> node);
    std::shared_ptr<rbt_node> move_red_right(std::shared_ptr<rbt_node> node);
    std::shared_ptr<rbt_node> balance(std::shared_ptr<rbt_node> node);
    void remove_min();
    std::shared_ptr<rbt_node> remove_min_recursive(std::shared_ptr<rbt_node> node);
    std::shared_ptr<rbt_node> rbt_node_add_recursive(std::shared_ptr<rbt_node> node,
                                                     std::shared_ptr<rbt_node> new_node);
    std::shared_ptr<rbt_node> rbt_node_remove_recursive(std::shared_ptr<rbt_node> node,
                                                        std::shared_ptr<rbt_node> node_to_remove);
    std::shared_ptr<rbt_node> rbt_node_search_recursive(std::shared_ptr<rbt_node> node,
                                                        float num);
    std::shared_ptr<rbt_node> rbt_max_get_recursive(std::shared_ptr<rbt_node> node);
    std::shared_ptr<rbt_node> rbt_min_get_recursive(std::shared_ptr<rbt_node> node);
    void rbt_print_recursive(std::shared_ptr<rbt_node> node) const;

public:
    std::shared_ptr<rbt_node> root;
    /**
     * Constructor y destructor de la clase rbt
     */
    rbt();

    /**
     * Destructor de la clase rbt
     */
    ~rbt();

    /**
     * rbt_create
     * Toma una lista de números flotantes, y crea la estructura de datos deseada.
     *
     * @param [in]  in_number_list es la lista de números flotantes de entrada
     *
     * @returns error_code         un código de error indicando el éxito o error
     *                             de la función
     */
    int rbt_create(std::vector<float> in_number_list);

    /**
     * rbt_node_add
     * Toma un nodo y lo inserta en la estructura de datos.
     * Una nueva raíz puede ser obtenida.
     *
     * @param [in]  new_node  es el nodo con el número flotante por insertar
     *
     * @returns error_code    un código de error indicando el éxito o error
     *                        de la función
     */
    int rbt_node_add(std::shared_ptr<rbt_node> new_node);

    /**
     * rbt_node_remove
     * Toma un nodo arbitrario, lo busca y lo elimina de la estructura de datos.
     * Da error si el nodo no pertenece al árbol.
     *
     * @param [in]  node_to_remove es el nodo por eliminar
     *
     * @returns error_code         un código de error indicando el éxito o error
     *                             de la función
     */
    int rbt_node_remove(rbt_node *node_to_remove);

    /**
     * rbt_search
     * Toma un número flotante, lo busca y se devuelve el nodo al que pertenece.
     * Si existieran varios nodos con el mismo valor, se devuelve cualquiera.
     * Da error si el valor no existe en ningún nodo.
     *
     * @param [in]  node           es el nodo raíz original del árbol
     * @param [in]  num            es el número flotante por buscar
     * @param [out] found_node     es el puntero al nodo encontrado que contiene el valor
     *
     * @returns error_code         un código de error indicando el éxito o error
     *                             de la función
     */
    int rbt_search(float num,
                   rbt_node *found_node);

    /**
     * rbt_max_get
     * Se obtiene el nodo que contenga el valor máximo en todo el árbol.
     *
     * @param [out] max_node  es el nodo encontrado que contiene el valor máximo
     *
     * @returns error_code    un código de error indicando el éxito o error
     *                        de la función
     */
    int rbt_max_get(rbt_node *max_node);

    /**
     * rbt_min_get
     * Se obtiene el nodo que contenga el valor mínimo en todo el árbol.
     *
     * @param [out] min_node  es el nodo encontrado que contiene el valor mínimo
     *
     * @returns error_code    un código de error indicando el éxito o error
     *                        de la función
     */
    int rbt_min_get(rbt_node *min_node);

    /**
     * rbt_print
     * Se imprime el árbol en terminal.
     *
     *
     * @returns error_code    un código de error indicando el éxito o error
     *                        de la función
     */
    int rbt_print();
};

#endif
