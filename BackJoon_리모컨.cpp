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

	// ������� �Է� �Ϸ�.


	for (int i = 0; i < 100000; i++)
	{
		string temp = to_string(i);
		

	}



}