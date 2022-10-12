#include "stdafx.h"


int mNum = 0;
int zNum = 0;
int pNum = 0;


void AddNum(int input)
{
	switch (input)
	{
	case -1:
		mNum++;
		break;
	case 0:
		zNum++;
		break;
	case 1:
		pNum++;
		break;
	}
}


void GetPaperNum(int** arr, int widthFrom, int widthTo, int heightFrom, int heightTo)
{
	
	int result = arr[widthFrom][heightFrom];
	int width = (widthTo - widthFrom) / 3;
	int height = (heightTo - heightFrom) / 3;



	for (int i = widthFrom; i < widthTo; i++)
	{
		for (int j = heightFrom; j < heightTo; j++)
		{
			if (arr[i][j] != result)
			{
				GetPaperNum(arr, widthFrom, widthFrom + width, heightFrom, heightFrom + height);
				GetPaperNum(arr, widthFrom + width, widthFrom + width * 2, heightFrom, heightFrom + height);
				GetPaperNum(arr, widthFrom + width * 2, widthFrom + width * 3, heightFrom, heightFrom + height);


				GetPaperNum(arr, widthFrom, widthFrom + width, heightFrom + height, heightFrom + height * 2);
				GetPaperNum(arr, widthFrom + width, widthFrom + width * 2, heightFrom + height, heightFrom + height * 2);
				GetPaperNum(arr, widthFrom + width * 2, widthFrom + width * 3, heightFrom + height, heightFrom + height * 2);



				GetPaperNum(arr, widthFrom, widthFrom + width, heightFrom + height * 2, heightFrom + height * 3);
				GetPaperNum(arr, widthFrom + width, widthFrom + width * 2, heightFrom + height * 2, heightFrom + height * 3);
				GetPaperNum(arr, widthFrom + width * 2, widthFrom + width * 3, heightFrom + height * 2, heightFrom + height * 3);


				return;
			}
		}
	}
	AddNum(arr[widthFrom][heightFrom]);
}


void main()
{
	int arrWidth;
	int** arr;

	scanf_s("%d", &arrWidth);
	arr = (int**)malloc(sizeof(int*) * arrWidth);

	for (int i = 0; i < arrWidth; i++)
	{
		arr[i] = (int*)malloc(sizeof(int) * arrWidth);
	}

	for (int i = 0; i < arrWidth; i++)
	{
		for (int j = 0; j < arrWidth; j++)
		{
			scanf_s("%d", &arr[i][j]);
		}
	}
	




		/*int arr[][9] =
		{
			{0,  0,  0,  1,  1,  1, -1, -1, -1},
			{0,  0,  0,  1,  1,  1, -1, -1, -1},
			{0,  0,  0,  1,  1,  1, -1, -1, -1},
			{1,  1,  1,  0,  0,  0,  0,  0,  0},
			{1,  1,  1,  0,  0,  0,  0,  0,  0},
			{1,  1,  1,  0,  0,  0,  0,  0,  0},
			{0,  1, -1,  0,  1, -1,  0,  1, -1},
			{0, -1,  1,  0,  1, -1,  0,  1, -1},
			{0,  1, -1,  1,  0, -1,  0,  1, -1}
		};*/


	GetPaperNum(arr, 0, arrWidth, 0, arrWidth);

	cout << mNum << endl;
	cout << zNum << endl;
	cout << pNum << endl;
	

}