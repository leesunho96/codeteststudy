/*
 *https://school.programmers.co.kr/learn/courses/30/lessons/42628
 *
 *���� ����
���� �켱���� ť�� ���� ������ �� �� �ִ� �ڷᱸ���� ���մϴ�.

��ɾ�	���� ž(����)
I ����	ť�� �־��� ���ڸ� �����մϴ�.
D 1	ť���� �ִ��� �����մϴ�.
D -1	ť���� �ּڰ��� �����մϴ�.
���� �켱���� ť�� �� ���� operations�� �Ű������� �־��� ��, ��� ������ ó���� �� ť�� ��������� [0,0] ������� ������ [�ִ�, �ּڰ�]�� return �ϵ��� solution �Լ��� �������ּ���.

���ѻ���
operations�� ���̰� 1 �̻� 1,000,000 ������ ���ڿ� �迭�Դϴ�.
operations�� ���Ҵ� ť�� ������ ������ ��Ÿ���ϴ�.
���Ҵ� ����ɾ� �����͡� �������� �־����ϴ�.- �ִ�/�ּڰ��� �����ϴ� ���꿡�� �ִ�/�ּڰ��� �� �̻��� ���, �ϳ��� �����մϴ�.
�� ť�� �����͸� �����϶�� ������ �־��� ���, �ش� ������ �����մϴ�.
����� ��
operations	return
["I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"]	[0,0]
["I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"]	[333, -45]
����� �� ����
����� �� #1

16�� -5643�� �����մϴ�.
�ּڰ��� �����մϴ�. -5643�� �����ǰ� 16�� �����ֽ��ϴ�.
�ִ��� �����մϴ�. 16�� �����ǰ� ���� �켱���� ť�� ����ֽ��ϴ�.
�켱���� ť�� ��������Ƿ� �ִ� ���� ������ ���õ˴ϴ�.
123�� �����մϴ�.
�ּڰ��� �����մϴ�. 123�� �����ǰ� ���� �켱���� ť�� ����ֽ��ϴ�.
���� [0, 0]�� ��ȯ�մϴ�.

����� �� #2

-45�� 653�� ������ �ִ�(653)�� �����մϴ�. -45�� �����ֽ��ϴ�.
-642, 45, 97�� ���� �� �ִ�(97), �ּڰ�(-642)�� �����մϴ�. -45�� 45�� �����ֽ��ϴ�.
333�� �����մϴ�.
���� �켱���� ť�� -45, 45, 333�� ���������Ƿ�, [333, -45]�� ��ȯ�մϴ�.
 */

#include "stdafx.h"



vector<int> solution(vector<string> operations) {
    vector<int> answer = {0, 0};    
    priority_queue<int, vector<int>, less<int>> queue;

    for (auto& operation : operations)
    {
	    const auto& command = operation[0];
        string sNumber = operation.substr(2, operation.size() - 2);
        int iNumber = stoi(sNumber);


        if(command == 'I')
        {
	        queue.push(iNumber);
            continue;
        }

        if(command == 'D')
        {
            if (queue.empty())
            {
                continue;
            }

	        if(iNumber > 0)
				queue.pop();
            else
            {
             	vector<int> numbers;               

				while (queue.size() > 1)
				{
                    numbers.push_back(queue.top());
					queue.pop();
				}
                queue.pop();
                for (auto number : numbers)
                {
					queue.push(number);
                }
            }
        }
    }

    if(!queue.empty())
    {
	    answer[0] = queue.top();

        while(!queue.empty())
        {
	        answer[1] = queue.top();
            queue.pop();
        }
    }

    return answer;
}

int main()
{
//	vector<string> input = { "I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1" };
    vector<string> input = { "I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333" };
    auto result = solution(input);

    cout << result[0] << " " << result[1] << endl;

}

