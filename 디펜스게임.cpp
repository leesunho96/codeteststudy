/*
 *https://school.programmers.co.kr/learn/courses/30/lessons/142085
 *
 *���潺 ����
���� ����
��ȣ�� ���� ���潺 ���ӿ� ǫ ���� �ֽ��ϴ�. ���潺 ������ ��ȣ�� ������ ���� n������ ���ӵǴ� ���� ������ ������� ���� �����Դϴ�. ���潺 ������ ������ ���� ��Ģ���� ����˴ϴ�.

��ȣ�� ó���� ���� n���� ������ �ֽ��ϴ�.
�� ���帶�� enemy[i]������ ���� �����մϴ�.
���� ���� �� enemy[i]�� ��ŭ �Ҹ��Ͽ� enemy[i]������ ���� ���� �� �ֽ��ϴ�.
���� ��� ���� ���簡 7���̰�, ���� ���� 2������ ���, ���� ���带 ������ 7 - 2 = 5���� ���簡 �����ϴ�.
���� ������ ������ ���� ������ ���� ���� �� ������ ������ ����˴ϴ�.
���ӿ��� �������̶�� ��ų�� ������, �������� ����ϸ� ������ �Ҹ���� �� ������ ������ ���� �� �ֽ��ϴ�.
�������� �ִ� k�� ����� �� �ֽ��ϴ�.
��ȣ�� �������� ������ �ñ⿡ ����Ͽ� �ִ��� ���� ���带 �����ϰ� �ͽ��ϴ�.

��ȣ�� ó�� ������ �ִ� ������ �� n, ��� ������ �������� Ƚ�� k, �� ���帶�� �����ؿ��� ���� ���� ������� ��� ���� �迭 enemy�� �Ű������� �־����ϴ�. ��ȣ�� �� ������� ���� �� �ִ��� return �ϵ��� solution �Լ��� �ϼ����ּ���.

���ѻ���
1 �� n �� 1,000,000,000
1 �� k �� 500,000
1 �� enemy�� ���� �� 1,000,000
1 �� enemy[i] �� 1,000,000
enemy[i]���� i + 1 ���忡�� �����ؿ��� ���� ���� ����ֽ��ϴ�.
��� ���带 ���� �� �ִ� ��쿡�� enemy[i]�� ���̸� return ���ּ���.
����� ��
n	k	enemy	result
7	3	[4, 2, 4, 5, 3, 3, 1]	5
2	4	[3, 3, 3, 3]	4
����� �� ����
����� ��#1

1, 3, 5 ������ ������ ���������� ���Ƴ���, 2, 4 ���忡 ���� ���縦 2��, 5�� �Ҹ��ϸ� 5������� ������ ���� �� �ֽ��ϴ�. ��, 1, 3, 4��° ������ ���������� ���Ƴ���, 2, 5 ��° ���ݿ� ���� ���縦 2��, 3�� �Ҹ��Ͽ� 5������� ������ ���� �� �ֽ��ϴ�. �׺��� ���� ���带 ���� ����� �����Ƿ� 5�� return �մϴ�.
����� ��#2

��ȣ�� ��� ���ݿ� �������� ����Ͽ� 4������� ���� �� �ֽ��ϴ�.
 *
 *
 */
#include "stdafx.h"



// multiset �̿��Ͽ� �ð��ʰ� �߻��ϴµ�.
namespace USEMULTISET
{

int solution(int n, int k, vector<int> enemy)
{
	int& mySoldiers = n;
    int& infinity = k;
    const int maxRound = enemy.size();


    // ����ó��
    {
		if(maxRound <= infinity)
			return maxRound;
    }
    using ii = tuple<int, int>;

    vector<multiset<int>> maxEnemySet(enemy.size());
    vector<long long> sums(enemy.size());


    // ������ �ʱ�ȭ.
    {
	    maxEnemySet[0] = {enemy[0]};
	    sums[0] = enemy[0];

	    for (int i = 1; i < maxRound; i++)
	    {
	        // max cases
			{
				const auto& pastSet = maxEnemySet[i - 1];
		        auto& presentSet = maxEnemySet[i];

		        presentSet = pastSet;

                presentSet.insert(enemy[i]);

                if(presentSet.size() > infinity)
					presentSet.erase(presentSet.begin());
			}

	        // max cases sum
			{
	            sums[i] = sums[i - 1] + enemy[i];
			}
	    }
    }


    for (int i = maxRound - 1; i >= 0; i--)
    {
	    const auto& presentSum = sums[i];
        const auto& presentMaxSet = maxEnemySet[i];
        
        int sum = 0;

        for (auto val : presentMaxSet)
			sum += val;

        if(presentSum - sum <= mySoldiers)
			return i + 1;
    }

    static_assert(true, "Not Exist");
 }

 }



int solution(int n, int k, vector<int> enemy)
{
	priority_queue<int, vector<int>, greater<int>> pq;

    const int maxRound = enemy.size();
    int& mySoldiers = n;
    int& infinityNum = k;
    int infSum = 0;
    int sum = 0;


    for (size_t i = 0; i < maxRound; i++)
    {
        sum += enemy[i];

        if(i < infinityNum)
        {        
	        infSum += enemy[i];
            pq.push(enemy[i]);
            continue;
        }

        auto thisRoundEnemyNum = enemy[i];        
        auto infMin = pq.top();
        

        if(thisRoundEnemyNum > infMin)
        {
	        infSum += thisRoundEnemyNum;
            infSum -= infMin;
            pq.pop();
            pq.push(thisRoundEnemyNum);
        }

        if(mySoldiers < sum - infSum)
			return i;		
    }

    return maxRound;
}
int Add(int a, int b)
{
    return a + b;
}


int main()
{
    using TUPLE = tuple<int, int, vector<int>, int>;

    vector<TUPLE> testCases
    {
       { 7, 3, vector<int>{4, 2, 4, 5, 3, 3, 1},	5},
       { 2, 4, vector<int>{3, 3, 3, 3}, 4}
    };

    for (auto testCase : testCases)
    {
        auto [n, k, enemy, result] = testCase;
        auto tp = make_tuple(n, k, enemy);
        
        TestFunction(solution, tp, result);        
    }

}
