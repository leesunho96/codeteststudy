#include "stdafx.h"

typedef struct Vector3
{
	int x;
	int y;
	int z;
};

int main()
{
	int x, y, z;

	cin >> x >> y >> z;

	vector<vector<vector<int>>> inputList;

	for (size_t i = 0; i < x; i++)
	{
		for (size_t j = 0; j < y; j++)
		{
			for (size_t k = 0; k < z; k++)
			{
				int temp;
				scanf("%d", &temp);
			}
		}
	}
}