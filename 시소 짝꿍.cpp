#include "stdafx.h"

/*
long long solution(vector<int> weights)
{
    long long answer = 0;

	set<long> inputSet;
	unordered_map<long, long> inputMap;



	// 입력에서 중복 제거, 중복된 값의 개수
	for (const auto a : weights)
	{
		if(inputSet.find(a) == inputSet.end())
		{
			inputSet.insert(a);
			inputMap[a] = 1;
		}
		else
		{
			inputMap[a] += 1;
		}
	}	


	unordered_map<long, set<long>> caseMap;
	set<long> caseSet;
	set<pair<long, long>> mulSet;

	// 나올 수 있는 값의 개수. 
    for (const auto a : inputSet)
    {
	    for (long i = 2; i <= 4; i++)
	    {
			long result = i * a;
			caseMap[i * a].insert(a);
			caseSet.insert(i * a);
	    }
    }


	
	for (auto a : caseSet)
	{
		set<long>& temp = caseMap[a];

		for (auto it = temp.begin(); it != temp.end(); ++it)
		{
			auto tempIt = it;
			++tempIt;
			for (auto compIt = tempIt; compIt != temp.end(); ++compIt)
			{
				auto tempVal = make_pair(*it, *compIt);
				mulSet.insert(tempVal);
			}
		}

	}

	// 입력값 중복에 따른 경우의 수 합.
	for (auto a : inputSet)
	{
		const long val = inputMap[a];

		answer += (val * (val - 1)) / 2;
	}

	answer += mulSet.size();

    return answer;
}

*/


long long solution(vector<int> weights) {
	vector<int> visit(4001, -1);
	vector<int> Same(1001, -1);

	long long cnt = 0;



	for (auto weight : weights) 
	{
		Same[weight] += 1;
		cnt += Same[weight];
		int SameCnt = Same[weight];

		for (int j = 2; j <= 4; j++) {
			visit[weight * j] += 1;
			cnt += (visit[weight * j] - SameCnt);
		}
	}

	
	return cnt;
}
long main()
{
	vector<int> input = { 100,180,360,100,270 };

    cout << solution(input);
}