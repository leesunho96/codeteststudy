#include "stdafx.h"

const int RIPE = 1;
const int RARE = 0;
const int EMPTY = -1;


void Solution();
void Input(int& width, int& height, int box[][1001]);
bool CheckFull(const int box[][1001], const int& width, const int& height);

void Output();


int main()
{
	Solution();
}

void Solution()
{
	int M, N;
	int box[1001][1001];
	Input(N, M, box);

	

	Output();
}

void Input(int& width, int& height, int box[][1001])
{
	cin >> width >> height;

	for (int i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
		{
			static int temp;
			cin >> temp;
			box[i][j] = temp;
		}
	}
}

bool CheckFull(const int box[][1001], const int& width, const int& height)
{

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if(box[height][width] == RARE)
			{
				return false;
			}
		}
	}


	return true;
}

