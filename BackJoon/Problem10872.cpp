#include <iostream>

using namespace std;


int Factorial(int input)
{
	if (input == 0)
		return 1;
	else
		return input * Factorial(input - 1);
}


int main()
{
	int input;
	cin >> input;

	cout << Factorial(input);

	return 0;
}