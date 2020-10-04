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
    void update_leaves(std::shared_ptr<rbt> tree);
    void update_leaves_recursive(std::shared_ptr<rbt_node> node);
    int count_black_nodes_to_leaf(std::shared_ptr<rbt_node> node, float value);
    bool test_black_nodes_count(std::shared_ptr<rbt> tree);
};

#endif
