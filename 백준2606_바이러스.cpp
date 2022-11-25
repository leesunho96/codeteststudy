#include "stdafx.h"


struct Node
{	
	int computerNum;
	bool bInfested = false;
	vector<Node*> links;

	void LinkNode(Node* node)
	{
		links.push_back(node);
		//node->links.push_back(this);
	}

	void Infested()
	{
		if(bInfested)
			return;

		bInfested = true;
		for (auto a : links)
		{
			a->Infested();
		}

	}
};

void InitDatas(std::vector<Node> &nodes);
int Solution(vector<Node>& nodes);

int main()
{
	vector<Node> nodes;

	InitDatas(nodes);
	cout << Solution(nodes);
}

void InitDatas(std::vector<Node> &nodes)
{
	int ComputerNum;
	int LinkageNum;
	cin >> ComputerNum >> LinkageNum;

	for (size_t i = 0; i < ComputerNum; i++)
	{
		Node node;
		node.computerNum = i + 1;
		nodes.push_back(node);
	}

	int from, to;
	for (size_t i = 0; i < LinkageNum; i++)
	{
		cin >> from >> to;

		nodes.at(from - 1).LinkNode(&nodes.at(to - 1));
		nodes.at(to - 1).LinkNode(&nodes.at(from - 1));
	}
}


int Solution(vector<Node>& nodes)
{
	int result = 0;

	nodes[0].Infested();

	for (auto a : nodes)
	{
		if (a.bInfested)
		{
			result++;
		}
	}

	return result - 1;
}