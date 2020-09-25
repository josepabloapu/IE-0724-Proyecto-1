#ifndef RBT_NODE_H
#define RBT_NODE_H

#include <memory>
#include <string>

enum rbt_color_codes
{
    RBT_COLOR_RED = true,
    RBT_COLOR_BLACK = false,
};

class rbt_node
{
public:
    rbt_node();
    rbt_node(float value, bool color);
    ~rbt_node();
    std::shared_ptr<rbt_node> lc_node;
    std::shared_ptr<rbt_node> rc_node;
    float value;
    bool color;
    std::string to_string() const;
};

#endif
