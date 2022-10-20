#include "stdafx.h"


int main()
{
	int Num;
	int ErrorSize;
	bool isError[10] = { true };

	cin >> Num;
	cin >> ErrorSize;

	for (int i = 0; i < ErrorSize; i++)
	{
		int temp;
		cin >> temp;
		
		isError[temp] = false;
	}

	// 여기까지 입력 완료.


	for (int i = 0; i < 100000; i++)
	{
		string temp = to_string(i);
		

	}



}