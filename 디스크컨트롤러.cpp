/*
 *
 *https://school.programmers.co.kr/learn/courses/30/lessons/42627
 *
 *�ϵ��ũ�� �� ���� �ϳ��� �۾��� ������ �� �ֽ��ϴ�. ��ũ ��Ʈ�ѷ��� �����ϴ� ����� ���� ������ �ֽ��ϴ�. ���� �Ϲ����� ����� ��û�� ���� ������� ó���ϴ� ���Դϴ�.

�������

- 0ms ������ 3ms�� �ҿ�Ǵ� A�۾� ��û
- 1ms ������ 9ms�� �ҿ�Ǵ� B�۾� ��û
- 2ms ������ 6ms�� �ҿ�Ǵ� C�۾� ��û
�� ���� ��û�� ���Խ��ϴ�. �̸� �׸����� ǥ���ϸ� �Ʒ��� �����ϴ�.
Screen Shot 2018-09-13 at 6.34.58 PM.png

�� ���� �ϳ��� ��û���� ������ �� �ֱ� ������ ������ �۾��� ��û���� ������� ó���ϸ� ������ ���� ó�� �˴ϴ�.
Screen Shot 2018-09-13 at 6.38.52 PM.png

- A: 3ms ������ �۾� �Ϸ� (��û���� ������� : 3ms)
- B: 1ms���� ����ϴٰ�, 3ms ������ �۾��� �����ؼ� 12ms ������ �۾� �Ϸ�(��û���� ������� : 11ms)
- C: 2ms���� ����ϴٰ�, 12ms ������ �۾��� �����ؼ� 18ms ������ �۾� �Ϸ�(��û���� ������� : 16ms)
�� �� �� �۾��� ��û���� ������� �ɸ� �ð��� ����� 10ms(= (3 + 11 + 16) / 3)�� �˴ϴ�.

������ A �� C �� B ������� ó���ϸ�
Screen Shot 2018-09-13 at 6.41.42 PM.png

- A: 3ms ������ �۾� �Ϸ�(��û���� ������� : 3ms)
- C: 2ms���� ����ϴٰ�, 3ms ������ �۾��� �����ؼ� 9ms ������ �۾� �Ϸ�(��û���� ������� : 7ms)
- B: 1ms���� ����ϴٰ�, 9ms ������ �۾��� �����ؼ� 18ms ������ �۾� �Ϸ�(��û���� ������� : 17ms)
�̷��� A �� C �� B�� ������ ó���ϸ� �� �۾��� ��û���� ������� �ɸ� �ð��� ����� 9ms(= (3 + 7 + 17) / 3)�� �˴ϴ�.

�� �۾��� ���� [�۾��� ��û�Ǵ� ����, �۾��� �ҿ�ð�]�� ���� 2���� �迭 jobs�� �Ű������� �־��� ��, �۾��� ��û���� ������� �ɸ� �ð��� ����� ���� ���̴� ������� ó���ϸ� ����� �󸶰� �Ǵ��� return �ϵ��� solution �Լ��� �ۼ����ּ���. (��, �Ҽ��� ������ ���� �����ϴ�)

���� ����
jobs�� ���̴� 1 �̻� 500 �����Դϴ�.
jobs�� �� ���� �ϳ��� �۾��� ���� [�۾��� ��û�Ǵ� ����, �۾��� �ҿ�ð�] �Դϴ�.
�� �۾��� ���� �۾��� ��û�Ǵ� �ð��� 0 �̻� 1,000 �����Դϴ�.
�� �۾��� ���� �۾��� �ҿ�ð��� 1 �̻� 1,000 �����Դϴ�.
�ϵ��ũ�� �۾��� �����ϰ� ���� ���� ������ ���� ��û�� ���� �۾����� ó���մϴ�.
����� ��
jobs	return
[[0, 3], [1, 9], [2, 6]]	9
 */




/*
 * ��λ���
 *	�۾� ��� ť�� �����ϴ� �۾��� ���۽ð��� ������׿� ���ԵǴ°�?
 *	X
 *	�۾��� ���ð��� ��ü �۾� �ð��� ����ȭ�� ������ ��ġ�� ����.
 */

#include "stdafx.h"

//#define DEBUG_MODE 1
int solution(vector<vector<int>> jobs) {
	int answer = 0;
	int total_ElapseTime = 0;
	static int presentTime = 0;
	struct compareForWaitQueue
	{
		bool operator()(const tuple<int, int>& val1, const tuple<int, int>& val2) const
		{
			auto& [val1BeginTime, val1Elapsetime] = val1;
			auto& [val2BeginTime, val2Elapsetime] = val2;

			const int&& val1EvaluateTime = -val1Elapsetime;
			const int&& val2EvaluateTime = -val2Elapsetime;


			return val1EvaluateTime < val2EvaluateTime;
		}
	};
	priority_queue<tuple<int, int>,vector<tuple<int, int>>, compareForWaitQueue> waitQueue;
	auto compareFunc = [&](const tuple<int, int>& val1, const tuple<int, int>& val2)
	{
		auto& [val1BeginTime, val1ElapseTime] = val1;
		auto& [val2BeginTime, val2ElapseTime] = val2;		

		return val1BeginTime == val2BeginTime ? (val1ElapseTime < val2ElapseTime) : (val1BeginTime < val2BeginTime);	
	};


	vector<tuple<int, int>> inputJob;

	for (int i = 0; i < jobs.size(); i++)
	{
		auto& job = jobs.at(i);
		inputJob.emplace_back(make_tuple(job[0], job[1]));
	}

	sort(inputJob.begin(), inputJob.end(), compareFunc);
	auto inputIter = inputJob.begin();
	presentTime = get<0>(* inputIter);
	waitQueue.push(*inputIter);
	++inputIter;
	

	while(!(inputIter == inputJob.end() && waitQueue.empty()))
	{
		if(waitQueue.empty())
		{
			auto [tempBeginTime, tempElapseTime] = *inputIter;
			presentTime = tempBeginTime;
			waitQueue.push(*inputIter);

			++inputIter;
			continue;
		}
		auto [top_BeginTime, top_ElapseTime] = waitQueue.top();
#ifdef  DEBUG_MODE
		{
			cout << top_BeginTime << " " << top_ElapseTime << endl;
		}
#endif
		waitQueue.pop();
		presentTime += top_ElapseTime;		
		while(inputIter != inputJob.end())
		{
			if(get<0>(*inputIter)> presentTime)
				break;
			waitQueue.push(*inputIter);
			++inputIter;
		}
		auto tempElapseTime = (presentTime - top_BeginTime);
#ifdef DEBUG_MODE
		{
			cout <<"elapseTime : "<<  tempElapseTime << endl;
		}
#endif
		total_ElapseTime += tempElapseTime;
	}

	

#ifdef  DEBUG_MODE
	{
		cout << total_ElapseTime << endl;
	}
#endif


	
	return total_ElapseTime / jobs.size();
}

int main()
{
	//vector<vector<int>> jobs = { { 0, 3},{1, 9},{2, 6 } };
	vector<vector<int>> jobs = {{0, 5}, {1, 2}, {5, 5}};
	cout << solution(jobs);
	return 0;
}