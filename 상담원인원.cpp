/*
https://school.programmers.co.kr/learn/courses/30/lessons/214288

���� �ο�
���� ����
�����񽺴� ����� SW ���� ä���� ���� ��÷� ä�� ����ȸ�� �����ϰ� �ֽ��ϴ�. ä�� ����ȸ������ ä��� ���õ� ����� ���ϴ� �����ڿ��� ����� 1:1�� ����� �� �ִ� ��ȸ�� �����մϴ�. ä�� ����ȸ���� ���� n���� ������, 1~k������ �з��Ǵ� ��� ������ �ֽ��ϴ�.
�� ����� k���� ��� ���� �� �ϳ��� ����� �� �ֽ��ϴ�. ����� �ڽ��� ����ϴ� ������ ��㸸 �����ϸ�, �ٸ� ������ ����� �Ұ����մϴ�. ����� ���ÿ� ������ �� ����� ��� �����ϸ�, ��� �ð��� ��Ȯ�� �����ڰ� ��û�� �ð���ŭ �ɸ��ϴ�.

�����ڰ� ��� ��û�� �ϸ� �Ʒ��� ���� ��Ģ��� ����� �����մϴ�.

����� ���ϴ� �����ڰ� ��� ��û�� ���� ��, �������� ��� ������ ����ϴ� ���� �� ��� ���� �ƴ� ����� ����� �����մϴ�.
���� �������� ��� ������ ����ϴ� ���䰡 ��� ��� ���̶��, �ڽ��� ���ʰ� �� ������ ��ٸ��ϴ�. �����ڰ� ��ٸ� �ð��� �����ڰ� ��� ��û���� ������ ����� ����� ������ �������� �ð��Դϴ�.
��� ����� ����� ������ �� �ڽ��� ��� ������ ����� �ޱ� ���� ��ٸ��� �ִ� �����ڰ� ������ ��� ����� �����մϴ�. �̶�, ���� ��� ��û�� �����ڰ� �켱�˴ϴ�.
�������� ��� ��û ������ �־��� ��, �����ڰ� ����� ��û���� ������ ����� �����ϱ���� ��ٸ� �ð��� ���� �ּҰ� �ǵ��� �� ��� �������� ���� �ο��� ���Ϸ� �մϴ�. ��, �� �������� ���� �ο��� ��� �� �� �̻��̾�� �մϴ�.

���� ���, 5���� ���䰡 �ְ� 1~3���� 3���� ��� ������ ���� �� �Ʒ��� ���� �������� ��� ��û�� �ֽ��ϴ�.

�������� ��� ��û

������ ��ȣ	�ð�	��� �ð�	��� ����
1�� ������	10��	60��	1�� ����
2�� ������	15��	100��	3�� ����
3�� ������	20��	30��	1�� ����
4�� ������	30��	50��	3�� ����
5�� ������	50��	40��	1�� ����
6�� ������	60��	30��	2�� ����
7�� ������	65��	30��	1�� ����
8�� ������	70��	100��	2�� ����
�̶�, ���� �ο��� �Ʒ��� ���� ���ϸ�, �����ڰ� ��ٸ� �ð��� ���� 25�� �ּҰ� �˴ϴ�.

1�� ����	2�� ����	3�� ����
2��	1��	2��
1�� ����

1�� ������ ����ϴ� ���䰡 2�� �ֽ��ϴ�.

1�� �����ڰ� ��� ��û���� ��, ����#1�� 10��~70�� ���� ����� �մϴ�.
3�� �����ڰ� ��� ��û���� ��, ����#2�� 20��~50�� ���� ����� �մϴ�.
5�� �����ڰ� ��� ��û���� ��, ����#2�� 50��~90�� ���� ����� �մϴ�.
7�� �����ڰ� ��� ��û���� ��, ��� ���䰡 ��� ���̹Ƿ� 1�� �������� ����� ���� ������ 5�� ���� ��ٸ��� ����#1�� 70��~100�� ���� ����� �մϴ�.
2�� ����

2�� ������ ����ϴ� ���䰡 1�� �ֽ��ϴ�.

6�� �����ڰ� ��� ��û���� ��, ����� 60��~90�� ���� ����� �մϴ�.
8�� �����ڰ� ��� ��û���� ��, ��� ���䰡 ��� ���̹Ƿ� 6�� �������� ����� ���� ������ 20�� ���� ��ٸ��� 90��~190�� ���� ����� �մϴ�.
3�� ����

3�� ������ ����ϴ� ���䰡 2�� �ֽ��ϴ�.

2�� �����ڰ� ��� ��û���� ��, ����#1�� 15��~115�� ���� ����� �մϴ�.
4�� �����ڰ� ��� ��û���� ��, ����#2�� 30��~80�� ���� ����� �մϴ�.
��� ������ ���� ��Ÿ���� ���� k, ������ ���� ��Ÿ���� ���� n�� �������� ��� ��û�� ���� 2���� ���� �迭 reqs�� �Ű������� �־����ϴ�. ���� �ο��� ������ �������� �� �����ڵ��� ����� �ޱ���� ��ٸ� �ð��� ��� ���� ���� �ּڰ��� return �ϵ��� solution �Լ��� �ϼ��� �ּ���.

���ѻ���
1 �� k �� 5
k �� n �� 20
3 �� reqs�� ���� �� 300
reqs�� ���Ҵ� [a, b, c] ������ ���̰� 3�� ���� �迭�̸�, c�� ������ ����� ���ϴ� �����ڰ� a�п� b�� ������ ����� ��û������ �ǹ��մϴ�.
1 �� a �� 1,000
1 �� b �� 100
1 �� c �� k
reqs�� a�� �������� ������������ ���ĵǾ� �ֽ��ϴ�.
reqs �迭���� a�� �ߺ����� �ʽ��ϴ�. ��, �����ڰ� ��� ��û�� �ð��� ��� �ٸ��ϴ�.
����� ��
k	n	reqs	result
3	5	[[10, 60, 1], [15, 100, 3], [20, 30, 1], [30, 50, 3], [50, 40, 1], [60, 30, 2], [65, 30, 1], [70, 100, 2]]	25
2	3	[[5, 55, 2], [10, 90, 2], [20, 40, 2], [50, 45, 2], [100, 50, 2]]	90
����� �� ����
����� �� #1

���� ���ÿ� �����ϴ�.

����� �� #2

�������� ��� ��û

������ ��ȣ	�ð�	��� �ð�	��� ����
1�� ������	5��	55��	2�� ����
2�� ������	10��	90��	2�� ����
3�� ������	20��	40��	2�� ����
4�� ������	50��	45��	2�� ����
5�� ������	100��	50��	2�� ����
���� �ο��� �Ʒ��� ���� ���ϸ�, �����ڰ� ��ٸ� �ð��� ���� 90���� �ּҰ� �˴ϴ�.

1�� ����	2�� ����
1��	2��
1�� ����

1�� ������ ����ϴ� ���䰡 1�� �ֽ��ϴ�. 1�� ������ ����� ��û�� �����ڰ� ������, �������� ���� �ο��� ��� �� �� �̻��̾�� �մϴ�.

2�� ����

2�� ������ ����ϴ� ���䰡 2�� �ֽ��ϴ�.

1�� �����ڰ� ��� ��û���� ��, ����#1�� 5��~60�� ���� ����� �մϴ�.
2�� �����ڰ� ��� ��û���� ��, ����#2�� 10��~100�� ���� ����� �մϴ�.
3�� �����ڰ� ��� ��û���� ��, ��� ���䰡 ��� ���̹Ƿ� 1�� �������� ����� ���� ������ 40�� ���� ��ٸ��� ����#1�� 60��~100�� ���� ����� �մϴ�. 1�� �������� ����� ������ �� 4�� �����ڵ� ��ٸ��� �־�����, ���� ��� ��û�� 3�� �����ڰ� �켱�˴ϴ�.
4�� �����ڰ� ��� ��û���� ��, ��� ���䰡 ��� ���̹Ƿ� 2�� �������� ����� ���� ������ 50�� ���� ��ٸ��� ����#2�� 100��~145�� ���� ����� �մϴ�. �̶�, ����#1�� ����� ���� ������ ��� ����� ����ص� ��������ϴ�.
5�� �����ڰ� ��� ��û���� ��, ����#1�� 100��~150�� ���� ����� �մϴ�.
���� 90�� return �ϸ� �˴ϴ�.

 
 */

