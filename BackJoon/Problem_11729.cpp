#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

void Move(int from, int to)
{
	printf("%d %d\n", from, to);
	//cout << from << " " << to << endl;
}

void Hanoi(int Num, int start, int end, int sub)
{
	if (Num == 1)
	{
		Move(start, end);
		return;
	}
	else
	{
		Hanoi(Num - 1, start, sub, end);
		Move(start, end);
		Hanoi(Num - 1, sub, end, start);
	}
}

int main()
{
	int input;
	cin >> input;
	cout <<(pow(2, input)) - 1 << endl;

	Hanoi(input, 1, 3, 2);

	return 0;
}