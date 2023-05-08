#include "stdafx.h"

#define START 'S'
#define EXIT 'E'
#define LAVER 'L'
#define PATH 'O'
#define WALL 'X'

struct POINT
{
public:
	int x;
	int y;

public:
	POINT() : x(0), y(0) {};
	POINT(int x, int y) : x(x), y(y) {};



	POINT operator+ (const POINT& rhs) const
	{
		return POINT(x + rhs.x, y + rhs.y);
	};

	bool operator== (const POINT& rhs) const
	{
		return this->x == rhs.x && this->y == rhs.y;
	};

};

const POINT Pathes[4] = {POINT(1, 0), POINT(-1, 0), POINT(0, 1), POINT(0, -1)};


bool IsAvailablePath(const POINT& point, int width, int height, const vector<string>& maps)
{
	if(point.x >= 0 && point.x < width && point.y >= 0 && point.y < height)
	{
		if(maps[point.x][point.y] != WALL)
			return true;
	}
	return false;
}


int bfs(POINT start, POINT end, vector<string>& maps)
{
	bool visited[100][100] = {{false, }, };
	int weights[100][100] = {{0, },};
	const int width = maps[0].size();
	const int height = maps.size();

	queue<POINT> q;

	q.push(start);
	visited[start.x][start.y] = true;

	while(!q.empty())
	{
		POINT top = q.front();

		if(top == end)
		{
			return weights[top.x][top.y];
		}

		q.pop();
		for(auto a : Pathes)
		{
			POINT newWay = a + top;
			if(IsAvailablePath(newWay, width, height, maps))
			{
				if(!visited[newWay.x][newWay.y])
				{
					q.push(newWay);
					visited[newWay.x][newWay.y] = true;
					weights[newWay.x][newWay.y] = weights[top.x][top.y] + 1;
				}
			}
		}		
	}

	return int_max;
}

int solution(vector<string> maps)
{
	int result = 0;
	const int width = maps[0].size();
	const int height = maps.size();

	POINT start;
	POINT end;
	POINT laber;


	// INITIALIZE POINT
	{
	// height
	for (int i = 0; i < maps.size(); i++)
	{
		// width
		for (int j = 0; j < maps[i].size(); j++)
		{
			if(maps[j][i] == START)
			{
				start = POINT(j, i);
			}
			else if(maps[j][i] == EXIT)
			{
				end = POINT(j, i);
			}
			else if(maps[j][i] == LAVER)
			{
				laber = POINT(j, i);
			}
		}
	}
	}



	int startToLaber = bfs(start, laber, maps);
	int laberToExit = bfs(laber, end, maps);

	return startToLaber == int_max || laberToExit == int_max ? -1 : startToLaber + laberToExit;
}

int main()
{
    vector<string> map;

    string input[] ={ "SOOOL","XXXXO","OOOOO","OXXXX","OOOOE" }; //{ "LOOXS","OOOOX","OOOOO","OOOOO","EOOOO" };

    for (auto a : input)
    {
	    map.push_back(a);
    }

	cout << solution(map);
}
