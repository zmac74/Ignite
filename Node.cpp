#include "model.h"

using namespace model;

Node::Node(Node* parent, const char* name, Transform transform, NodeType type)
{
	this->parent = parent;
	this->name = name;
	this->transform = transform;
	this->type = type;
}

void Node::addChild(Node* child)
{
	children.push_back(child);
}

bool Node::isRoot() 
{
	if (parent == nullptr) return true;
	else return false;
}

NodeType Node::getType()
{
	return type;
}