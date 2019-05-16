#pragma once
#include <list>
#include <stack>

using namespace std;

class Node
{
	Node* Parent;
	list<int> Points;
	list<Node> Childs;
public:
	Node(Node* parent);
	Node();
	~Node();
	Node GetParent() const;
	void SetParent(Node node);
	void PushPoint(int point);
	void PushChild(Node node);
	list<Node> GetChilds() const;
	bool CheckPointPresence(int point);
};