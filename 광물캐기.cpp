/*
 *https://school.programmers.co.kr/learn/courses/30/lessons/172927
 *
 *���� ĳ��
���� ����
������ ��̷� ���꿡�� ������ ĳ���� �մϴ�. ������ ���̾Ƹ�� ���, ö ���, �� ��̸� ���� 0������ 5������ ������ ������, ��̷� ������ Ķ ���� �Ƿε��� �Ҹ�˴ϴ�. �� ��̷� ������ Ķ ���� �Ƿε��� �Ʒ� ǥ�� �����ϴ�.

image

���� ���, ö ��̴� ���̾Ƹ�带 Ķ �� �Ƿε� 5�� �Ҹ�Ǹ�, ö�� ���� Ķ���� �Ƿε��� 1�� �Ҹ�˴ϴ�. �� ��̴� ������ ������� ���� 5���� ĵ �Ŀ��� �� �̻� ����� �� �����ϴ�.

������ ������ ���� ��Ģ�� ��Ű�鼭 �ּ����� �Ƿε��� ������ ĳ���� �մϴ�.

����� �� �ִ� ����� �ƹ��ų� �ϳ��� ������ ������ ĸ�ϴ�.
�� �� ����ϱ� ������ ��̴� ����� �� ���� ������ ����մϴ�.
������ �־��� ������θ� Ķ �� �ֽ��ϴ�.
���꿡 �ִ� ��� ������ ĳ�ų�, �� ����� ��̰� ���� ������ ������ ĸ�ϴ�.
��, ��̸� �ϳ� �����ؼ� ���� 5���� �������� ĳ��, ���� ��̸� �����ؼ� ���� 5���� �������� ĳ�� ������ �ݺ��ϸ�, �� ����� ��̰� ���ų� ���꿡 �ִ� ��� ������ Ķ ������ ������ �ݺ��ϸ� �˴ϴ�.

������ ���� �ִ� ����� ������ ��Ÿ���� ���� �迭 picks�� �������� ������ ��Ÿ���� ���ڿ� �迭 minerals�� �Ű������� �־��� ��, ������ �۾��� ��������� �ʿ��� �ּ����� �Ƿε��� return �ϴ� solution �Լ��� �ϼ����ּ���.

���ѻ���
picks�� [dia, iron, stone]�� ���� ������ �̷���� �ֽ��ϴ�.
0 �� dia, iron, stone �� 5
dia�� ���̾Ƹ�� ����� ���� �ǹ��մϴ�.
iron�� ö ����� ���� �ǹ��մϴ�.
stone�� �� ����� ���� �ǹ��մϴ�.
��̴� �ּ� 1�� �̻� ������ �ֽ��ϴ�.
5 �� minerals�� ���� �� 50
minerals�� ���� 3���� ���ڿ��� �̷���� ������ ������ �ǹ̴� ������ �����ϴ�.
diamond : ���̾Ƹ��
iron : ö
stone : ��
����� ��
picks	minerals	result
[1, 3, 2]	["diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone"]	12
[0, 1, 1]	["diamond", "diamond", "diamond", "diamond", "diamond", "iron", "iron", "iron", "iron", "iron", "diamond"]	50
����� �� ����
����� �� #1

���̾Ƹ�� ��̷� �տ� �ټ� ������ ĳ�� ö ��̷� ���� ���̾Ƹ��, ö, ���� 1���� ĳ�� 12(1 + 1 + 1 + 1+ 1 + 5 + 1 + 1)�� �Ƿε��� Ķ �� ������ �̶��� �ּҰ��Դϴ�.

����� �� #2

ö ��̷� ���̾Ƹ�� 5���� ĳ�� �� ��̰� ö 5���� ĳ�� 50�� �Ƿε��� Ķ �� ������, �̶��� �ּҰ��Դϴ�.
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