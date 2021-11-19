#include "model.h"

using namespace model;

Node::Node(Node* parent, const char* name, Transform transform, ObjectType type) 
{
	this->parent = parent;
	this->name = name;
	this->transform = transform;
	this->type = type;
}

ObjectType Node::getType() 
{
	return type;
}