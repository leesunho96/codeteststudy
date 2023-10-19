/*
 *
 https://school.programmers.co.kr/learn/courses/30/lessons/155651

 ȣ�� ���
���� ����
ȣ���� � ���� �ڴϴ� �ּ����� ���Ǹ��� ����Ͽ� ���� �մԵ��� �������� �մϴ�. �� �� ����� ������ ��� �ð��� �������� 10�а� û�Ҹ� �ϰ� ���� �մԵ��� ����� �� �ֽ��ϴ�.
���� �ð��� ���ڿ� ���·� ��� 2���� �迭 book_time�� �Ű������� �־��� ��, �ڴϿ��� �ʿ��� �ּ� ������ ���� return �ϴ� solution �Լ��� �ϼ����ּ���.

���ѻ���
1 �� book_time�� ���� �� 1,000
book_time[i]�� ["HH:MM", "HH:MM"]�� ���·� �̷���� �迭�Դϴ�
[��� ���� �ð�, ��� ���� �ð�] �����Դϴ�.
�ð��� HH:MM ���·� 24�ð� ǥ����� ������, "00:00" ���� "23:59" ������ �־����ϴ�.
���� �ð��� ������ �Ѿ�� ���� �����ϴ�.
���� �ð��� �׻� ���� �ð����� �����ϴ�.
����� ��
book_time	result
[["15:00", "17:00"], ["16:40", "18:20"], ["14:20", "15:20"], ["14:10", "19:20"], ["18:20", "21:20"]]	3
[["09:10", "10:10"], ["10:20", "12:20"]]	1
[["10:20", "12:30"], ["10:20", "12:30"], ["10:20", "12:30"]]	3
����� �� ����
����� �� #1

example1
�� ������ �����ϴ�.

����� �� #2

ù ��° �մ��� 10�� 10�п� ��� �� 10�а� û���� �� �� ��° �մ��� 10�� 20�п� �Խ��Ͽ� ����� �� �����Ƿ� ���� 1���� �ʿ��մϴ�.

����� �� #3

�� �մ� ��� ������ �ð��븦 �����߱� ������ 3���� ���� �ʿ��մϴ�.
 */


#include "stdafx.h"

struct cmp
{
	bool operator() (const pair<int, int>& val1, const pair<int, int>& val2)
	{
		return val1.first < val2.first;
	}
};


int solution(vector<vector<string>> book_time)
{
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> rooms;
	vector<pair<int, int>> reservations;

	auto bExistEmptyRoom = [](const priority_queue<int, vector<int>, greater<int>> & rooms, int beginTime)
	{
		const auto& top = rooms.top();
		return top <= beginTime;
	};

	

	// InitializeValues
	{
		for (const auto& bookTime : book_time)
		{
			const int& beginTime = STimeToITime(bookTime[0]);
			const int& endTime = STimeToITime(bookTime[1]) + 10;

			reservations.emplace_back(make_pair(beginTime, endTime));
		}

		sort(reservations.begin(), reservations.end(), cmp());
		rooms.push(0);
		answer += 1;
	}

	// Main Sequence
	{
		for (const auto& reservation : reservations)
		{
			const auto& [beginTime, endTime] = reservation;
			const auto bIsEmptyRoom = bExistEmptyRoom(rooms, beginTime);


			if(bIsEmptyRoom)
				rooms.pop();
			else
				answer += 1;

			rooms.push(endTime);
		}
	}

	return answer;
}


int main()
{
	vector<tuple<vector<vector<string>>, int>> testCases
	{
		{{{"15:00", "17:00"},{"16:40", "18:20"},{"14:20", "15:20"},{"14:10", "19:20"},{"18:20", "21:20"}},	3},
		{{{"09:10", "10:10"},{"10:20", "12:20"}}, 1},
		{{{"10:20", "12:30"},{"10:20", "12:30"},{"10:20", "12:30"}}, 3}
	};


	for (const auto& testCase : testCases)
	{
		const auto [book_Time, expectedResult] = testCase;

		TestFunction(solution, make_tuple(book_Time), expectedResult);

	}

}