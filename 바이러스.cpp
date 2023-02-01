#include "stdafx.h"

typedef struct Node
{
private:

	bool isInfected = false;
	vector<Node*> Link;

public:
	void SetLink(Node* to)
	{
		Link.push_back(to);
		to->Link.push_back(this);
	}
	void SetInfest()
	{
		this->isInfected = true;
		for (Node* victim : Link)
		{
			if(!victim->IsInfested())
			{
				victim->isInfected = true;
				victim->SetInfest();
			}
		}
	}
	bool IsInfested()
	{
		return isInfected;
	}
} GraphNode;

void Solution();
void Input(vector<GraphNode*>& Graphs, int& ComputerNumber, int& LinkNumber);
void Output(vector<GraphNode*>& Graphs);

int main()
{
	Solution();
}

void Solution()
{
	vector<Node*> graphs;
	int computerNumber;
	int linkNumber;
	Input(graphs, computerNumber, linkNumber);
	Output(graphs);
}

void Input(vector<Node*>& Graphs, int& ComputerNumber, int& LinkNumber)
{
	cin >> ComputerNumber;
	cin >> LinkNumber;

	for (int i = 0; i < ComputerNumber; i++)
	{
		Graphs.push_back(new Node());
	}

	
	for (int i = 0; i < LinkNumber; i++)
	{
		int from, to;
		cin >> from >> to;
		Graphs.at(from - 1)->SetLink(Graphs.at(to - 1));
	}
}



void Output(vector<GraphNode*>& Graphs)
{

	int result = 0;
	Graphs.at(0)->SetInfest();

	for (auto a : Graphs)
	{
		if(a->IsInfested())
		{
			result++;
		}
	}

	cout << result - 1;
}