#include "stdafx.h"

int solution(vector<int> elements);
void GetAdds(const vector<int>& Elements, vector<int>& Results, const int& idx);

int main()
{
	vector<int> inputs;
	
	inputs.push_back(7);
	inputs.push_back(9);
	inputs.push_back(1);
	inputs.push_back(1);
	inputs.push_back(4);

	cout << solution(inputs);
	return 0;
}

int solution(vector<int> elements)
{
	int answer = 0;
	vector<int> results;

	for (size_t i = 0; i < elements.size(); i++)
	{
		GetAdds(elements, results, i + 1);
	}


	sort(results.begin(), results.end());
	results.erase(unique(results.begin(), results.end()), results.end());
	answer = results.size();
	return answer;
}

void GetAdds(const vector<int>& Elements, vector<int>& Results, const int& idx)
{
	int temp = 0;
	for (size_t i = 0; i < Elements.size(); i++)
	{
		temp += Elements.at((idx + i) % Elements.size());
		Results.push_back(temp);
	}
}
