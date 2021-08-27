#include "stdafx.h"

int solution(string numbers) {
	int answer = 0;
	vector<int> input;
	vector<int> combination;
	int digit = 1;
	int inumber = stoi(numbers);



	while (true)
	{
		input.push_back(inumber % 10);
		inumber = inumber / 10;
		if (inumber == 0)
			break;     
	}

	sort(input.begin(), input.end());

	do {
		int temp = 0;
		for (int i = 0; i < input.size(); i++)
		{
			temp += pow(10, i) * input[i];
		}
		combination.push_back(temp);
	} while (next_permutation(input.begin(), input.end()));

	for (size_t i = 0; i < combination.size(); i++)
	{
		cout << combination[i] << "    ";
	}


	return answer;
}


int main()
{
	string input = "17";
	solution(input);

}