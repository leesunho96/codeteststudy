#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> Slave;
	int temp;
	int total = 0;
	for (int i = 0; i < 9; i++)
	{
		cin >> temp;
		Slave.push_back(temp);
		total += temp;
	}

	sort(Slave.begin(), Slave.end());

	int Size = total - 100;

	int Max = 0;
	for (Max; Max < Slave.size(); Max++)
	{
		if (Slave[Max] > Size)
		{
			break;
		}
	}

	for (size_t i = 0; i < Max; i++)
	{
		for (size_t j = i + 1; j < Max; j++)
		{
			if (Slave[i] + Slave[j] == Size)
			{
				Slave.erase(Slave.begin() + j);
				Slave.erase(Slave.begin() + i);
				for (vector<int>::iterator iter = Slave.begin(); iter != Slave.end(); iter++)
				{
					cout << *iter << endl;
				}
				return 0;
			}
		}
	}

}