// https://school.programmers.co.kr/learn/courses/30/lessons/169198



/*
 *���α׷��ӽ��� ������Ʈ�� �Ӿ��̴� �ֱ� ��̷� �籸�� ġ�� �����߽��ϴ�.

�Ӿ��̴� �� ��� ������ ����ؾ� �ؼ� �籸�� �� �� Ĩ�ϴ�. ������ ���Ⱑ ���� �Ӿ��̴� ������ ����ؼ� �籸�� �� ġ���� �籸 �п��� �ٴϰ� �ֽ��ϴ�.

���õ� �籸 �п��� ���� �Ӿ��̿��� �籸 ��������"�����"(�籸���� ���� �ļ� ���� ������ �� ����̶�� �θ���, ���� �� �� ���� �� ���� ������ ������̶�� �θ��ϴ�) ������ �϶�鼭 �籸���� ��ġ�� ��� ����Ʈ�� �ǳ�����ϴ�. ����Ʈ���� �Ӿ��̰� ����� �ϴ� ������ ��ġ�� ����ֽ��ϴ�. �Ӿ��̴� ����Ʈ�� ��� �� ��ġ�� ������� ���� ���ư��� "�����" ������ �ϸ� �˴ϴ�. �̶�, �Ӿ��̴� �׻� ���� ��ġ�� ���� ���� �ļ� ����Ʈ�� ��� ��ġ�� ���� ���� ����ϴ�.

�Ӿ��̿� �޸� �ֱ� ��̷� �˰��� ������ Ǯ�� ������ �����, �Ӿ��̰� ģ ���� ������ ��ǥ���� ���� ���� ������ �ּ� ���� �Ÿ��� �������� �ϴ����� �ñ��������ϴ�.

�籸���� ���� ���� m, ���� ���� n�� �Ӿ��̰� �ľ� �ϴ� ���� ���� ��ġ ��ǥ�� ��Ÿ���� �� ���� startX, startY, �׸��� �� ȸ���� ��ǥ�� �ؾ��ϴ� ������ ��ġ ��ǥ�� ��Ÿ���� ���� �ֵ��� ����ִ� 2���� �����迭 balls�� �־����ϴ�. "�����" ������ ���� �Ӿ��̰� ���� ��� ���� �� ���� ���� �� ��ǥ ���� �����ٰ� �� ��, �� ȸ���� �Ӿ��̰� ģ ���� ������ �Ÿ��� �ּڰ��� ������ �迭�� ��� return �ϵ��� solution �Լ��� �ϼ��� �ּ���.

��, �Ӿ��̰� ģ ���� ���� �ε��� �� ���� ������ �׻� �Ի簢�� �ݻ簢�� �����ϸ�, ���� �������� �ε��� ��� ���� ������ �ݴ�������� ���� ����˴ϴ�. ���� ũ��� �����ϸ�, �� ���� ��ǥ�� ��Ȯ�� ��ġ�ϴ� ��쿡�� �� ���� ���� �¾Ҵٰ� �Ǵ��մϴ�. ���� ��ǥ ���� �±� ���� ���ߴ� ���� ������, ��ǥ ���� ������ �ٷ� ����ٰ� �����մϴ�.


���ѻ���.
3 �� m, n �� 1,000
0 < startX < m
0 < startY < n
2 �� balls�� ���� �� 1,000
balls�� ���Ҵ� [get<0>(input), get<1>(input)] �����Դϴ�.
get<0>(input), get<1>(input)�� �Ӿ��̰� ����� �� ���� ���� ��ǥ�� �ǹ��մϴ�.
0 < get<0>(input) < m, 0 < get<1>(input) < n
(get<0>(input), get<1>(input)) = ( startX, startY )�� �Է��� ������ �ʽ��ϴ�.


����� ��

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

