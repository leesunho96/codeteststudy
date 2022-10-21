#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
int way[100][100] = 
{ 
	INT32_MAX,
};

void Initialize(int* PeopleNum, int* relationshipNum)
{
	cin >> *PeopleNum;
	cin >> *relationshipNum;

	for (size_t i = 0; i < *PeopleNum; i++)
	{
		for (size_t j = 0; j < *PeopleNum; j++)
		{
			way[i][j] = INT_MAX;
		}
	}


	for (int i = 0; i < *relationshipNum; i++)
	{
		pair<int, int> temp;
		cin >> temp.first >> temp.second;

		way[temp.first][temp.second] = 1;
		way[temp.second][temp.first] = 1;		
	}

	for (size_t i = 0; i < 10; i++)
	{
		printf("%.10d, %.10d, %.10d, %.10d, %.10d, %.10d, %.10d, %.10d, %.10d, %.10d", way[i][0], way[i][1], way[i][2], way[i][3], way[i][4], way[i][5], )
	}

}


void Floyd(int PeopleNum)
{
	for (int m = 1; m <= PeopleNum; m++) //��� ���
		for (int s = 1; s <= PeopleNum; s++) //���� ���
			for (int e = 1; e <= PeopleNum; e++) //������ ���
				if (way[s][e] > way[s][m] + way[m][e])
					way[s][e] = way[s][m] + way[m][e]; //����� ���İ��� ���� �� ������ �װɷ� ������Ʈ�Ѵ�.
}
vector<pair<int, int>> RelationShip;


int main()
{

	int PeopleNum;
	int relationshipNum;
	
	
	Initialize(&PeopleNum, &relationshipNum);
	Floyd(PeopleNum);

	for (size_t i = 0; i < 10; i++)
	{

		for (size_t j = 0; j < 10; j++)
		{
			cout << way[i][j] << "  ";
		}
		cout << endl;
	}


}
