#include "stdafx.h"

vector<vector<int>> house;
int main()
{
	int TestNum;
	cin >> TestNum;

	vector<int> floorCase;
	vector<int> houseNum;

	for (size_t i = 0; i < TestNum; i++)
	{
		static int temp1, temp2;

		cin >> temp1 >> temp2;
		floorCase.push_back(temp1);
		houseNum.push_back(temp2);
	}

	int calculateFloor = 0;
	int calculateHouseNum = 0;

	for (size_t i = 0; i < TestNum; i++)
	{
		calculateFloor = floorCase[i] > calculateFloor ? floorCase[i] : calculateFloor;
		calculateHouseNum = houseNum[i] > calculateHouseNum ? houseNum[i]: calculateHouseNum;
	}


	vector<int> tempFloor;//(calculateHouseNum, 1);

	for (size_t i = 1; i < calculateHouseNum + 1; i++)
	{
		tempFloor.push_back(i);
	}
	for (size_t i = 0; i < calculateFloor + 1; i++)
	{		
		house.push_back(tempFloor);
	}

	for (size_t i = 1; i < calculateFloor+ 1; i++)
	{
		for (size_t j = 1; j < calculateHouseNum; j++)
		{
			house[i][j] = house[i][j - 1] + house[i - 1][j];
		}
	}

	for (size_t i = 0; i < TestNum; i++)
	{
		static int floorNum, houseOrder;
		floorNum = floorCase.at(i);
		houseOrder = houseNum.at(i) - 1;
		cout << house[floorNum][houseOrder] << endl;
	}
}

