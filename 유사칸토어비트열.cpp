/*
 *https://school.programmers.co.kr/learn/courses/30/lessons/148652
 *문제 설명
수학에서 칸토어 집합은 0과 1 사이의 실수로 이루어진 집합으로, [0, 1]부터 시작하여 각 구간을 3등분하여 가운데 구간을 반복적으로 제외하는 방식으로 만들어집니다.

남아는 칸토어 집합을 조금 변형하여 유사 칸토어 비트열을 만들었습니다. 유사 칸토어 비트열은 다음과 같이 정의됩니다.

0 번째 유사 칸토어 비트열은 "1" 입니다.
n(1 ≤ n) 번째 유사 칸토어 비트열은 n - 1 번째 유사 칸토어 비트열에서의 1을 11011로 치환하고 0을 00000로 치환하여 만듭니다.
남아는 n 번째 유사 칸토어 비트열에서 특정 구간 내의 1의 개수가 몇 개인지 궁금해졌습니다.
n과 1의 개수가 몇 개인지 알고 싶은 구간을 나타내는 l, r이 주어졌을 때 그 구간 내의 1의 개수를 return 하도록 solution 함수를 완성해주세요.

제한사항
1 ≤ n ≤ 20
1 ≤ l, r ≤ 5n
l ≤ r < l + 10,000,000
l과 r은 비트열에서의 인덱스(1-base)이며 폐구간 [l, r]을 나타냅니다.
입출력 예
n	l	r	result
2	4	17	8
입출력 예 설명
2 번째 유사 칸토어 비트열은 "110(11 11011 00000 11)011 11011" 입니다. 음영 표시된 부분은 폐구간 [4, 17] 이며 구간 내의 1은 8개 있습니다.
 */

#include "stdafx.h"


using KEY = tuple<int, long long, long long>;
namespace RECURSIVE
{
    using VALUE = int;
    map<KEY, VALUE> calMap;


    int solution_R(int n, long long l, long long r)
    {
        const long long WIDTH = pow(5, n);
        const long long SECTIONWIDTH = pow(5, n - 1);
        const long long SECTIONSUM = pow(4, n - 1);
    
        if(calMap.find(make_tuple(n, l, r)) != calMap.end())
    		return calMap[make_tuple(n, l, r)];
        
    
    
        // Exception
        {
            if (l < 0 || r > WIDTH || l > r)
            {
    #ifdef DEBUG_MODE
                cout << "(n, l, r) : " << n << " " << l << " " << r << endl;
                cout << "(Width, SectionWidth, SectionSum)" << WIDTH << " " << SECTIONWIDTH << " " << SECTIONSUM << endl;
            	cout << "answer : 0" << endl;
    #endif
            	return 0;
            }
            if (n == 0)
            {
    
    #ifdef DEBUG_MODE
                cout << "(n, l, r) : " << n << " " << l << " " << r << endl;
                cout << "(Width, SectionWidth, SectionSum)" << WIDTH << " " << SECTIONWIDTH << " " << SECTIONSUM << endl;
                cout << "answer : 1" << endl;
    
    #endif
                return 1;
            }
        }
    
        const long long lSection = l / SECTIONWIDTH;
        const long long lIdx = l % SECTIONWIDTH;
        const long long rSection = r / SECTIONWIDTH;
        const long long rIdx = r % SECTIONWIDTH;
        const long long lrRange = rSection - lSection + 1;
    
        const bool bHasThree = IsInRange<int>(2, lSection, rSection);
    
        int answer = (lrRange + (bHasThree && lrRange != 0 ? - 1 : 0)) * SECTIONSUM;  
    
    
    
    
        answer -= solution_R(n - 1, 0, lIdx -1);
        answer -= solution_R(n - 1, rIdx + 1, SECTIONWIDTH - 1);
    
    
    #ifdef DEBUG_MODE
    
        cout << "(n, l, r) : " << n << " " << l << " " << r << endl;
        cout << "(Width, SectionWidth, SectionSum)" << WIDTH << " " << SECTIONWIDTH << " " << SECTIONSUM << endl;
        cout << "(lSection, rSection) : " << lSection << " " << rSection << endl;
        cout << "(lIdx, rIdx) : " << lIdx << " " << rIdx << endl;
        cout << "sum : " << answer << endl << endl;
    
    #endif
    
        calMap[make_tuple(n, l, r)] = answer;
    	return answer;
    }
    
    int solution(int n, long long l, long long r) {
        
        return solution_R(n, l - 1, r - 1);
    }
}

int answer = 0;

#ifndef DEBUG_MODE
vector<thread*> threadPool;
#endif
mutex m1;
int solution(int n, long long l, long long r)
{
    function<void(int, int)> GetDigit = [&](int n, long long l)
    {
		const long long Width = pow(5, n - 1);
        if(n == 0)
        {
            m1.lock();
            answer++;
            m1.unlock();
            return;
        }
        if(n == 1)
        {
	        if(l == 2)
				return;

            m1.lock();
            answer++;
            m1.unlock();
            return;
        }

        if(l / Width == 2)
			return;
        GetDigit(n - 1, l % Width);
    };

#ifdef DEBUG_MODE
    for (long long i = l - 1; i < r; i++ )
    {
		GetDigit(n, i);	    
    }
#endif

#ifndef DEBUG_MODE
    for (long long i = l - 1; i < r; i++)
    {
    	auto locThread = new thread(GetDigit, n, i);
        threadPool.push_back(locThread);
    }



    for (auto& thread : threadPool)
    {
        if(thread->joinable())
    		thread->join();
    }
#endif
    return answer;

}

int main()
{
    using NLRR = tuple<int, long long, long long, int>;
    vector<NLRR> input =
    {
        {2, 10, 15, 1},
        {2, 4, 17, 8},
        {4, 30, 118,39},
        {3, 1, 125,64},
        {4,  27,  68, 15},
    };


    
	for (auto a : input)
	{
		auto [n, l, r, result] = a;

        auto GetResult = solution(n, l, r);
        answer = 0;
        auto str = result == GetResult ? "TRUE" : "FALSE";
        cout << "n : " << n << ", (l, r)  : (" << l << " " << r << "), Expected Result : " << result << ", Get RESULT : "<< GetResult << ", Answer : " << str << endl;
	}
}
