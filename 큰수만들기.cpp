/*
 *https://school.programmers.co.kr/learn/courses/30/lessons/42883
 * � ���ڿ��� k���� ���� �������� �� ���� �� �ִ� ���� ū ���ڸ� ���Ϸ� �մϴ�.

���� ���, ���� 1924���� �� �� ���� �����ϸ� [19, 12, 14, 92, 94, 24] �� ���� �� �ֽ��ϴ�. �� �� ���� ū ���ڴ� 94 �Դϴ�.

���ڿ� �������� ���� number�� ������ ���� ���� k�� solution �Լ��� �Ű������� �־����ϴ�. number���� k ���� ���� �������� �� ���� �� �ִ� �� �� ���� ū ���ڸ� ���ڿ� ���·� return �ϵ��� solution �Լ��� �ϼ��ϼ���.

���� ����
number�� 2�ڸ� �̻�, 1,000,000�ڸ� ������ �����Դϴ�.
k�� 1 �̻� number�� �ڸ��� �̸��� �ڿ����Դϴ�.
����� ��
number	k	return
"1924"	2	"94"
"1231234"	3	"3234"
"4177252841"	4	"775841"
 */


#include "stdafx.h"


string solution(string number, int k)
{
	string answer;

	auto cycle = [&](string number, int k)
	{
		const string targetStr = number.substr(0, k);
		
		int tempVal = -1, index = 0;
		
		for (int i = 0; i < k; i++)
		{
			const int&& tempComp = number.at(i) - '0';

			if(tempVal >= tempComp)
				continue;

			tempVal = tempComp;
			index = i;
		}
		return index;
	};

	
	while(k > 0)
	{
		auto presentIndex = cycle(number, k + 1);

		answer += number.substr(presentIndex, 1);
		number = number.substr(presentIndex + 1, number.length() - presentIndex);
		k -= presentIndex;

		if(number.length() == k)
		{
			number = "";
			break;
		}

	}


	answer += number;


	return answer;
}


int main()
{
	cout << solution(string("999"), 2);
}