#include "stdafx.h"

int main()
{

	int A, B, C;
	int result;

	cin >> A >> B >> C;
	if ((C - B) <= 0)
		result = -1;
	else
		result = (A / (C - B)) + 1;

	cout << result;
	return 0;
}