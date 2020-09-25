#include "rbt_node.h"

rbt_node::rbt_node()
{
    lc_node = nullptr;
    rc_node = nullptr;
    value = 0;
    color = rbt_color_codes::RBT_COLOR_BLACK;
}

rbt_node::rbt_node(float value, bool color) : value(value), color(color)
{
    lc_node = nullptr;
    rc_node = nullptr;
}

rbt_node::~rbt_node()
{
}

/**
 * Return a string representation of this node.
 * The format is:
 * Node (<color>) <value>
 * Left node (<color>) <value
 * Right node (<color>) <value>
 */
std::string rbt_node::to_string() const
{
    std::string s = "";
    std::string colorString = color ? "red" : "black";
    s.append("Node (" + colorString + ") " + std::to_string(value) + "\n");
    if (lc_node != nullptr)
    {
        colorString = lc_node->color ? "red" : "black";
        s.append("Left node (" + colorString + "): " + std::to_string(lc_node->value) + "\n");
    }
    if (rc_node != nullptr)
    {
        colorString = rc_node->color ? "red" : "black";
        s.append("Right node (" + colorString + "): " + std::to_string(rc_node->value) + "\n");
    }
    return s;
}
