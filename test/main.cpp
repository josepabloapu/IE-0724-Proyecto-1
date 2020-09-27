#include "rbt_node.h"
#include "rbt.h"
#include "gtest/gtest.h"

TEST(constructor, positive)
{
    std::shared_ptr<rbt_node> my_node(new rbt_node(1, rbt_color_codes::RBT_COLOR_BLACK));
    EXPECT_EQ(my_node->color, rbt_color_codes::RBT_COLOR_BLACK);
}

// int main(int argc, char **argv)
// {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }

int main(int argc, char **argv)
{
    std::shared_ptr<rbt> my_tree(new rbt());
    std::vector<float> in_number_list{10, 5, 15, 25, 1};

    int status = my_tree->rbt_create(in_number_list);
    if (status == rbt_error_codes::RBT_SUCCESS)
    {
        my_tree->rbt_print();
    }
    else
    {
        std::cout << "Error code:" << status << std::endl;
    }
}
