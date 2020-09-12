#include "node.hpp"

/**
 * Initializes a new node
 */
Node::Node(float value, bool color) : value(value), color(color)
{
    left = nullptr;
    right = nullptr;
}

/**
 * Destructor
 */
Node::~Node()
{
}

/**
 * Return a string representation of this node.
 * The format is:
 * Node (<color>) <value>
 * Left node (<color>) <value
 * Right node (<color>) <value>
 */
std::string Node::toString() const
{
	std::string s = "";
	std::string colorString = color ? "red" : "black";
	s.append("Node (" + colorString + ") " + std::to_string(value) + "\n");
	if (left != nullptr)
	{
		colorString = left->getColor() ? "red" : "black";
		s.append("Left node (" + colorString + "): " + std::to_string(left->value) + "\n");
	}
	if (right != nullptr)
	{
		colorString = right->getColor() ? "red" : "black";
		s.append("Right node (" + colorString + "): " + std::to_string(right->value) + "\n");
	}
	return s;
}
