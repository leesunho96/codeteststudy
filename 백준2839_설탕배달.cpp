#include "stdafx.h"
#define FIVE 5
#define THREE 3

int main()
{
	int input;
	cin >> input;

	int max5 = input / FIVE;

	while (max5 > -1)
	{
		int temp = input - FIVE * max5;
		int Remain = temp % THREE;

		if (Remain == 0)
		{
			cout << max5 + (temp / THREE);
			return 0;
		}
		max5--;
	}

	cout << -1;
	return 0;

	
}