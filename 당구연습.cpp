// https://school.programmers.co.kr/learn/courses/30/lessons/169198



/*
 *프로그래머스의 마스코트인 머쓱이는 최근 취미로 당구를 치기 시작했습니다.

머쓱이는 손 대신 날개를 사용해야 해서 당구를 잘 못 칩니다. 하지만 끈기가 강한 머쓱이는 열심히 노력해서 당구를 잘 치려고 당구 학원에 다니고 있습니다.

오늘도 당구 학원에 나온 머쓱이에게 당구 선생님이"원쿠션"(당구에서 공을 쳐서 벽에 맞히는 걸 쿠션이라고 부르고, 벽에 한 번 맞힌 후 공에 맞히면 원쿠션이라고 부릅니다) 연습을 하라면서 당구공의 위치가 담긴 리스트를 건네줬습니다. 리스트에는 머쓱이가 맞춰야 하는 공들의 위치가 담겨있습니다. 머쓱이는 리스트에 담긴 각 위치에 순서대로 공을 놓아가며 "원쿠션" 연습을 하면 됩니다. 이때, 머쓱이는 항상 같은 위치에 공을 놓고 쳐서 리스트에 담긴 위치에 놓인 공을 맞춥니다.

머쓱이와 달리 최근 취미로 알고리즘 문제를 풀기 시작한 당신은, 머쓱이가 친 공이 각각의 목표로한 공에 맞을 때까지 최소 얼마의 거리를 굴러가야 하는지가 궁금해졌습니다.

당구대의 가로 길이 m, 세로 길이 n과 머쓱이가 쳐야 하는 공이 놓인 위치 좌표를 나타내는 두 정수 startX, startY, 그리고 매 회마다 목표로 해야하는 공들의 위치 좌표를 나타내는 정수 쌍들이 들어있는 2차원 정수배열 balls가 주어집니다. "원쿠션" 연습을 위해 머쓱이가 공을 적어도 벽에 한 번은 맞춘 후 목표 공에 맞힌다고 할 때, 각 회마다 머쓱이가 친 공이 굴러간 거리의 최솟값의 제곱을 배열에 담아 return 하도록 solution 함수를 완성해 주세요.

단, 머쓱이가 친 공이 벽에 부딪힐 때 진행 방향은 항상 입사각과 반사각이 동일하며, 만약 꼭짓점에 부딪힐 경우 진입 방향의 반대방향으로 공이 진행됩니다. 공의 크기는 무시하며, 두 공의 좌표가 정확히 일치하는 경우에만 두 공이 서로 맞았다고 판단합니다. 공이 목표 공에 맞기 전에 멈추는 경우는 없으며, 목표 공에 맞으면 바로 멈춘다고 가정합니다.


제한사항.
3 ≤ m, n ≤ 1,000
0 < startX < m
0 < startY < n
2 ≤ balls의 길이 ≤ 1,000
balls의 원소는 [get<0>(input), get<1>(input)] 형태입니다.
get<0>(input), get<1>(input)는 머쓱이가 맞춰야 할 공이 놓인 좌표를 의미합니다.
0 < get<0>(input) < m, 0 < get<1>(input) < n
(get<0>(input), get<1>(input)) = ( startX, startY )인 입력은 들어오지 않습니다.


입출력 예

m	n	startX	startY	balls	                    result
10	10	3	    7	    [[7, 7], [2, 7], [7, 3]]	[52, 37, 116]

*
 */


#include "stdafx.h"

typedef tuple<int, int, int> EQUATION;
typedef tuple<int, int> POINT;

#define XEQU0 EQUATION(1, 0, 0)
#define YEQU0 EQUATION(0, 1, 0)
#define XEQUM EQUATION(1, 0, -m)
#define YEQUN EQUATION(0, 1, -n)


#define FZEROZERO make_tuple(0.0f, 0.0f)
#define FZERON    make_tuple(0.0f, (float)n)
#define FMZERO    make_tuple((float)m, 0.0f)
#define FMN       make_tuple((float)m, (float)n)


#define ZEROZERO make_tuple(0, 0)
#define ZERON    make_tuple(0, n)
#define MZERO    make_tuple(m, 0)
#define MN       make_tuple(m, n)




