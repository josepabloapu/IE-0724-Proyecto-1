#ifndef NODE_H
#define NODE_H

#include <memory>
#include <string>

class Node
{
private:
    // no private members, to avoid verbosity

public:
    Node(float value, bool color);
    ~Node();
    float value;
    bool color; // RED = true, BLACK = false
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
    std::string toString() const;
};

#endif
