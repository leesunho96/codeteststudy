#include <iostream>
#define FIVEMINUTE 300
#define MINUTE 60
#define SECOND 10

using namespace std;

int main()
{
	int inputTime;
	cin >> inputTime;

	int timeTable[3] = {0, 0, 0};

	timeTable[0] = inputTime / FIVEMINUTE;
	inputTime = inputTime % FIVEMINUTE;
	timeTable[1] = inputTime / MINUTE;
	inputTime = inputTime % MINUTE;
	timeTable[2] = inputTime / SECOND;
	inputTime = inputTime % SECOND;

	if(inputTime == 0)
		cout << timeTable[0] << " " << timeTable[1] << " " << timeTable[2] << endl;
	else
		cout << -1 << endl;

}