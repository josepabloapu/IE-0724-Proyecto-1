#include <iostream>
#include "rbt.h"

int main()
{
    std::cout << "main()" << std::endl;
    std::vector<float> in_number_list{10, 5, 15};
    struct rbt_node root = {};
    int status = rbt_create(in_number_list, &root);
    status = rbt_print(root);
}
