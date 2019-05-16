#include "Node.h"

Node::Node(Node* parent)
{
	Parent = parent;
	if(parent != nullptr)
	Points = parent->Points;
}

Node::Node()
{
	Parent = nullptr;
}

Node::~Node()
{
	delete Parent;
}

Node Node::GetParent() const
{
	return *Parent;
}

void Node::SetParent(Node node)
{
	Parent = &node;
}

void Node::PushPoint(int point)
{
	Points.push_front(point);
}

void Node::PushChild(Node node)
{
	Childs.push_front(node);
}

list<Node> Node::GetChilds() const
{
	return Childs;
}

bool Node::CheckPointPresence(int point)
{
	for(list<int>::iterator i = Points.begin() ; i != Points.end() ; ++i)
	{
		if (*i == point) return true;
	}
	return false;
}
