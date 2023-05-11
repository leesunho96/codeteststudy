/*
 * https://school.programmers.co.kr/learn/courses/30/lessons/154539
 *
 *	������ �̷���� �迭 numbers�� �ֽ��ϴ�.�迭 �� �� ���ҵ鿡 ���� �ڽź��� �ڿ� �ִ� ���� �߿��� �ڽź��� ũ�鼭 ���� ������ �ִ� ���� �� ū����� �մϴ�.
 *	���� �迭 numbers�� �Ű������� �־��� ��, ��� ���ҿ� ���� �� ū������ ���ʷ� ���� �迭�� return �ϵ��� solution �Լ��� �ϼ����ּ���.��, �� ū���� �������� �ʴ� ���Ҵ� - 1�� ����ϴ�.
 *
 *
 *	����� ��
 numbers	result
 [2, 3, 3, 5][3, 5, 5, -1]
 [9, 1, 5, 3, 6, 2][-1, 5, 6, 6, -1, -1]
 
 *
 */


#include "stdafx.h"




/*
 * 
 *	����� ���� ����.
 *
 *	answer�� index ������ ������ ��� �Ϸ�� ����.
 *
 *	case 1 : number[i] < number[i + 1] �� ���, number[i + 1] ��ü�� ��ū��.
 *				return number[i + 1]
 *
 *	case 2: number[i] == number[i + 1]�� ���, answer[i + 1] �� ��ū��. // ������ ���̴ϱ�.
 *				return answer[i + 1]
 *
 *
 *	case 3: number[i] > number[i + 1]�� ���
 *		��찡 ��������.
 *
 *		case 3-1. ���� number[i + 1]�� -1�� ���.
 *					number[i]���ٵ� ���� ������ ��ū���� ���� : number[i]�� ��ū���� ����. *
 *						return 01
 *		case 3-2. ���� number[i]���� answer[i + 1] ū ���
 *					number[i]���� ũ�鼭, number[i + 1]���� ���� ���� �� ū�� : number[i]�� ��ū��.
 *						return number[i + 1]
 *
 *		case 3-3. �� ���� ���(number[i] ���� number[i + 1]�� �����鼭, ���ÿ� answer[i + 1]�� number[i]���� ���� ���)
 *					answer[i + 1]�� number[i + 1]��� ����� number[i]�� �� ū���� �� �� ����.
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