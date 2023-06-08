/*
 *https://school.programmers.co.kr/learn/courses/30/lessons/161988
 *
 *���� �޽� �κ� ������ ��
���� ����
� ������ ���� �κ� ������ ���� ������ �޽� ������ �� ���ҳ��� ���Ͽ� ���� �޽� �κ� ������ ����� �մϴ�. �޽� �����̶� [1, -1, 1, -1 ��] �Ǵ� [-1, 1, -1, 1 ��] �� ���� 1 �Ǵ� -1�� �����ϸ鼭 1�� -1�� ������ ������ �����Դϴ�.
���� ��� ���� [2, 3, -6, 1, 3, -1, 2, 4]�� ���� �κ� ���� [3, -6, 1]�� �޽� ���� [1, -1, 1]�� ���ϸ� ���� �޽� �κм����� [3, 6, 1]�� �˴ϴ�. �� �ٸ� ���÷� ���� �κ� ���� [3, -1, 2, 4]�� �޽� ���� [-1, 1, -1, 1]�� ���ϸ� ���� �޽� �κм����� [-3, -1, -2, 4]�� �˴ϴ�.
���� ���� sequence�� �Ű������� �־��� ��, ���� �޽� �κ� ������ �� �� ���� ū ���� return �ϵ��� solution �Լ��� �ϼ����ּ���.

���� ����
1 �� sequence�� ���� �� 500,000
-100,000 �� sequence�� ���� �� 100,000
sequence�� ���Ҵ� �����Դϴ�.
����� ��
sequence	result
[2, 3, -6, 1, 3, -1, 2, 4]	10
����� �� ����
�־��� ������ ���� �κ� ���� [3, -6, 1]�� �޽� ���� [1, -1, 1]�� ���Ͽ� ���� �޽� �κ� ���� [3, 6, 1]�� ���� �� �ְ� �� ���� 10���μ� ���� Ů�ϴ�.
 *
 */
#include "stdafx.h"


long long solution(vector<int> sequence)
{	
	for (int i = 0; i < sequence.size(); i += 2)
	{
		sequence[i] = -sequence[i];
	}

	vector<long long> sum(sequence.size());
	set<long long> sumSet;
	sum[0] = sequence[0];
	sumSet.insert(sum[0]);
	for (int i = 1; i < sequence.size(); i++)
	{
		sum[i] = sum[i - 1] + sequence[i];
		sumSet.insert(sum[i]);
	}


	
	auto minVal = *sumSet.begin();
	auto maxVal = *sumSet.rbegin();


	set<long long> answerList;

	answerList.insert(minVal);
	answerList.insert(-minVal);
	answerList.insert(maxVal);
	answerList.insert(-maxVal);

	answerList.insert(maxVal - minVal);
	answerList.insert(-(maxVal - minVal));	

	return *answerList.rbegin();

}




int main()
{
	vector<int> sequence { 2, 3, -6, 1, 3, -1, 2, 4 };

	cout << solution(sequence);
}