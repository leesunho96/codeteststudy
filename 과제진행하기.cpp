/*
 *https://school.programmers.co.kr/learn/courses/30/lessons/176962
 *
 *���� �����ϱ�
���� ����
������ ���� ��� ������ ���� ������� ������ �Ϸ��� ��ȹ�� �������ϴ�.

������ �����ϱ�� �� �ð��� �Ǹ� �����մϴ�.
���ο� ������ ������ �ð��� �Ǿ��� ��, ������ ���� ���̴� ������ �ִٸ� ���� ���̴� ������ ���߰� ���ο� ������ �����մϴ�.
�������̴� ������ ������ ��, ��� ���� ������ �ִٸ�, ����� ������ �̾ �����մϴ�.
����, ������ ���� �ð��� ���� �����ؾ� �Ǵ� ������ ��� ����� ������ ��� �ִٸ�, ���� �����ؾ� �ϴ� �������� �����մϴ�.
����� ������ ���� ���� ���, ���� �ֱٿ� ���� �������� �����մϴ�.
���� ��ȹ�� ���� ������ ���ڿ� �迭 plans�� �Ű������� �־��� ��, ������ ���� ������� �̸��� �迭�� ��� return �ϴ� solution �Լ��� �ϼ����ּ���.

���ѻ���
3 �� plans�� ���� �� 1,000
plans�� ���Ҵ� [name, start, playtime]�� ������ �̷���� �ֽ��ϴ�.
name : ������ �̸��� �ǹ��մϴ�.
2 �� name�� ���� �� 10
name�� ���ĺ� �ҹ��ڷθ� �̷���� �ֽ��ϴ�.
name�� �ߺ��Ǵ� ���Ҵ� �����ϴ�.
start : ������ ���� �ð��� ��Ÿ���ϴ�.
"hh:mm"�� ���·� "00:00" ~ "23:59" ������ �ð����� �� �ֽ��ϴ�.
��� ������ ���� �ð��� �޶� ��ĥ ���� �����ϴ�.
������ "00:00" ... "23:59" ������ �����ϸ� �˴ϴ�. ��, �ÿ� ���� ���� �������� �� ���� ������ �����Դϴ�.
playtime : ������ ��ġ�µ� �ɸ��� �ð��� �ǹ��ϸ�, ������ ���Դϴ�.
1 �� playtime �� 100
playtime�� 0���� �������� �ʽ��ϴ�.
�迭�� �ð������� ���ĵǾ� ���� ���� �� �ֽ��ϴ�.
�������̴� ������ ������ �ð��� ���ο� ������ �����ؾ��ϴ� �ð��� ���� ��� �������̴� ������ ���� ������ �Ǵ��մϴ�.
����� ��
plans	result
[["korean", "11:40", "30"], ["english", "12:10", "20"], ["math", "12:30", "40"]]	["korean", "english", "math"]
[["science", "12:40", "50"], ["music", "12:20", "40"], ["history", "14:00", "30"], ["computer", "12:30", "100"]]	["science", "history", "computer", "music"]
[["aaa", "12:00", "20"], ["bbb", "12:10", "30"], ["ccc", "12:40", "10"]]	["bbb", "ccc", "aaa"]
����� �� ����
����� �� #1

"korean", "english", "math"������ ������ �����մϴ�. "korean" ������ "11:40"�� �����Ͽ� 30�� ���� "12:10"�� ��ġ��, ��� "english" ������ �����մϴ�. 20�� ���� "12:30"�� "english" ������ ��ġ��, ��� "math" ������ �����մϴ�. 40�� ���� "01:10"�� "math" ������ ��Ĩ�ϴ�. ���� "korean", "english", "math" ������ ������ �����Ƿ� ���ʴ�� �迭�� ��� ��ȯ�մϴ�.

����� �� #2

"music", "computer", "science", "history" ������ ������ �����մϴ�.

�ð�	���� �� ����	��� ���� ����	����
"12:20"	"music"	[ ]	"music"�� �����մϴ�.
"12:30"	"computer"	["music"]	"music"�� ��� ���߰�(���� �ð� 30��) "computer"�� �����մϴ�
"12:40"	"science"	["music", "computer"]	"computer"�� ��� ���߰�(���� �ð� 90��) "science"�� �����մϴ�
"13:30"	"computer"	["music"]	"science"�� ������ ���� �ֱٿ� ���� "computer"�� �ٽ� �����մϴ�
"14:00"	"history"	["music", "computer"]	"computer"�� ��� ���߰�(���� �ð� 60��) "history"�� �����մϴ�
"14:30"	"computer"	["music"]	"history"�� ������ ���� �ֱٿ� ���� "computer"�� �ٽ� �����մϴ�"
"15:30"	"music"	[ ]	"computer"�� ������ ���� �ֱٿ� ���� "music"�� �ٽ� �����մϴ�"
"16:00"	-	[ ]	"music"�� �����ϴ�
���� ["science", "history", "computer", "music"] ������ ������ ��Ĩ�ϴ�.

����� �� #3

���� ����
 *
 */

