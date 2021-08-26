#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct names {
	int num = 0;
	string names;
};

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	int inumtype = 1;
	

	for (size_t i = 0; i < clothes.size(); i++)
	{
		swap(clothes[i][0], clothes[i][1]);
	}
	sort(clothes.begin(), clothes.end());
	names *name = new names[clothes.size()];

	name[0].names = clothes[0][0];
	name[0].num++;

	for (size_t i = 1; i < clothes.size(); i++)
	{		
		if (name[inumtype - 1].names == clothes[i][0])
		{
			name[inumtype - 1].num++;
		}
		else
		{
			name[inumtype].names = clothes[i][0];
			name[inumtype].num++;
			inumtype++;
		}		
	}


	for (size_t i = 0; i < inumtype; i++)
	{

		answer = (name[i].num + 1) * answer;
	}
	

	return answer - 1;
}



int main()
{
	//vector<vector<string>> clothes = { {"crowmask", "c"},{"bluesunglasses", "b"},{"smoky_makeup", "a"} };
	vector<vector<string>> clothes = { {"yellowhat", "headgear"},{"bluesunglasses", "eyewear"},{"green_turban", "headgear"} };
	cout << solution(clothes);
}