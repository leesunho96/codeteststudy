#include "stdafx.h"

const int RIPE = 1;
const int RARE = 0;
const int EMPTY = -1;

int box[1001][1001];

void Solution();
void Input(int& width, int& height, queue<pair<int, int>>& ripeQueue);
int GetResult(  const int& width, const int& height, queue<pair<int, int>>& ripeQueue);
bool CheckFull(  const int& width, const int& height);
int GetRipNum(  const int& width, const int& height);
void Cycle(const int& width, const int& height, queue<pair<int, int>>& ripeQueue, int& presentRipNum);
bool SetRipe(  const int& width, const int& height);



int main()
{
	Solution();
}

void Solution()
{
	int M, N;	
	queue<pair<int, int>> ripeQueue;
	Input(M, N,ripeQueue);
	cout << GetResult(M, N, ripeQueue);
}

void Input(int& width, int& height,   queue<pair<int, int>>& ripeQueue)
{
	//cin >> width >> height;
	scanf("%d %d", &width, &height);

	for (int i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
		{
			static int temp;
			//cin >> temp;
			scanf("%d", &temp);
			box[i][j] = temp;

			if(temp == RIPE)
			{
				ripeQueue.push(make_pair(i, j));
			}
		}
	}
}

bool CheckFull(const int& width, const int& height)
{

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if(box[i][j] == RARE)
			{
				return false;
			}
		}
	}


	return true;
}

int GetResult(  const int& width, const int& height, queue<pair<int, int>>& ripeQueue)
{
	int turn = 0;
	int presentRipNum = GetRipNum(width, height);	

	while(!CheckFull(width, height))
	{
		static int tempRipNum;
		tempRipNum = presentRipNum;
		Cycle(width, height, ripeQueue, presentRipNum);
		if(presentRipNum == tempRipNum)
		{
			turn = -1;
			break;
		}
		turn++;		
	}
	return turn;
}

int GetRipNum(const int& width, const int& height)
{
	int result = 0;

	for (size_t i = 0; i < height; i++)
	{
		for (size_t j = 0; j < width; j++)
		{
			if(box[i][j] == RIPE)
				result++;
		}
	}
	return result;
}

void Cycle(const int& width, const int& height, queue<pair<int, int>>& ripeQueue, int& presentRipNum)
{	
	const int queLen = ripeQueue.size();

	for (int i = 0; i < queLen; i++)
	{
		const pair<int, int> ripe = ripeQueue.front();
		int x = ripe.second;
		int y = ripe.first;
				
		ripeQueue.pop();

		if(y - 1 >= 0)
		{
			if(SetRipe(x, y - 1))
			{
				ripeQueue.push(make_pair(y - 1, x));
				presentRipNum++;
			}
		}
		if(y + 1 < height)
		{
			if(SetRipe(x, y + 1))
			{
				ripeQueue.push(make_pair(y + 1, x));
				presentRipNum++;
			}
				
		}
		if(x - 1 >= 0)
		{
			if(SetRipe(x - 1, y))
			{
				ripeQueue.push(make_pair(y, x - 1));
				presentRipNum++;
			}
		}
		if(x + 1 < width)
		{
			if(SetRipe(x + 1, y))
			{
				ripeQueue.push(make_pair(y, x + 1));
				presentRipNum++;
			}
				
		}
	}	
}

bool SetRipe(const int& width, const int& height)
{
	if(box[height][width] == RARE)
	{
		box[height][width] = RIPE;
		return true;
	}
	return false;
}
