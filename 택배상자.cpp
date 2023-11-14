/*
 *https://school.programmers.co.kr/learn/courses/30/lessons/131704
 *
 *\�ù����
���� ����
����� �ù���ڸ� Ʈ���� �ƴ� ���� �մϴ�. ���簡 �Ǿ�� �ϴ� �ù���ڴ� ũ�Ⱑ ��� ������ 1�� ���ں��� n�� ���ڱ��� ��ȣ�� �����ϴ� ������� �����̳� ��Ʈ�� �Ϸķ� ���� ���翡�� ���޵˴ϴ�. �����̳� ��Ʈ�� �� �������θ� ������ �����ؼ� ��Ʈ�� ���� �������(1�� ���ں���) ���ڸ� ���� �� �ֽ��ϴ�. ������ �����̳� ��Ʈ�� ���� ������� �ù���ڸ� ���� �ٷ� Ʈ���� �ư� �Ǹ� �ù� ������ ����ϴ� ������ �ù���ڰ� �Ƿ� �ִ� ������ ���� �ʾ� ��޿� ������ ����ϴ�. ���� �ù� ������ �̸� �˷��� ������ �°� ���簡 �ù���ڸ� �Ǿ�� �մϴ�.

���� �����̳� ��Ʈ�� �� �տ� ���� ���ڰ� ���� Ʈ���� �Ǿ�� �ϴ� ������ �ƴ϶�� �� ���ڸ� Ʈ���� ���� ������ �� ������ ��� �ٸ� ���� �����ؾ� �մϴ�. ������ ���� ������ �Ժη� ���� �� �� ���� ���� �����̳� ��Ʈ�� �߰��� ��ġ�Ͽ����ϴ�. ���� �����̳� ��Ʈ�� �� �ڷ� �̵��� ���������� �Ա� �ܿ� �ٸ� ���� ���� �־ �� ���� ���ڸ� �� �� �ֽ��ϴ�(��, ���� �������� ���� �����̳� ��Ʈ�� ������ ���ں��� ������ �˴ϴ�). ���� �����̳� ��Ʈ�� �̿��ص� ������ ���ϴ� ������� ���ڸ� ���� �� �Ѵٸ�, �� �̻� ���ڸ� ���� �ʽ��ϴ�.

���� ���, ���簡 5���� ���ڸ� �Ǿ�� �ϸ�, �ù� ������ �˷��� ������ ������ �����̳� ��Ʈ�� �� ��°, �� ��°, ù ��°, �� ��°, �ټ� ��° ���� �ù���� ������ ���, ����� �켱 ù ��°, �� ��°, �� ��° ���ڸ� ���� �����̳� ��Ʈ�� �����մϴ�. �� �� �� ��° ���ڸ� Ʈ���� �ư� ���� �����̳� ��Ʈ���� �� ��° ���� ���� Ʈ�����ƽ��ϴ�. �������� ù ��° ���ڸ� �Ǿ�� ������ ���� �����̳� ��Ʈ������ �� ��° ���ڸ�, ������ �����̳� ��Ʈ���� �ټ� ��° ���ڸ� ���� �� �ֱ� ������ ���̻��� ���ڴ� ���� �� �����ϴ�. ���� Ʈ������ 2���� ���ڸ� �Ǹ��� �˴ϴ�.

�ù� ������ ���ϴ� ���� ������ ��Ÿ���� ���� �迭 order�� �־����� ��, ���簡 �� ���� ���ڸ� ���� �� �ִ��� return �ϴ� solution �Լ��� �ϼ��ϼ���.

���ѻ���
1 �� order�� ���� �� 1,000,000
order�� 1�̻� order�� ���� ������ ��� ������ �ѹ��� �����մϴ�.
order[i]�� ������ �����̳� ��Ʈ�� order[i]��° ���ڸ� i+1��°�� Ʈ���� �Ǿ�� ���� �ǹ��մϴ�.
����� ��
order	result
[4, 3, 1, 2, 5]	2
[5, 4, 3, 2, 1]	5
����� �� ����
����� �� #1

���� ���ÿ� �����ϴ�.
����� �� #2

��� ���ڸ� ���� �����̳� ��Ʈ�� ��� �ְ�, �������� �ϳ��� ���� Ʈ���� �ƽ��ϴ�.
 *
 */
#include "stdafx.h"


int solution(vector<int> order) {
    int answer = 0;
    queue<int> conv;
    stack<int> subConv;

    auto CanGetVal = [&](const int val)
    {
        if (conv.empty())
        {
            const auto& subConvT = subConv.top();

            return subConvT == val;

        }
        else if (subConv.empty())
        {
            const auto& convF = conv.front();

            return convF <= val;
        }
        else
        {
            const auto& subConvT = subConv.top();
            const auto& convF = conv.front();

            if (subConvT == val)
                return true;
            else
            {
                return convF <= val;
            }
        }
    };


    auto SetConvaierBelt = [&](const int target) mutable
    {
        if (conv.empty())
        {
            const auto& subConvT = subConv.top();

            if (subConvT == target)
                subConv.pop();
        }
        else if (subConv.empty())
        {
            const auto& convF = conv.front();

            if(convF <= target)
            {
	            while(conv.front() != target)
	            {
                    subConv.push(conv.front());
                    conv.pop();
	            }
                conv.pop();
            }
        }
        else
        {
            const auto& subConvT = subConv.top();
            const auto& convF = conv.front();

            if (subConvT == target)
            {
                subConv.pop();                
            }
            else
            {
                while (conv.front() != target)
                {
                    subConv.push(conv.front());
                    conv.pop();
                }
                conv.pop();
            }
        }
    };


    {
        for (size_t i = 1; i <= order.size(); i++)
            conv.push(i);
    }

    // MainSequence
    {
        for (const auto& ord : order)
        {
            if (!CanGetVal(ord))
                break;

            SetConvaierBelt(ord);

#ifdef DEBUG_MODE
            auto temp = conv;
            auto tempSub = subConv;

            cout << "Target : " << ord << " ";
            cout << "conv : ";
            while (!temp.empty())
            {
                cout << temp.front() << " "; temp.pop();
            }
            cout << ", subConv : ";
            while(!tempSub.empty())
            {
                cout << tempSub.top() << " ";
                tempSub.pop();
            }
            cout << endl;



#endif
            answer++;
        }
    }

    return answer;
}

int main()
{
    vector<tuple<vector<int>, int>> testCases
    {
        { {4, 3, 1, 2, 5}, 2},
		{ {5, 4, 3, 2, 1},	5 },
        {{2, 1, 4, 3, 6, 5, 8, 7, 10, 9}, 10},
        {{2, 1, 6, 7, 5, 8, 4, 9, 3, 10}, 10}
    };

    for (const auto& testCase : testCases)
    {
        const auto& [order, expectedResult] = testCase;

        TestFunction(solution, tuple<vector<int>>(order), expectedResult);
    }
}