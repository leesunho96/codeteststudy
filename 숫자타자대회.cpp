/*
 *
 *https://school.programmers.co.kr/learn/courses/30/lessons/136797
 *
숫자 타자 대회
문제 설명
그림.png
위와 같은 모양으로 배열된 숫자 자판이 있습니다. 숫자 타자 대회는 이 동일한 자판을 사용하여 숫자로만 이루어진 긴 문자열을 누가 가장 빠르게 타이핑하는지 겨루는 대회입니다.

대회에 참가하려는 민희는 두 엄지 손가락을 이용하여 타이핑을 합니다. 민희는 항상 왼손 엄지를 4 위에, 오른손 엄지를 6 위에 두고 타이핑을 시작합니다. 엄지 손가락을 움직여 다음 숫자를 누르는 데에는 일정 시간이 듭니다. 민희는 어떤 두 숫자를 연속으로 입력하는 시간 비용을 몇몇 가중치로 분류하였습니다.

이동하지 않고 제자리에서 다시 누르는 것은 가중치가 1입니다.
상하좌우로 인접한 숫자로 이동하여 누르는 것은 가중치가 2입니다.
대각선으로 인접한 숫자로 이동하여 누르는 것은 가중치가 3입니다.
같지 않고 인접하지 않은 숫자를 누를 때는 위 규칙에 따라 가중치 합이 최소가 되는 경로를 따릅니다.
예를 들어 1 위에 있던 손가락을 0 으로 이동하여 누르는 것은 2 + 2 + 3 = 7 만큼의 가중치를 갖습니다.
단, 숫자 자판은 버튼의 크기가 작기 때문에 같은 숫자 버튼 위에 동시에 두 엄지 손가락을 올려놓을 수 없습니다. 즉, 어떤 숫자를 눌러야 할 차례에 그 숫자 위에 올려져 있는 손가락이 있다면 반드시 그 손가락으로 눌러야 합니다.

숫자로 이루어진 문자열 numbers가 주어졌을 때 최소한의 시간으로 타이핑을 하는 경우의 가중치 합을 return 하도록 solution 함수를 완성해주세요.

제한사항
1 ≤ numbers의 길이 ≤ 100,000
numbers는 아라비아 숫자로만 이루어진 문자열입니다.
입출력 예
numbers	result
"1756"	10
"5123"	8
입출력 예 설명
입출력 예 #1
왼손 엄지로 17, 오른손 엄지로 56을 누르면 가중치 10으로 최소입니다.

입출력 예 #2
오른손 엄지로 5, 왼손 엄지로 123을 누르거나 오른손 엄지로 5, 왼손 엄지로 1, 오른손 엄지로 23을 누르면 가중치 8로 최소입니다.
 
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


        // 같은 경우
        if (from == to)
            return 1;

        // 한 줄에 있는 경우
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