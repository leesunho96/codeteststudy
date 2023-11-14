/*
 *
 *https://school.programmers.co.kr/learn/courses/30/lessons/136797
 *
���� Ÿ�� ��ȸ
���� ����
�׸�.png
���� ���� ������� �迭�� ���� ������ �ֽ��ϴ�. ���� Ÿ�� ��ȸ�� �� ������ ������ ����Ͽ� ���ڷθ� �̷���� �� ���ڿ��� ���� ���� ������ Ÿ�����ϴ��� �ܷ�� ��ȸ�Դϴ�.

��ȸ�� �����Ϸ��� ����� �� ���� �հ����� �̿��Ͽ� Ÿ������ �մϴ�. ����� �׻� �޼� ������ 4 ����, ������ ������ 6 ���� �ΰ� Ÿ������ �����մϴ�. ���� �հ����� ������ ���� ���ڸ� ������ ������ ���� �ð��� ��ϴ�. ����� � �� ���ڸ� �������� �Է��ϴ� �ð� ����� ��� ����ġ�� �з��Ͽ����ϴ�.

�̵����� �ʰ� ���ڸ����� �ٽ� ������ ���� ����ġ�� 1�Դϴ�.
�����¿�� ������ ���ڷ� �̵��Ͽ� ������ ���� ����ġ�� 2�Դϴ�.
�밢������ ������ ���ڷ� �̵��Ͽ� ������ ���� ����ġ�� 3�Դϴ�.
���� �ʰ� �������� ���� ���ڸ� ���� ���� �� ��Ģ�� ���� ����ġ ���� �ּҰ� �Ǵ� ��θ� �����ϴ�.
���� ��� 1 ���� �ִ� �հ����� 0 ���� �̵��Ͽ� ������ ���� 2 + 2 + 3 = 7 ��ŭ�� ����ġ�� �����ϴ�.
��, ���� ������ ��ư�� ũ�Ⱑ �۱� ������ ���� ���� ��ư ���� ���ÿ� �� ���� �հ����� �÷����� �� �����ϴ�. ��, � ���ڸ� ������ �� ���ʿ� �� ���� ���� �÷��� �ִ� �հ����� �ִٸ� �ݵ�� �� �հ������� ������ �մϴ�.

���ڷ� �̷���� ���ڿ� numbers�� �־����� �� �ּ����� �ð����� Ÿ������ �ϴ� ����� ����ġ ���� return �ϵ��� solution �Լ��� �ϼ����ּ���.

���ѻ���
1 �� numbers�� ���� �� 100,000
numbers�� �ƶ��� ���ڷθ� �̷���� ���ڿ��Դϴ�.
����� ��
numbers	result
"1756"	10
"5123"	8
����� �� ����
����� �� #1
�޼� ������ 17, ������ ������ 56�� ������ ����ġ 10���� �ּ��Դϴ�.

����� �� #2
������ ������ 5, �޼� ������ 123�� �����ų� ������ ������ 5, �޼� ������ 1, ������ ������ 23�� ������ ����ġ 8�� �ּ��Դϴ�.
 
 */


#include "stdafx.h"
using HandPos = tuple<int, int>;
const int MAXNUM = 100001;
const int NOTVISITED = numeric_limits<int>::max();
array < array<array<int, 10>, 10>, MAXNUM> DP;

HandPos operator-(const HandPos& lhs, const HandPos& rhs)
{
    const auto& [lhsHeight, lhsWidth] = lhs;
    const auto& [rhsHeight, rhsWidth] = rhs;

    return HandPos(-rhsHeight + lhsHeight, -rhsWidth + lhsWidth);
}

HandPos abs( const HandPos pos)
{
    return { abs(get<0>(pos)), abs(get<1>(pos))};
}


int solution(string numbers)
{
    int answer = 0;
    const char STAR = '*';
    const char WELL = '#';



    HandPos Left{ 1, 0 }, Right{ 1, 2 };
    const int KeyBoard[4][3] {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {STAR, 0, WELL}};
    vector<HandPos> pathes;

    const map<char, HandPos> NumberToPos
	{
		{'0', {3, 1}},
        {'1', {0, 0}},
        {'2', {0, 1}},
        {'3', {0, 2}},
        {'4', {1, 0}},
        {'5', {1, 1}},
        {'6', {1, 2}},
        {'7', {2,0}},
        {'8', {2, 1}},
        {'9', {2, 2}},
        {STAR, {3, 0}},
        {WELL, {3, 2}}
	};

    {
        for (auto& v1 : DP)
        {
	        for (auto& v2 : v1)
	        {
                for (auto& v3 : v2)
                    v3 = numeric_limits<int>::max();
	        }
        }
	    for (const auto& number : numbers)
	    {
            pathes.push_back(NumberToPos.at(number));
	    }
    }

    function<int(HandPos, HandPos)> FindMinDistance = [&](HandPos from, HandPos to)
    {
		int result = 0;
        const auto&& distance = to - from;
        const auto&& absDistance = abs(distance);

        const auto& [absHeight, absWidth] = absDistance;
        const auto& [dirHeight, dirWidth] = distance;


        // ���� ���
        if (from == to)
            return 1;

        // �� �ٿ� �ִ� ���
        if (absHeight == 0 || absWidth == 0)
            return (absHeight + absWidth) * 2;

        if (absHeight == absWidth)
            return 3 * absHeight;

        return min(absHeight, absWidth) * 3 + (max(absHeight, absWidth) - min(absHeight, absWidth)) * 2;
    };

    function<int(HandPos, HandPos, int)> dp = [&](HandPos left, HandPos right, int depth)
    {
        if (depth >= pathes.size())
            return 0;

        if (left == right)
            return numeric_limits<int>::max();

        const auto& [leftHeight, leftWidth] = left;
        const auto& [rightHeight, rightWidth] = right;

        const int lNum = KeyBoard[leftHeight][leftWidth];
        const int rNum = KeyBoard[rightHeight][rightWidth];

        if (DP[depth][lNum][rNum] != NOTVISITED)
            return DP[depth][lNum][rNum];



        int lWeight = FindMinDistance(left, pathes.at(depth));
        int rWeight = FindMinDistance(right, pathes.at(depth));
       
        int lWay = lWeight + dp(pathes.at(depth), right, depth + 1);
        int rWay = rWeight + dp(left, pathes.at(depth), depth + 1);

        DP[depth][lNum][rNum] = min(lWay, rWay);


        return DP[depth][lNum][rNum];
    };

    return dp(Left, Right, 0);

}


int main()
{
    vector<tuple<string, int>> testCases
    {
        {"1756",	10},
		{"5123",	8 }
    };

    for (const auto& testCase : testCases)
    {
        auto [str, expectedResult] = testCase;

        TestFunction(solution, make_tuple(str), expectedResult);
    }
}