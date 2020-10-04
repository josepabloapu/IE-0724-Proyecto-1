#include "rbt.h"
#include "rbt_node.h"
#include "rbt_debug.h"
#include "gtest/gtest.h"

int main(int argc, char **argv)
{
    std::vector<float> in_number_list{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::shared_ptr<rbt> my_tree(new rbt());
    my_tree->rbt_create(in_number_list);

    rbt_node *node_to_remove = new rbt_node();
    node_to_remove->value = 5;
    my_tree->rbt_node_remove(node_to_remove);
    // my_tree->rbt_print();

    std::shared_ptr<rbt_debug> my_debug(new rbt_debug());
    my_debug->test_black_nodes_count(my_tree);
}
