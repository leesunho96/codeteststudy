#include "stdafx.h"

int getNum(char input)
{
	int up = input - 'A';
	int down = 26 + 'A' - input;
	if (up > down)
	{
		return down;
	}
	else
	{
		return up;
	}
}

int solution(string name) {
	int answer = 0;
	string sright(name.size(), 'A');

	if (name == sright)
		return 0;

	// A B C D E F G H I J K L M
	// Z Y X W V U T S R Q P O N
	int temp1 = getNum(name[0]); // 오른쪽으로 진행시 경우의 수
	int temp2 = getNum(name[0]); // 왼쪽으로 진행시 경우의 수
	sright[0] = name[0];
	string sleft(sright);

	int index = 1;
	while (name != sright)
	{
		temp1 += getNum(name[index]);
		sright[index] = name[index];
		index++;
		temp1++;
	}


	index = name.size() - 1;

	while ( name != sleft)
	{
		temp2 += getNum(name[index]);
		sleft[index] = name[index];
		index--;
		temp2++;
	}


	answer = min(temp1, temp2);


	return answer;
}



int main()
{
	string sinput = "JEROEN";
	cout << solution(sinput);

};