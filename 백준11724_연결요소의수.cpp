#include "stdafx.h"
#define VERTEXNUM N
#define LINKNUM M
struct Node
{
	int GroupNum;
	bool bVisited = false;
	vector<Node*> links;

	void LinkNode(Node* node)
	{
		links.push_back(node);
		node->links.push_back(this);
	}

	void ConnectGroup()
	{
		if(bVisited)
			return;

		else
		{
			bVisited = true;
			for (auto a : links)
			{
				if(!(a->bVisited))
					a->ConnectGroup();
			}
		}
	}
};


void InitData(int &N, int &M, std::vector<Node *> &Nodes);
int Solution(std::vector<Node *> &Nodes);
void DFS(Node* node);

int main()
{
	int N, M;
	vector<Node*> Nodes;

	InitData(N, M, Nodes);
	cout << Solution(Nodes);
}


void InitData(int &N, int &M, std::vector<Node *> &Nodes)
{
	cin >> VERTEXNUM >> LINKNUM;
	for (size_t i = 0; i < VERTEXNUM; i++)
	{
		Node* node = new Node();
		Nodes.push_back(node);
	}

	int u, v;
	for (size_t i = 0; i < LINKNUM; i++)
	{
		cin >> u >> v;
		Nodes[u - 1]->LinkNode(Nodes[v - 1]);
	}
}

int Solution(std::vector<Node*>& Nodes)
{
	int result = 0;

	for (auto a : Nodes)
	{
		if(!(a->bVisited))
		{
			DFS(a);
			result++;
		}
	}


	return result;
}

void DFS(Node * node)
{	
	node->ConnectGroup();
}
