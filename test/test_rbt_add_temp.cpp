#include <vector>
#include <random>
#include <chrono>

#include "rbt.h"
#include "rbt_node.h"
#include "gtest/gtest.h"

void display_vector(const std::vector<float> &v)
{
    std::copy(v.begin(),
              v.end(),
              std::ostream_iterator<float>(std::cout, " "));
}

int generate_random_int_value()
{
    std::random_device rd;
    std::mt19937 engine(rd());

    // distribution in range [100, 100'000]
    std::uniform_int_distribution<std::mt19937::result_type> dist6(100, 100'000);
    return dist6(engine);
}

std::vector<float> generate_vector_with_random_values(int size)
{
    std::vector<float> v(size);
    float increment = 0.01f;
    std::generate(begin(v), end(v), [&increment]() {static float start = 0.0f; return start += increment; });
    std::random_shuffle(v.begin(), v.end());
    return v;
}

int timed_add_function(std::shared_ptr<rbt> tree, float value)
{
    std::shared_ptr<rbt_node> new_node(new rbt_node(value, rbt_color_codes::RBT_COLOR_RED));

    auto t1 = std::chrono::high_resolution_clock::now();

    int status = tree->rbt_node_add(new_node);
    if (status != rbt_error_codes::RBT_SUCCESS)
        return status;

    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
    return duration;
}

void test_timed_add_function()
{
    int size = generate_random_int_value();
    std::vector<float> my_vector = generate_vector_with_random_values(size);
    float value_to_insert = my_vector.back();
    std::vector<float> samples;
    std::copy(my_vector.begin(), my_vector.end() - 1,
              std::back_inserter(samples));
    int sample_size = samples.size();

    std::shared_ptr<rbt> tree(new rbt());
    tree->rbt_create(samples);
    int time = timed_add_function(tree, value_to_insert);

    std::cout << sample_size << ", " << time << std::endl;
}

TEST(RedBlackTree, Time_AddFunction_Size_VS_NanoSeconds)
{
    for (int i = 0; i < 100; ++i)
    {
        test_timed_add_function();
    }
    EXPECT_TRUE(true);
}