int GetDistance(const EQUATION& input, const POINT& basePoint, const POINT& targetPoint)
{
    POINT symmetryPoint;
    {
        auto& [x0, y0] = targetPoint;
        auto& [a, b, c] = input;

        int x = x0 - 2 * (a * (a * x0 + b * y0 + c)) / (pow(a, 2) + pow(b, 2));
        int y = y0 - 2 * (b * (a * x0 + b * y0 + c)) / (pow(a, 2) + pow(b, 2));

        symmetryPoint = std::make_tuple(x, y);
    }

    return GetDistance(basePoint, symmetryPoint);
}


vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls)
{
    vector<int> answer;	
    POINT&& start = make_tuple(startX, startY);

    int X, Y;
    // initialize
    {
    	X = m;
        Y = n;          
    }


    for (auto ball : balls)
    {
		float&& fStartX = (float)startX;
        float&& fStartY = (float)startY;
        float&& fTargetX = (float)ball[0];
        float&& fTargetY = (float)ball[1];
        int& targetX = ball[0];
        int& targetY = ball[1];


        
        auto minVal = numeric_limits<int>::max();
        auto&& linearStartToBall = GetLinear(make_tuple(fStartX, fStartY), make_tuple(fTargetX, fTargetY));       

    // 0, 0
        {
	        if(fTargetX == fTargetY && fStartX == fStartY && fStartX < fTargetX)
				minVal = min(minVal, GetDistance(ZEROZERO, make_tuple(startX, startY))+ GetDistance(ZEROZERO, make_tuple((int)fTargetX, (int)fTargetY)));
	        
        }

    // M, 0

        {            
	        if(linearStartToBall == GetLinear(FMZERO, make_tuple(fTargetX, fTargetY)) && fStartX > fTargetX)
                minVal = min(minVal, GetDistance(MZERO, make_tuple(startX, startY)) + GetDistance(MZERO, make_tuple((int)fTargetX, (int)fTargetY)));	        
        }

    // 0, N

		{
            if (linearStartToBall == GetLinear(FZERON, make_tuple(fTargetX, fTargetY)) && fStartX < fTargetX)
                minVal = min(minVal, GetDistance(ZERON, make_tuple(startX, startY)) + GetDistance(ZERON, make_tuple((int)fTargetX, (int)fTargetY)));
		}
    // M, N
		{
            if (linearStartToBall == GetLinear(FMN, make_tuple(fTargetX, fTargetY)) && fStartX > fTargetX)
                minVal = min(minVal, GetDistance(MN, make_tuple(startX, startY)) + GetDistance(MN, make_tuple((int)fTargetX, (int)fTargetY)));
		}

    // x = 0
		{
			if(linearStartToBall.has_value())
			{
				if(!(linearStartToBall.value() == 0.0f && startX > targetX))
                    minVal = min(minVal, GetDistance(XEQU0, make_tuple(targetX, targetY), make_tuple(startX, startY)));
			}
            else
            {
                minVal = min(minVal, GetDistance(XEQU0, make_tuple(targetX, targetY), make_tuple(startX, startY)));
            }			
		}
    // x = m
        {
            if (linearStartToBall.has_value())
            {
                if (!(linearStartToBall.value() == 0.0f && startX < targetX))
					minVal = min(minVal, GetDistance(XEQUM, make_tuple(targetX, targetY), make_tuple(startX, startY)));
            }
            else
            {
                minVal = min(minVal, GetDistance(XEQUM, make_tuple(targetX, targetY), make_tuple(startX, startY)));
            }
        }


    // y = 0
        {
            if (!(!linearStartToBall.has_value() && startY > targetY))
                minVal = min(minVal, GetDistance(YEQU0, make_tuple(targetX, targetY), make_tuple(startX, startY)));
        }

    // y = n
        {
            if (!(!linearStartToBall.has_value() && startY < targetY))
                minVal = min(minVal, GetDistance(YEQUN, make_tuple(targetX, targetY), make_tuple(startX, startY)));
        }
        answer.push_back(minVal);
    }


    return answer;
}





int main()
{
	vector<vector<int>> balls = {{7, 7}, {2, 7}, {7, 3}};
    auto tempInput = make_tuple(10,	10,	3,	7);

    auto  [m, n, startX, startY] = make_tuple(10, 10, 3, 7);;

    for (auto distance : solution(m, n, startX, startY, balls))
    {
	    cout << distance << " ";
    }
    cout << endl;
}

