#include <iostream>
using namespace std;

int main()
{
	unsigned long long int arr[91];


	int n;
	cin >> n;
	arr[0] = 0;
	arr[1] = 1;

	for (size_t i = 2; i <= n; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	cout << arr[n];
}