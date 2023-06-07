/*
 *https://school.programmers.co.kr/learn/courses/30/lessons/172927
 *
 *광물 캐기
문제 설명
마인은 곡괭이로 광산에서 광석을 캐려고 합니다. 마인은 다이아몬드 곡괭이, 철 곡괭이, 돌 곡괭이를 각각 0개에서 5개까지 가지고 있으며, 곡괭이로 광물을 캘 때는 피로도가 소모됩니다. 각 곡괭이로 광물을 캘 때의 피로도는 아래 표와 같습니다.

image

예를 들어, 철 곡괭이는 다이아몬드를 캘 때 피로도 5가 소모되며, 철과 돌을 캘때는 피로도가 1씩 소모됩니다. 각 곡괭이는 종류에 상관없이 광물 5개를 캔 후에는 더 이상 사용할 수 없습니다.

마인은 다음과 같은 규칙을 지키면서 최소한의 피로도로 광물을 캐려고 합니다.

사용할 수 있는 곡괭이중 아무거나 하나를 선택해 광물을 캡니다.
한 번 사용하기 시작한 곡괭이는 사용할 수 없을 때까지 사용합니다.
광물은 주어진 순서대로만 캘 수 있습니다.
광산에 있는 모든 광물을 캐거나, 더 사용할 곡괭이가 없을 때까지 광물을 캡니다.
즉, 곡괭이를 하나 선택해서 광물 5개를 연속으로 캐고, 다음 곡괭이를 선택해서 광물 5개를 연속으로 캐는 과정을 반복하며, 더 사용할 곡괭이가 없거나 광산에 있는 모든 광물을 캘 때까지 과정을 반복하면 됩니다.

마인이 갖고 있는 곡괭이의 개수를 나타내는 정수 배열 picks와 광물들의 순서를 나타내는 문자열 배열 minerals가 매개변수로 주어질 때, 마인이 작업을 끝내기까지 필요한 최소한의 피로도를 return 하는 solution 함수를 완성해주세요.

제한사항
picks는 [dia, iron, stone]과 같은 구조로 이루어져 있습니다.
0 ≤ dia, iron, stone ≤ 5
dia는 다이아몬드 곡괭이의 수를 의미합니다.
iron은 철 곡괭이의 수를 의미합니다.
stone은 돌 곡괭이의 수를 의미합니다.
곡괭이는 최소 1개 이상 가지고 있습니다.
5 ≤ minerals의 길이 ≤ 50
minerals는 다음 3개의 문자열로 이루어져 있으며 각각의 의미는 다음과 같습니다.
diamond : 다이아몬드
iron : 철
stone : 돌
입출력 예
picks	minerals	result
[1, 3, 2]	["diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone"]	12
[0, 1, 1]	["diamond", "diamond", "diamond", "diamond", "diamond", "iron", "iron", "iron", "iron", "iron", "diamond"]	50
입출력 예 설명
입출력 예 #1

다이아몬드 곡괭이로 앞에 다섯 광물을 캐고 철 곡괭이로 남은 다이아몬드, 철, 돌을 1개씩 캐면 12(1 + 1 + 1 + 1+ 1 + 5 + 1 + 1)의 피로도로 캘 수 있으며 이때가 최소값입니다.

입출력 예 #2

철 곡괭이로 다이아몬드 5개를 캐고 돌 곡괭이고 철 5개를 캐면 50의 피로도로 캘 수 있으며, 이때가 최소값입니다.
 *
 */

#include "stdafx.h"



#define DIAMOND 0
#define IRON 1
#define STONE 2

using CostByPick =  tuple<int, int, int>;
int solution(vector<int> picks, vector<string> minerals) {
	int answer = 0;	
	auto [diamondPick, ironPick, stonePick] = VectorToTuple::vectorToTuple<int, 3>(picks);
	
	constexpr int costs[3][3] = 
	{
		{1, 1, 1},
		{5, 1, 1},
		{25, 5, 1}
	};
	vector<CostByPick> mineralCostCases;
	
	auto GetMineralFromString = [&](string a)
	{
		switch(a.size())
		{
		case 7:
			return DIAMOND;
		break;
		case 5:
			return STONE;
		break;
		case 4:
			return IRON;
		break;
		default:
			static_assert(true, "Wrong Input");	
		};
	};

	auto GetCostByPick = [&](int pickType, const vector<int>& mineral)
	{
		int answer = 0;
		for (const auto mine : mineral)
		{
			answer += costs[pickType][mine];
		}
		return answer;
	};

	while(!minerals.empty())
	{
		int diamondCost, ironCost, stoneCost;

		int possibleSize = minerals.size() >= 5 ? 5 : minerals.size();
		vector<int> temp;


		for (auto iter = minerals.begin(); iter < minerals.begin() + possibleSize; ++iter)
			temp.push_back(GetMineralFromString(*iter));

		diamondCost = GetCostByPick(DIAMOND, temp);
		ironCost = GetCostByPick(IRON, temp);
		stoneCost = GetCostByPick(STONE, temp);		
		mineralCostCases.emplace_back(tie(diamondCost, ironCost, stoneCost));
		minerals.erase(minerals.begin(), minerals.begin() + possibleSize);
	}


	int compareNum = mineralCostCases.size() > (diamondPick + ironPick + stonePick) ? (diamondPick + ironPick + stonePick) : mineralCostCases.size();


	sort(mineralCostCases.begin(), mineralCostCases.begin() + compareNum, [&](const CostByPick& val1, const CostByPick& val2)
	{
		const auto& [val1Diamond, val1Iron, val1Stone] = val1;
		const auto& [val2Diamond, val2Iron, val2Stone] = val2;

		const bool&& stoneSame = val1Stone == val2Stone;
		const bool&& ironSame = val1Iron == val2Iron;

		if(!stoneSame)
			return val1Stone > val2Stone;

		if(!ironSame)
			return val2Iron > val2Iron;

		return val1Diamond > val2Diamond;
	});



	
	while(!(mineralCostCases.empty() || (tie(diamondPick, ironPick, stonePick) == make_tuple(0, 0, 0))))
	{
		if(diamondPick > 0)
		{
			answer += get<DIAMOND>(mineralCostCases.front());
			diamondPick--;
		}
		else if(ironPick > 0)
		{
			answer += get<IRON>(mineralCostCases.front());
			ironPick--;
		}
		else if(stonePick > 0)
		{
			answer += get<STONE>(mineralCostCases.front());
			stonePick--;
		}
		mineralCostCases.erase(mineralCostCases.begin());
	}



	return answer;
}


int main()
{
	//vector<int> picks { 1, 3, 2 };
	//vector<string> minerals { "diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone" };

	vector<int> picks{ 0, 1, 1};
	vector<string> minerals {"diamond", "diamond", "diamond", "diamond", "diamond", "iron", "iron", "iron", "iron", "iron", "diamond"};

	cout << solution(picks, minerals);
}