#include "stdafx.h"
#define VERTEXNUM N
#define LINKNUM N - 1

struct Node
{	
	
	int index;
	bool bVisited = false;
	vector<Node*> links;
	Node* parentNode = nullptr;

	void LinkNode(Node* node)
	{
		links.push_back(node);
		node->links.push_back(this);
	}
};

void BFS(queue<Node*> &nodeQueue)
{
	Node* parent = nodeQueue.front();
	nodeQueue.pop();

	if(parent->bVisited)
		return;

	parent->bVisited = true;

	for (auto a : parent->links)
	{
		if (!(a->bVisited))
		{
			nodeQueue.push(a);
			a->parentNode = parent;			
		}
	}
}

void Solution(vector<Node*>& Nodes)
{
	queue<Node*> nodequeue;
	nodequeue.push(Nodes[0]);

	while(!nodequeue.empty())
		BFS(nodequeue);

}


int main()
{
	int N;
	vector<Node*> nodes;

	cin >> VERTEXNUM;

	for (size_t i = 0; i < VERTEXNUM; i++)
	{
		Node* node = new Node();
		node->index = i + 1;
		nodes.push_back(node);
	}
	
	int linkNum1, linkNum2;

	for (size_t i = 0; i < LINKNUM; i++)
	{
		cin >> linkNum1 >> linkNum2;
		nodes[linkNum1 - 1]->LinkNode(nodes[linkNum2 - 1]);
	}

	Solution(nodes);

	for (int i = 1; i < VERTEXNUM; i++)
	{
		cout << (nodes[i]->parentNode)->index << endl;
	}

	
	
}
