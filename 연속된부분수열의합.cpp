/*
 *https://school.programmers.co.kr/learn/courses/30/lessons/178870
 *
 * ���� ����
�񳻸��������� ���ĵ� ������ �־��� ��, ���� ������ �����ϴ� �κ� ������ ã������ �մϴ�.

���� �������� ������ �� �ε����� ���ҿ� �� ������ ���Ҹ� ��� �����ϴ� �κ� �����̾�� �մϴ�.
�κ� ������ ���� k�Դϴ�.
���� k�� �κ� ������ ���� ���� ��� ���̰� ª�� ������ ã���ϴ�.
���̰� ª�� ������ ���� ���� ��� ����(���� �ε����� ����)�� ������ ������ ã���ϴ�.
������ ��Ÿ���� ���� �迭 sequence�� �κ� ������ ���� ��Ÿ���� ���� k�� �Ű������� �־��� ��, �� ������ �����ϴ� �κ� ������ ���� �ε����� ������ �ε����� �迭�� ��� return �ϴ� solution �Լ��� �ϼ����ּ���. �̶� ������ �ε����� 0���� �����մϴ�.

���ѻ���
5 �� sequence�� ���� �� 1,000,000
1 �� sequence�� ���� �� 1,000
sequence�� �񳻸��������� ���ĵǾ� �ֽ��ϴ�.
5 �� k �� 1,000,000,000
k�� �׻� sequence�� �κ� ������ ���� �� �ִ� ���Դϴ�.
����� ��
sequence	k	result
[1, 2, 3, 4, 5}	7	[2, 3}
[1, 1, 1, 2, 3, 4, 5}	5	[6, 6}
[2, 2, 2, 2, 2}	6	[0, 2}
����� �� ����
����� �� #1

[1, 2, 3, 4, 5}���� ���� 7�� ���ӵ� �κ� ������ [3, 4}���̹Ƿ� �ش� ������ ���� �ε����� 2�� ������ �ε��� 3�� �迭�� ��� [2, 3}�� ��ȯ�մϴ�.

����� �� #2

[1, 1, 1, 2, 3, 4, 5}���� ���� 5�� ���ӵ� �κ� ������ [1, 1, 1, 2}, [2, 3}, [5}�� �ֽ��ϴ�. �� �� [5}�� ���̰� ���� ª���Ƿ� �ش� ������ ���� �ε����� ������ �ε����� ���� [6, 6}�� ��ȯ�մϴ�.

����� �� #3

[2, 2, 2, 2, 2}���� ���� 6�� ���ӵ� �κ� ������ [2, 2, 2}�� 3���� ��찡 �ִµ�, ���̰� ª�� ������ ���� ���� ��� ���ʿ� ���� ������ ã���Ƿ� [0, 2}�� ��ȯ�մϴ�.
 */

#include "stdafx.h"


namespace TIMEOUTVERSION
{
	vector<int> solution(vector<int> sequence, int k) {
	    vector<int> answer;
		const int TARGETNUM = k;
		const int sequenceSize = sequence.size();
		int* const dpArr = new int[sequenceSize];
		int front = 0, back;

		// InitializeValues
		{
			dpArr[0] = sequence[0];	
			for (int i = 1; i < sequenceSize; i++)
			{
				dpArr[i] = dpArr[i - 1] + sequence[i];
			}

		}

		// ����ó��
		{
			for (int i = 0; i < sequenceSize; i++)
			{
				if (sequence[i] == TARGETNUM)
					return vector<int>{i, i};
			}

			for (int i = 0; i < sequenceSize; i++)
			{
				if(dpArr[i] == TARGETNUM)
					return vector<int>{0, i};			
			}

		}

		int targetRange = 0;	

		while(true)
		{		
			targetRange += 1;
			for (int i = targetRange; i < sequenceSize; i++)
			{
				int backNum = dpArr[i];
				int beginNum = dpArr[i - targetRange];

				if(backNum <= TARGETNUM)
					continue;									

				if(backNum - beginNum == TARGETNUM)
				{
					return vector<int>{i - targetRange + 1, i};
				}

			}

		}
	    return answer;
	}
}



vector<int> solution(vector<int> input, int k)
{
	vector<int> answer;
	const int INPUTLENGTH = input.size() + 1;
	int* const sum = new int[INPUTLENGTH];

	// INITIALIZE
	{
		sum[0] = input[0];
		for (size_t i = 1; i < INPUTLENGTH; i++)
		{
			sum[i] = input[i - 1] + sum[i - 1];
		}
	}

	int right = 0, left = 0;


	int cur = numeric_limits<int>::max();

	while (left <= right) {

		if (right >= INPUTLENGTH)
			break;
		
		const int particialSum = sum[right] - sum[left];

		if (particialSum == k)
		{
			if (cur > right - left) 
			{
				answer = vector<int>{left, right - 1};
				cur = right - left;
			}
			right++;
		}
		else if (particialSum < k)
			right++;		
		else
			left++;		
	}
	return answer;
}

int main()
{
	vector<tuple<vector<int>, int, vector<int>>> arr
	{
		{{1, 2, 3, 4, 5}, 7,{2, 3}},
        {{1, 1, 1, 2, 3, 4, 5},	5,{6, 6}},
        {{2, 2, 2, 2, 2},	6,{0, 2} }
	};



	for (auto& ar : arr)
	{
		auto&[input, k, result] = ar;

		auto GetResult = solution(input, k);

		string output = GetResult == result ? "TRUE" : "FALSE";

		cout << "INPUT : {" ;
		for (auto a : input)
		{
			cout << a << ", ";
		}cout << "}, OUTPUT : { " << GetResult[0] << " , " << GetResult[1] << " }, EXPECTED : { " << result[0] << " , " << result[1] << " }, RESULT :  ";

		cout << output << endl;
	}

    
}