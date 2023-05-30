/*
 *
 *https://school.programmers.co.kr/learn/courses/30/lessons/42627
 *
 *하드디스크는 한 번에 하나의 작업만 수행할 수 있습니다. 디스크 컨트롤러를 구현하는 방법은 여러 가지가 있습니다. 가장 일반적인 방법은 요청이 들어온 순서대로 처리하는 것입니다.

예를들어

- 0ms 시점에 3ms가 소요되는 A작업 요청
- 1ms 시점에 9ms가 소요되는 B작업 요청
- 2ms 시점에 6ms가 소요되는 C작업 요청
와 같은 요청이 들어왔습니다. 이를 그림으로 표현하면 아래와 같습니다.
Screen Shot 2018-09-13 at 6.34.58 PM.png

한 번에 하나의 요청만을 수행할 수 있기 때문에 각각의 작업을 요청받은 순서대로 처리하면 다음과 같이 처리 됩니다.
Screen Shot 2018-09-13 at 6.38.52 PM.png

- A: 3ms 시점에 작업 완료 (요청에서 종료까지 : 3ms)
- B: 1ms부터 대기하다가, 3ms 시점에 작업을 시작해서 12ms 시점에 작업 완료(요청에서 종료까지 : 11ms)
- C: 2ms부터 대기하다가, 12ms 시점에 작업을 시작해서 18ms 시점에 작업 완료(요청에서 종료까지 : 16ms)
이 때 각 작업의 요청부터 종료까지 걸린 시간의 평균은 10ms(= (3 + 11 + 16) / 3)가 됩니다.

하지만 A → C → B 순서대로 처리하면
Screen Shot 2018-09-13 at 6.41.42 PM.png

- A: 3ms 시점에 작업 완료(요청에서 종료까지 : 3ms)
- C: 2ms부터 대기하다가, 3ms 시점에 작업을 시작해서 9ms 시점에 작업 완료(요청에서 종료까지 : 7ms)
- B: 1ms부터 대기하다가, 9ms 시점에 작업을 시작해서 18ms 시점에 작업 완료(요청에서 종료까지 : 17ms)
이렇게 A → C → B의 순서로 처리하면 각 작업의 요청부터 종료까지 걸린 시간의 평균은 9ms(= (3 + 7 + 17) / 3)가 됩니다.

각 작업에 대해 [작업이 요청되는 시점, 작업의 소요시간]을 담은 2차원 배열 jobs가 매개변수로 주어질 때, 작업의 요청부터 종료까지 걸린 시간의 평균을 가장 줄이는 방법으로 처리하면 평균이 얼마가 되는지 return 하도록 solution 함수를 작성해주세요. (단, 소수점 이하의 수는 버립니다)

제한 사항
jobs의 길이는 1 이상 500 이하입니다.
jobs의 각 행은 하나의 작업에 대한 [작업이 요청되는 시점, 작업의 소요시간] 입니다.
각 작업에 대해 작업이 요청되는 시간은 0 이상 1,000 이하입니다.
각 작업에 대해 작업의 소요시간은 1 이상 1,000 이하입니다.
하드디스크가 작업을 수행하고 있지 않을 때에는 먼저 요청이 들어온 작업부터 처리합니다.
입출력 예
jobs	return
[[0, 3], [1, 9], [2, 6]]	9
 */




/*
 * 고민사항
 *	작업 대기 큐에 존재하는 작업의 시작시간은 고려사항에 포함되는가?
 *	X
 *	작업의 대기시간은 전체 작업 시간의 최적화에 영향을 미치지 않음.
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