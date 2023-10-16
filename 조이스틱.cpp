/*
 *https://school.programmers.co.kr/learn/courses/30/lessons/42860
 *
���� ����
���̽�ƽ���� ���ĺ� �̸��� �ϼ��ϼ���. �� ó���� A�θ� �̷���� �ֽ��ϴ�.
ex) �ϼ��ؾ� �ϴ� �̸��� �� ���ڸ� AAA, �� ���ڸ� AAAA

���̽�ƽ�� �� �������� �����̸� �Ʒ��� �����ϴ�.

�� - ���� ���ĺ�
�� - ���� ���ĺ� (A���� �Ʒ������� �̵��ϸ� Z��)
�� - Ŀ���� �������� �̵� (ù ��° ��ġ���� �������� �̵��ϸ� ������ ���ڿ� Ŀ��)
�� - Ŀ���� ���������� �̵� (������ ��ġ���� ���������� �̵��ϸ� ù ��° ���ڿ� Ŀ��)
���� ��� �Ʒ��� ������� "JAZ"�� ���� �� �ֽ��ϴ�.

- ù ��° ��ġ���� ���̽�ƽ�� ���� 9�� �����Ͽ� J�� �ϼ��մϴ�.
- ���̽�ƽ�� �������� 1�� �����Ͽ� Ŀ���� ������ ���� ��ġ�� �̵���ŵ�ϴ�.
- ������ ��ġ���� ���̽�ƽ�� �Ʒ��� 1�� �����Ͽ� Z�� �ϼ��մϴ�.
���� 11�� �̵����� "JAZ"�� ���� �� �ְ�, �̶��� �ּ� �̵��Դϴ�.
������� �ϴ� �̸� name�� �Ű������� �־��� ��, �̸��� ���� ���̽�ƽ ���� Ƚ���� �ּڰ��� return �ϵ��� solution �Լ��� ���弼��.

���� ����
name�� ���ĺ� �빮�ڷθ� �̷���� �ֽ��ϴ�.
name�� ���̴� 1 �̻� 20 �����Դϴ�.
����� ��
name	return
"JEROEN"	56
"JAN"	23
 */




#include "stdafx.h"
#define DEBUG_MODE 1



// ������ ��/��� �̵��� a�� ���ư��� ���� �𸣰�, �����ϴ� ���� �������� ���� �ذ�. ������ �߸� ����.
namespace MissUnderstanding
{
/*
 * get<0>(result) : targetIdx
 * get<1>(result) : moveNumber
 */
CheckDesc GetMinDesc(const int presentIndex, const string presentString, const string compareString, const vector<bool>& sameIDX)
{
	CheckDesc result(0, numeric_limits<int>::max());
	vector<int> validIdx;
	const char& presentChar = presentString.at(presentIndex);

	auto GetMinNum = [&](const char& c)
	{
		const int&& up = c - presentChar;
		const int&& down = abs(26 + presentChar - c);

		return up > down ? down : up;
	};

	auto GetMinIndex = [&](const string& pStr, const int& presentIdx, const int& targetIndex )
	{
		const int&& strSize = pStr.length();

		const int&& direct = abs(presentIndex - targetIndex);
		const int&& round = abs(presentIndex - targetIndex + strSize);

		return min(direct, round);
	};

	for (int i = 0; i < sameIDX.size(); i++)
	{
		if(!sameIDX.at(i))
			validIdx.push_back(i);
	}

	int minComp = numeric_limits<int>::max();

#ifdef DEBUG_MODE
	int mvIDX, mvCh;
#endif


	for (const auto idx : validIdx)
	{
		const auto [moveIDX, moveChar] = make_tuple(GetMinIndex(presentString, presentIndex, idx ),  GetMinNum(compareString.at(idx)));
		const auto moveTime = moveIDX + moveChar;

		if(get<1>(result) > moveTime)
		{
			get<1>(result) = moveTime;
			get<0>(result) = idx;

#ifdef DEBUG_MODE
			mvIDX = moveIDX;
			mvCh = moveChar;
#endif
		}
	}
#ifdef DEBUG_MODE
	cout <<"moveIDX : " << mvIDX << ", moveChar : " << mvCh <<  endl;
#endif
	return result;
}

using CheckDesc = tuple<int, int>;
int solution(string name)
{
	int answer = 0;
	int length = name.size();
	string present(length, 'A');
	vector<bool> sameIDX(name.length(), false);
	int presentIndex = 0;
	




	while(!AllSameInContainer<vector<bool>, bool>(sameIDX, true))
	{
#ifdef DEBUG_MODE
		cout << "present IDX : " << presentIndex << ", Alphabet : " << present.at(presentIndex) << endl;
#endif

		auto [targetIDX, moveTime] = GetMinDesc(presentIndex, present, name, sameIDX);


		answer += moveTime;
		present.at(targetIDX) = name.at(targetIDX);
		sameIDX.at(targetIDX) = true;
		presentIndex = targetIDX;
#ifdef DEBUG_MODE
		cout << 	"change IDX : " << presentIndex << ", Alphabet : " << present.at(presentIndex) << ", moveTime : " << moveTime << endl<<endl;
#endif
	}


	return answer;
}
}

struct node
{
	string substr = string();	
	node* next = nullptr;
};
int solution(string name)
{
	vector<int> AIDX;

	for (int i = 0; i < name.length(); i++)
	{
		if(name.at(i) == 'A')
		{
			AIDX.push_back(i);
		}
	}



	

	return 0;
}
int main()
{
	string sinput = "JEROEN";
	cout << solution(sinput);

};