#include "stdafx.h"

class CouncilType
{
public:
	CouncilType(vector<vector<int>>& reqs, int x) : councilType(x)
	{
		for (const auto& req : reqs)
		{
			const auto [beginTime, needTime, type] = array<int, 3> {req[0], req[1], req[2]};

			if(type != councilType)
				continue;

			councilRequirements.emplace_back(make_tuple(beginTime, needTime));
		}

		costsPerTutorNum.push_back(GetCostTime(1));
	};


public:
	int GetPresentTime();
	int GetAddedTutorTime();
	void AddTutor(){tutorNum++;};
	int GetWaitTime(int tutorNum);

private:
	int GetPossibleTutor(vector<int>& timeTable, int beginTime);
	int GetCostTime(int targetTutorNum);
	


private:
	int councilType;
	int tutorNum = 1;

	vector<tuple<int, int>> councilRequirements;
	vector<int> costsPerTutorNum;
};


int CouncilType::GetPresentTime()
{
	return GetWaitTime(tutorNum);
}

int CouncilType::GetAddedTutorTime()
{
	return GetWaitTime(tutorNum + 1);
}

int CouncilType::GetPossibleTutor(vector<int>& timeTable, int tuteeBeginTime)
{
	int targetTutorIdx = 0;
	for (size_t i = 0; i < timeTable.size(); i++)
	{
		const auto& tutorEndTime = timeTable[i];
		if(tutorEndTime <= tuteeBeginTime)
			return i;

		const auto& minTutorEndTime = timeTable[targetTutorIdx];

		if(minTutorEndTime > tutorEndTime)
			targetTutorIdx = i;
	}
	return targetTutorIdx;
}

