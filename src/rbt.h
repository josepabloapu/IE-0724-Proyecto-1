#include <vector>

/**
 * Códigos de error
 */
enum rbt_error_codes
{
    RBT_SUCCESS = 0,
    RBT_INVALID_PARAM = -1,
    RBT_OUT_OF_RANGE = -2,
    RBT_TIMEOUT = -3,
    RBT_NOT_FOUND = -4,
};

enum rbt_color_codes
{
    RBT_COLOR_RED = true,
    RBT_COLOR_BLACK = false,
};

/**
 * Struct que define un nodo de la estructura de datos
 */
struct rbt_node
{
    /** Puntero al nodo hijo izquierdo */
    struct rbt_node *lc_node;

    /** Puntero al nodo hijo derecho */
    struct rbt_node *rc_node;

    /** Número flotante asociado al nodo */
    float value;

    /** Valor lógico asociado al color del nodo */
    bool color;
};

/**
 * rbt_create
 * Toma una lista de números flotantes, y crea la estructura de datos deseada.
 * Retorna el nodo raíz del árbol.
 *
 * @param [in]  in_number_list es la lista de números flotantes de entrada
 * @param [out] new_root_node  es el puntero al nodo raíz del árbol creado
 *
 * @returns error_code         un código de error indicando el éxito o error
 *                             de la función
 */
int rbt_create(std::vector<float> in_number_list,
               struct rbt_node *new_root_node);

/**
 * rbt_node_add
 * Toma un nodo y lo inserta en la estructura de datos.
 * Una nueva raíz puede ser obtenida.
 *
 * @param [in]  in_root   es el nodo raíz original del árbol
 * @param [in]  new_node  es el nodo con el número flotante por insertar
 * @param [out] new_root  es el puntero al nuevo nodo raíz del árbol
 *
 * @returns error_code    un código de error indicando el éxito o error
 *                        de la función
 */
int rbt_node_add(struct rbt_node in_root,
                 struct rbt_node new_node,
                 struct rbt_node *new_root);

/**
 * rbt_node_remove
 * Toma un nodo arbitrario, lo busca y lo elimina de la estructura de datos.
 * Da error si el nodo no pertenece al árbol.
 *
 * @param [in]  in_root        es el nodo raíz original del árbol
 * @param [in]  node_to_remove es el nodo por eliminar
 * @param [out] new_root       es el puntero al nuevo nodo raíz del árbol
 *
 * @returns error_code         un código de error indicando el éxito o error
 *                             de la función
 */
int rbt_node_remove(struct rbt_node in_root,
                    struct rbt_node node_to_remove,
                    struct rbt_node *new_root);

/**
 * rbt_search
 * Toma un número flotante, lo busca y se devuelve el nodo al que pertenece.
 * Si existieran varios nodos con el mismo valor, se devuelve cualquiera.
 * Da error si el valor no existe en ningún nodo.
 *
 * @param [in]  in_root        es el nodo raíz original del árbol
 * @param [in]  num            es el número flotante por buscar
 * @param [out] found_node     es el nodo encontrado que contiene el valor
 *
 * @returns error_code         un código de error indicando el éxito o error
 *                             de la función
 */
int rbt_search(struct rbt_node in_root,
               float num,
               struct rbt_node *found_node);

/**
 * rbt_max_get
 * Se obtiene el nodo que contenga el valor máximo en todo el árbol.
 *
 * @param [in]  in_root   es el nodo raíz original del árbol
 * @param [out] max_node  es el nodo encontrado que contiene el valor máximo
 *
 * @returns error_code    un código de error indicando el éxito o error
 *                        de la función
 */
int rbt_max_get(struct rbt_node in_root,
                struct rbt_node *max_node);

/**
 * rbt_min_get
 * Se obtiene el nodo que contenga el valor mínimo en todo el árbol.
 *
 * @param [in]  in_root   es el nodo raíz original del árbol
 * @param [out] min_node  es el nodo encontrado que contiene el valor mínimo
 *
 * @returns error_code    un código de error indicando el éxito o error
 *                        de la función
 */
int rbt_min_get(struct rbt_node in_root,
                struct rbt_node *min_node);

/**
 * rbt_print
 * Se imprime el árbol en terminal.
 *
 * @param [in]  in_root   es el nodo raíz original del árbol
 *
 * @returns error_code    un código de error indicando el éxito o error
 *                        de la función
 */
int rbt_print(struct rbt_node in_root);
