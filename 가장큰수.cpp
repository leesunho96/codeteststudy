#include "stdafx.h"


namespace usingsort {
	bool compare(string a, string b)
	{
		return a + b > b + a;
	}


	string solution(vector<int> numbers) {
		string answer = "";
		vector<string> temp;

		for (size_t i = 0; i < numbers.size(); i++)
		{
			temp.push_back(to_string(numbers[i]));
		}

		sort(temp.begin(), temp.end(), compare);
		if (temp[0] == "0") return 0;

		for (size_t i = 0; i < temp.size(); i++)
		{
			answer += temp[i];

		}

		return answer;
	}
}

namespace usingpriorityqueue 
{
	struct compare {
		bool operator()(std::string a, std::string b)
		{
			return a + b > b + a;
		}
	};

	string solution(vector<int> numbers) {
		string answer = "";
		priority_queue<string, vector<string>, compare> pq;

		for (size_t i = 0; i < numbers.size(); i++)
		{			
			pq.push(to_string(numbers[i]));		
		}
		
		if (pq.top() == "0") return 0;

		while (!pq.empty())
		{
			answer = pq.top() + answer;
			pq.pop();
		}

		return answer;
	}
}

int main()
{
	vector<int> input = { 3, 30, 34, 5, 9 };

	cout << usingpriorityqueue::solution(input) << endl;

}