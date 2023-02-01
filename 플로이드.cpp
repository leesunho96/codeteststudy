#include "stdafx.h"
const int INF = 2147483647;
void Solution();
void Input(int& BusNum, int& CitiesNum, int Cities[][101]);
void Floyd(int Cities[][101], const int& CitiesNum);
void Output(int Cities[][101], const int& CityNum);


int main()
{
	Solution();	
}

void Solution()
{
	int busNum, cityNum;
	int cities[101][101];
	Input(busNum, cityNum, cities);
	
	Floyd(cities, cityNum);
	Output(cities, cityNum);


}

void Input(int& BusNum, int& CitiesNum, int Cities[][101])
{

	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			Cities[i][j] = INF;
		}
	}

	for (int i = 0; i < 101; i++)
	{
		Cities[i][i] = 0;
	}



	cin >> CitiesNum >> BusNum;

	for (int i = 0; i < BusNum; i++)
	{
		static int from, to, cost;

		cin >> from >> to >> cost;
		if(Cities[from][to] > cost)
		{
			Cities[from][to] = cost;
		}
	}


}

void Floyd(int Cities[][101], const int& CitiesNum)
{
	for (int mid = 1; mid <= CitiesNum; mid++)
	{
		for (int from = 1; from <= CitiesNum; from++)
		{
			for (int to = 1; to <= CitiesNum; to++)
			{
				if(Cities[from][mid] != INF && Cities[mid][to] != INF)
				{
					if(Cities[from][to] > Cities[from][mid] + Cities[mid][to])
					{
						Cities[from][to] = Cities[from][mid] + Cities[mid][to];
					}
				}
			}
		}
	}
}

void Output(int Cities[][101], const int& CityNum)
{
	for (int i = 1; i <= CityNum; i++)
	{
		for (int j = 1; j <= CityNum; j++)
		{
			
			if(Cities[i][j] == INF)
			{
				cout << "0";
			}
			else
			{
				cout << Cities[i][j];
			}
			cout << " ";
		}
		cout << endl;
	}
}
