/*
 * https://school.programmers.co.kr/learn/courses/30/lessons/12909
 *
 *
 ��ȣ�� �ٸ��� ¦�������ٴ� ���� '(' ���ڷ� �������� �ݵ�� ¦��� ')' ���ڷ� ������ �Ѵٴ� ���Դϴ�. ���� ���

"()()" �Ǵ� "(())()" �� �ùٸ� ��ȣ�Դϴ�.
")()(" �Ǵ� "(()(" �� �ùٸ��� ���� ��ȣ�Դϴ�.
'(' �Ǵ� ')' �θ� �̷���� ���ڿ� s�� �־����� ��, ���ڿ� s�� �ùٸ� ��ȣ�̸� true�� return �ϰ�, �ùٸ��� ���� ��ȣ�̸� false�� return �ϴ� solution �Լ��� �ϼ��� �ּ���.

���ѻ���
���ڿ� s�� ���� : 100,000 ������ �ڿ���
���ڿ� s�� '(' �Ǵ� ')' �θ� �̷���� �ֽ��ϴ�.
����� ��
s	answer
"()()"	true
"(())()"	true
")()("	false
"(()("	false
����� �� ����
����� �� #1,2,3,4
������ ���ÿ� �����ϴ�.
 */

#include "stdafx.h"

bool solution(string s)
{    
    stack<char> stringStack;

    for (auto a : s)
    {
        if (a == '(')
			stringStack.push('(');

		if (a == ')')
		{
			if(stringStack.empty())
				return false;

			char& top = stringStack.top();
			if(top != '(')
				return false;
            
			stringStack.pop();
		}
    }


    return stringStack.empty();
}


int main()
{
	cout << solution(")()(");
}