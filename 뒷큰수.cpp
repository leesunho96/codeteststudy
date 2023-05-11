/*
 * https://school.programmers.co.kr/learn/courses/30/lessons/154539
 *
 *	정수로 이루어진 배열 numbers가 있습니다.배열 의 각 원소들에 대해 자신보다 뒤에 있는 숫자 중에서 자신보다 크면서 가장 가까이 있는 수를 뒷 큰수라고 합니다.
 *	정수 배열 numbers가 매개변수로 주어질 때, 모든 원소에 대한 뒷 큰수들을 차례로 담은 배열을 return 하도록 solution 함수를 완성해주세요.단, 뒷 큰수가 존재하지 않는 원소는 - 1을 담습니다.
 *
 *
 *	입출력 예
 numbers	result
 [2, 3, 3, 5][3, 5, 5, -1]
 [9, 1, 5, 3, 6, 2][-1, 5, 6, 6, -1, -1]
 
 *
 */


#include "stdafx.h"




/*
 * 
 *	경우의 수를 나눔.
 *
 *	answer의 index 이후의 값들은 계산 완료된 값들.
 *
 *	case 1 : number[i] < number[i + 1] 인 경우, number[i + 1] 자체가 뒷큰수.
 *				return number[i + 1]
 *
 *	case 2: number[i] == number[i + 1]인 경우, answer[i + 1] 이 뒷큰수. // 동일한 값이니까.
 *				return answer[i + 1]
 *
 *
 *	case 3: number[i] > number[i + 1]인 경우
 *		경우가 복잡해짐.
 *
 *		case 3-1. 만약 number[i + 1]이 -1인 경우.
 *					number[i]보다도 값이 작은데 뒷큰수가 없다 : number[i]도 뒷큰수가 없다. *
 *						return 01
 *		case 3-2. 만약 number[i]보다 answer[i + 1] 큰 경우
 *					number[i]보다 크면서, number[i + 1]보다 작은 수의 뒷 큰수 : number[i]의 뒷큰수.
 *						return number[i + 1]
 *
 *		case 3-3. 그 외의 경우(number[i] 보다 number[i + 1]이 작으면서, 동시에 answer[i + 1]이 number[i]보다 작은 경우)
 *					answer[i + 1]과 number[i + 1]모두 절대로 number[i]의 뒷 큰수가 될 수 없다.
 *						answer[i + 1] < number[i] && number[i + 1] < number[i];
 *						-> continue;
 *
 *
 *
 *
 *
 */
namespace DP_V{
int DP(vector<int>& numbers, vector<int>& answer, int index)
{
	for (int pastIt = index + 1; pastIt < answer.size(); ++pastIt)
	{
		if(numbers.at(index) < numbers.at(pastIt))
			return numbers.at(pastIt);

		else if(numbers.at(index) == numbers.at(pastIt) )
			return answer.at(pastIt);

		else
		{
			if(numbers.at(index) < answer.at(pastIt))
				return answer.at(pastIt);
			else if(answer.at(pastIt) == -1)
				return -1;
			else
				continue;
		}
	}


	return -1;	
}



vector<int> solution(vector<int> numbers)
{
	vector<int> answer(numbers.size(), -1);
	set<int> values;

	const int numberSize = numbers.size();


	for (int i = numbers.size() - 1; i >= 0; i--)
	{
		answer.at(i) = DP(numbers, answer, i);
	}

	return answer;
}

}


namespace Stack_V{

int GetBackBigNum(const vector<int>& numbers, stack<int>& savedStack, int index)
{
	
}

vector<int> solution(vector<int> numbers)
{
	vector<int> answer(numbers.size(), -1);
	stack<int> temp;


	

	return answer;
}
}
int main()
{
	//vector<int> input{ 10, 1, 10, 2, 10, 3, 10, 10, 10, 11, 11, 11, 12 };
	vector<int> input{ 2, 3, 3, 5 };
	vector<int> output(std::move(DP_V::solution(input)));

	for (auto val : output)
	{
		cout << val << " ";
	}

	cout << endl;
}