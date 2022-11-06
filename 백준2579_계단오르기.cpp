#include<iostream>

#define endl "\n"
#define MAX 301
using namespace std;

int N;
int Arr[MAX];    // ����� ��Ÿ���� �迭
int DP[MAX];    // �ش� ��ܱ����� Max���� ��Ÿ���� �迭

int Max(int A, int B) { if (A > B) return A; return B; }

void Input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> Arr[i];
	}
}

void Solution()
{
	DP[1] = Arr[1];    // ù ��° ��ܱ����� Max ���� ù��° ��� ������
	DP[2] = Arr[1] + Arr[2];
	DP[3] = Max(Arr[1] + Arr[3], Arr[2] + Arr[3]);

	for (int i = 4; i <= N; i++)
	{
		DP[i] = Max(DP[i - 2] + Arr[i], DP[i - 3] + Arr[i - 1] + Arr[i]);
	}

	cout << DP[N] << endl;
}

void Solve()
{
	Input();
	Solution();
}

int main(void)
{
	Solve();
	return 0;
}