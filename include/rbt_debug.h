#ifndef RBT_DEBUG_H
#define RBT_DEBUG_H

#include "rbt.h"
#include "rbt_node.h"

class rbt_debug
{
public:
    std::vector<std::shared_ptr<rbt_node>> leaves;
    rbt_debug();
    ~rbt_debug();
    bool is_red(std::shared_ptr<rbt_node> node);
    void update_leaves(std::shared_ptr<rbt> tree);
    void update_leaves_recursive(std::shared_ptr<rbt_node> node);
    int count_black_nodes_to_leaf(std::shared_ptr<rbt_node> node, float value);
    bool test_black_nodes_count(std::shared_ptr<rbt> tree);
    bool detect_consecutive_red_nodes(std::shared_ptr<rbt> tree);
    std::shared_ptr<rbt_node> detect_consecutive_red_nodes_recursive(std::shared_ptr<rbt_node> node);
    bool detect_red_root(std::shared_ptr<rbt> tree);
    bool test_red_black_tree(std::shared_ptr<rbt> tree);
};

#endif