int CouncilType::GetCostTime(int targetTutorNum)
{
	int waitTime = 0;
	int elapseTime = 0;
	vector<int> timeTable(targetTutorNum, 0);


	for (const auto& councilRequirement : councilRequirements)
	{
		const auto&[beginTime, needTime] = councilRequirement;
		const int nextTutorNum = GetPossibleTutor(timeTable, beginTime);
		const auto targetTutorEndTime = timeTable[nextTutorNum];
		int newEndTime;

		if(targetTutorEndTime > beginTime)
		{
			waitTime += targetTutorEndTime - beginTime;
			newEndTime = targetTutorEndTime + needTime;			
		}
		else
		{
			newEndTime = beginTime + needTime;
		}

		timeTable[nextTutorNum] = newEndTime;		
	}

	return waitTime;
}

int CouncilType::GetWaitTime(int tutorNum)
{
	if(costsPerTutorNum.size() < tutorNum)
		costsPerTutorNum.push_back(GetCostTime(tutorNum));

	return costsPerTutorNum[tutorNum - 1];	
}

int solution(int k, int n, vector<vector<int>> reqs) {
	int answer = 0;

	const int& councilTypeNum = k;
	const int& tutorNum = n;
	vector<CouncilType> tables;

	// initialize
	{
		for (int i = 0; i < councilTypeNum; i++)
			tables.emplace_back(reqs, i + 1);
	}

	// Sequence.
	{
		const int&& leftTutorNum = tutorNum - councilTypeNum;

		for (int i = 0; i < leftTutorNum; i++)
		{
			vector<int> costTimes;

			for (auto iter = tables.begin(); iter != tables.end(); ++iter)						
			{
				auto& targetTable = *iter;
				const auto&& decreaseTime = targetTable.GetPresentTime() - targetTable.GetAddedTutorTime();
				costTimes.push_back(decreaseTime);
			}

			int maxIdx = 0;
			for (int i = 0; i < costTimes.size(); i++)
			{
				if(costTimes[maxIdx] < costTimes[i])
					maxIdx = i;
			}
			tables[maxIdx].AddTutor();
		}

		for (auto& table : tables)
		{
			answer += table.GetPresentTime();
		}
	}

	return answer;
}


int main()
{
	vector<tuple<int, int, vector<vector<int>>, int>> testCases
	{
		{3,	5,{{10, 60, 1},{15, 100, 3},{20, 30, 1},{30, 50, 3},{50, 40, 1},{60, 30, 2},{65, 30, 1},{70, 100, 2}},	25},
		{2,	3,{{5, 55, 2},{10, 90, 2},{20, 40, 2},{50, 45, 2},{100, 50, 2}},	90}
	};

	for (const auto& testCase : testCases)
	{
		const auto& [k, n, req, expectedResult] = testCase;
		TestFunction(solution, make_tuple(k, n, req), expectedResult);
	}

}