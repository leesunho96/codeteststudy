// https://school.programmers.co.kr/learn/courses/30/lessons/148653

#include "stdafx.h"


int solution(int storey) 
{
    int answer = 0;

    while (storey != 0)
    {
        int rest = storey % 10;
        if(rest >= 6)
        {
            storey += 10 - rest;
            answer += 10 - rest;
        }
        else if (rest == 5 && (int)(storey / 10) % 10 >= 5)
        {
            storey += 10 - rest;
            answer += 10 - rest;
        }
        else
            answer += rest;

        storey /= 10;       
    }

    return answer;
}

int main()
{
    cout << solution(16) << endl;

}