#include "stdafx.h"

#define NAME 0
#define BEGINTIME 1
#define PLAYTIME  2


using TUPLE = tuple<string, int, int>;



vector<string> DoStoredWork(stack<TUPLE>& inputStack, int betweenTime)
{
	vector<string> answer;
	while(betweenTime > 0 && !inputStack.empty())
	{
		auto topTuple = inputStack.top();
		inputStack.pop();

		const int playTime = get<PLAYTIME>(topTuple);

		if(betweenTime - playTime >= 0)
		{
			betweenTime -= playTime;
			answer.push_back(get<NAME>(topTuple));
		}
		else
		{			
			get<PLAYTIME>(topTuple) -= betweenTime;
			inputStack.push(topTuple);
			betweenTime = 0;
		}		
	}
	return answer;
}


vector<string> solution(vector<vector<string>> plans)
{
	vector<string> answer;
	struct cmp
	{
		bool operator()(const TUPLE& val1, const TUPLE& val2)
		{
			const auto val1BeginTime = get<BEGINTIME>(val1);
			const auto val2BeginTime = get<BEGINTIME>(val2);

			return val1BeginTime > val2BeginTime;
		}
	};
	priority_queue<TUPLE, vector<TUPLE>, cmp> pq;

	for (auto plan : plans)
	{
		TUPLE tuple;
		auto& [planSubject, planHour, planPlayTime] = tuple;
		{
			planSubject = plan[0];
			planHour = 60 * stoi(plan[1].substr(0, 2)) + stoi(plan[1].substr(3, 2));
			planPlayTime = stoi(plan[2]);
		}
		pq.push(tuple);
	}

	stack<TUPLE> waitStack;
	int presentTime = 0;



	while(!pq.empty())
	{
		auto topPlan = pq.top();
		pq.pop();

		auto& [subjectName, beginTime, playTime] = topPlan;

		const int betweenTime = beginTime - presentTime;
		auto storedSubject = DoStoredWork(waitStack, betweenTime);

		for (auto subject : storedSubject)
		{
			answer.push_back(subject);
		}

		waitStack.push(topPlan);
		presentTime = beginTime;
	}

	while(!waitStack.empty())
	{	answer.push_back(get<NAME>(waitStack.top()));		waitStack.pop();	}
	return answer;
}


int main()
{
	vector<tuple<vector<vector<string>>, vector<string>>> testCases
	{
		{
			make_tuple(vector<vector<string>>{{"korean", "11:40", "30"}, {"english", "12:10", "20"}, {"math", "12:30", "40"}}, vector<string>{"korean", "english", "math"})
		},
		{
			{{"science", "12:40", "50"},{"music", "12:20", "40"},{"history", "14:00", "30"},{"computer", "12:30", "100"}},{"science", "history", "computer", "music"}
		},
		{
			{{"aaa", "12:00", "20"},{"bbb", "12:10", "30"},{"ccc", "12:40", "10"}} ,{"bbb", "ccc", "aaa"}
		}
	};


	for (auto& testCase : testCases)
	{
		auto& [input, result] = testCase;
		auto GetResult = solution(input);

		auto str = result == GetResult ? "TRUE" : "FALSE";

		PrintAllIngredient<string>("Expected Result : ", result);
		PrintAllIngredient<string>("Get Result : ", GetResult);
		cout << "Pass : "<< str << endl;
	}

}