#include "stdafx.h"
#define TUPLE tuple<int, int>




int solution(vector<vector<int>> scores) {
	int answer = 0;


	TUPLE wanho = make_tuple(scores[0][0], scores[0][1]);
	int wanhoSum = get<0>(wanho) + get<1>(wanho);

	auto compare = [&](vector<int>& v1, vector<int>& v2)
	{
		auto [v1x, v1y] = v1;
		auto [v2x, v2y] = v2;


		if(v1x > v2x)
			return true;
		if(v1x == v2x)
			return v1y > v2y;
		return false;
	};


	return answer;
}


int main()
{
	vector<vector<int>> input = {{2,2},{1,4},{3,2},{3,2},{2,1}};
	cout << solution(input);
}
