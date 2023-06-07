/*
 *https://school.programmers.co.kr/learn/courses/30/lessons/42885
 ���� ����
���ε��� ���� ������� ����Ʈ�� �̿��Ͽ� �����Ϸ��� �մϴ�. ����Ʈ�� �۾Ƽ� �� ���� �ִ� 2�� �ۿ� Ż �� ����, ���� ���ѵ� �ֽ��ϴ�.

���� ���, ������� �����԰� [70kg, 50kg, 80kg, 50kg]�̰� ����Ʈ�� ���� ������ 100kg�̶�� 2��° ����� 4��° ����� ���� Ż �� ������ 1��° ����� 3��° ����� ������ ���� 150kg�̹Ƿ� ����Ʈ�� ���� ������ �ʰ��Ͽ� ���� Ż �� �����ϴ�.

����Ʈ�� �ִ��� ���� ����Ͽ� ��� ����� �����Ϸ��� �մϴ�.

������� �����Ը� ���� �迭 people�� ����Ʈ�� ���� ���� limit�� �Ű������� �־��� ��, ��� ����� �����ϱ� ���� �ʿ��� ����Ʈ ������ �ּڰ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
���ε��� ���� ����� 1�� �̻� 50,000�� �����Դϴ�.
�� ����� �����Դ� 40kg �̻� 240kg �����Դϴ�.
����Ʈ�� ���� ������ 40kg �̻� 240kg �����Դϴ�.
����Ʈ�� ���� ������ �׻� ������� ������ �� �ִ񰪺��� ũ�� �־����Ƿ� ������� ������ �� ���� ���� �����ϴ�.
����� ��
people	limit	return
[70, 50, 80, 50]	100	3
[70, 80, 50]	100	3
 */


#include "stdafx.h"

int solution(vector<int> people, int limit) {
	int answer = 0;

	sort(people.begin(),people.end(), greater<>());

	list<int> peoples;

	for (auto a : people)
		peoples.push_back(a);


	while(!peoples.empty())
	{
		auto big = peoples.begin();
		auto back = --peoples.end();
		auto backLimit = limit - *big;

		if(big == back)
		{
			peoples.erase(big);
			answer += 1;		
			break;
		}
		if(backLimit < *back)
		{
			peoples.erase(big);
			answer += 1;
			continue;
		}

		while(true)
		{
			auto temp = back;
			if(*(--temp) < backLimit && temp != big)
				back = temp;
			else
				break;
		}
		answer += 1;

		peoples.erase(back);
		peoples.erase(big);
	}



	return answer;
}


int main()
{
	vector<int> people{ 70, 80, 50 };

	cout << solution(people, 100);
}