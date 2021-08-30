#include "stdafx.h"

int dfs(int sum, int depth, vector<int> input, int target)
{
	if (depth == input.size() && sum == target)
		return 1;
	else if(depth == input.size() && sum != target)
		return 0;
	else
	{
		return dfs(sum + input[depth], depth + 1, input, target) + dfs(sum - input[depth], depth + 1, input, target);
	}
	
}


int solution(vector<int> numbers, int target) {
	int answer = 0;

	vector<pair<int, int>> temp;
	return dfs(0, 0, numbers, target);
}

int main()
{
	vector<int> input = { 1, 1, 1, 1, 1 };
	int target = 3;

	cout << solution(input, target);
}