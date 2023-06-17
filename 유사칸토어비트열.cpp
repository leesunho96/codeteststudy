/*
 *https://school.programmers.co.kr/learn/courses/30/lessons/148652
 *���� ����
���п��� ĭ��� ������ 0�� 1 ������ �Ǽ��� �̷���� ��������, [0, 1]���� �����Ͽ� �� ������ 3����Ͽ� ��� ������ �ݺ������� �����ϴ� ������� ��������ϴ�.

���ƴ� ĭ��� ������ ���� �����Ͽ� ���� ĭ��� ��Ʈ���� ��������ϴ�. ���� ĭ��� ��Ʈ���� ������ ���� ���ǵ˴ϴ�.

0 ��° ���� ĭ��� ��Ʈ���� "1" �Դϴ�.
n(1 �� n) ��° ���� ĭ��� ��Ʈ���� n - 1 ��° ���� ĭ��� ��Ʈ�������� 1�� 11011�� ġȯ�ϰ� 0�� 00000�� ġȯ�Ͽ� ����ϴ�.
���ƴ� n ��° ���� ĭ��� ��Ʈ������ Ư�� ���� ���� 1�� ������ �� ������ �ñ��������ϴ�.
n�� 1�� ������ �� ������ �˰� ���� ������ ��Ÿ���� l, r�� �־����� �� �� ���� ���� 1�� ������ return �ϵ��� solution �Լ��� �ϼ����ּ���.

���ѻ���
1 �� n �� 20
1 �� l, r �� 5n
l �� r < l + 10,000,000
l�� r�� ��Ʈ�������� �ε���(1-base)�̸� �󱸰� [l, r]�� ��Ÿ���ϴ�.
����� ��
n	l	r	result
2	4	17	8
����� �� ����
2 ��° ���� ĭ��� ��Ʈ���� "110(11 11011 00000 11)011 11011" �Դϴ�. ���� ǥ�õ� �κ��� �󱸰� [4, 17] �̸� ���� ���� 1�� 8�� �ֽ��ϴ�.
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
