#include "stdafx.h"

#define LAND 1
#define SEA 0
#define VISITED 0


int Map[52][52];
int CheckMap[52][52];
vector<int> Result;
int presentWidth, presentHeight;

void ClearMap()
{
	for (int i = 0; i < 52; i++)
	{
		for (int j = 0; j < 52; j++)
		{
			Map[i][j] = 0;
			CheckMap[i][j] = 0;
		}
	}
}

void InitMap(int width, int height)
{
	static int temp;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cin >> temp;

			Map[i][j] = temp;
			CheckMap[i][j] = temp;
		}
	}
}

void Check(int XLocation, int YLocation)
{
	CheckMap[XLocation][YLocation] = VISITED;

	if(XLocation - 1 >= 0 && YLocation - 1 >= 0)
	{
		if(CheckMap[XLocation-1][YLocation-1] != VISITED && Map[XLocation - 1][YLocation - 1] == LAND)
		{
			Check(XLocation-1, YLocation-1);
		}
	}


	if (XLocation - 1 >= 0 && YLocation + 1 < presentHeight)
	{
		if (CheckMap[XLocation - 1][YLocation + 1] != VISITED && Map[XLocation - 1][YLocation + 1] == LAND)
		{
			Check(XLocation - 1, YLocation + 1);
		}
	}

	if (XLocation + 1 < presentWidth && YLocation - 1 >= 0)
	{
		if (CheckMap[XLocation + 1][YLocation - 1] != VISITED && Map[XLocation + 1][YLocation - 1] == LAND)
		{
			Check(XLocation + 1, YLocation - 1);
		}
	}

	if (XLocation + 1 < presentWidth && YLocation + 1 < presentHeight)
	{
		if (CheckMap[XLocation + 1][YLocation + 1] != VISITED && Map[XLocation + 1][YLocation + 1] == LAND)
		{
			Check(XLocation + 1, YLocation + 1);
		}
	}


	if(XLocation + 1 < presentWidth)
	{
		if(CheckMap[XLocation + 1][YLocation] != VISITED && Map[XLocation + 1][YLocation] == LAND)
		{
			Check(XLocation + 1, YLocation);
		}
	}


	if (XLocation - 1 >= 0)
	{
		if (CheckMap[XLocation - 1][YLocation] != VISITED && Map[XLocation - 1][YLocation] == LAND)
		{
			Check(XLocation - 1, YLocation);
		}
	}

	if (YLocation + 1 < presentHeight)
	{
		if (CheckMap[XLocation][YLocation + 1] != VISITED && Map[XLocation][YLocation + 1] == LAND)
		{
			Check(XLocation, YLocation + 1);
		}
	}


	if (YLocation - 1 >= 0)
	{
		if (CheckMap[XLocation][YLocation - 1] != VISITED && Map[XLocation][YLocation - 1] == LAND)
		{
			Check(XLocation, YLocation - 1);
		}
	}

}


int Solution(int Width, int Height)
{
	int Result = 0;
	presentWidth = Width;
	presentHeight = Height;

	for (int i = 0; i < Width; i++)
	{
		for (int j = 0; j < Height; j++)
		{
			if(Map[i][j] == LAND && CheckMap[i][j] != VISITED)
			{

				
				Check(i, j);
				Result++;
			}
		}
	}
	presentWidth = 0;
	presentHeight = 0;
	return Result;
}


int main()
{	
	int testCase;
	int width, height;

	while(true)
	{
		cin >> width >> height;

		if(width == 0 && height == 0)
			break;

		ClearMap();
		InitMap(width, height);

		Result.push_back(Solution(width, height));
	}


	for (const int& result : Result)
	{
		cout << result << endl;
	}

	
}