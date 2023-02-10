#include "stdafx.h"

const int ENDTIME = 1;
const int STARTTIME = 0;


int solution(vector<vector<string>> book_time);
int GetMinutesFromHour(const string& input);
void SetStrToInt(vector<vector<string>>& book_time, list<vector<int>>& bookTimebyMinute);
bool CompareWithBeginTime(vector<int>& a, vector<int>&b);
bool CompareWithEndTime(vector<int>& a, vector<int>& b);
void EraseVectorIngredient(list<vector<int>>& erasingVector, vector<int> removingIngredient);

void Cycle(list<vector<int>>& SortedByBeginTime, list<vector<int>>& SortedByEndTime);

list<vector<int>>::iterator GetProperReservation(list<vector<int>>& SortedByEndTime, const list<vector<int>>::iterator It, const int EndTimeOfPastReservation);

int main()
{
	vector<vector<string>> bookTime;
	string inputs[] = 
	{
		"15:00", "17:00",
		"16:40", "18:20",
		"14:20", "15:20",
		"14:10", "19:20",
		"18:20", "21:20",
	};

	for (int i = 0; i < 5; i++)
	{
		vector<string> tempvector;

		tempvector.push_back(inputs[2 * i]);
		tempvector.push_back(inputs[2 * i + 1]);

		bookTime.push_back(tempvector);
	}


	cout << solution(bookTime);
}

int solution(vector<vector<string>> book_time)
{
	list<vector<int>> bookTimebyMinute;
	list<vector<int>> bookTimebyMinute_EndTime;
	
	int result = 0;

	SetStrToInt(book_time, bookTimebyMinute);

	bookTimebyMinute_EndTime = bookTimebyMinute;


	bookTimebyMinute.sort(CompareWithBeginTime);
	bookTimebyMinute_EndTime.sort(CompareWithEndTime);

	while(!bookTimebyMinute.empty())
	{
		Cycle(bookTimebyMinute, bookTimebyMinute_EndTime);
		result++;
	}


	return result;
}

void SetStrToInt(vector<vector<string>>& book_time, list<vector<int>>& bookTimebyMinute)
{
	for (auto a : book_time)
	{
		vector<int> tempVector;
		tempVector.push_back(GetMinutesFromHour(a.at(0)));
		tempVector.push_back(GetMinutesFromHour(a.at(1)) + 10);
		bookTimebyMinute.emplace_back(tempVector);		
	}
}

int GetMinutesFromHour(const string& input)
{
	const string hours = input.substr(0, 2);
	const string minutes = input.substr(3, 2);

	return stoi(hours) * 60 + stoi(minutes);
}

bool CompareWithBeginTime(vector<int>& a, vector<int>& b)
{
	return a.at(0) < b.at(0);
}

bool CompareWithEndTime(vector<int>& a, vector<int>& b)
{
	return a.at(1) < b.at(1);
}

void Cycle(list<vector<int>>& SortedByBeginTime, list<vector<int>>& SortedByEndTime)
{
	vector<int> tempVector(2);
	tempVector = *SortedByBeginTime.begin();

	EraseVectorIngredient(SortedByBeginTime, tempVector);
	EraseVectorIngredient(SortedByEndTime, tempVector);
	list<vector<int>>::iterator it = SortedByBeginTime.begin();	

	while(true)
	{
		it = GetProperReservation(SortedByBeginTime,it, tempVector.at(ENDTIME));	

		if(it == SortedByBeginTime.end())
		{
			break;
		}
		tempVector = *it;

		EraseVectorIngredient(SortedByBeginTime, tempVector);
		EraseVectorIngredient(SortedByEndTime, tempVector);
		
	}
	cout << endl;
	
}

list<vector<int>>::iterator GetProperReservation(list<vector<int>>& SortedByBeginTime, list<vector<int>>::iterator It, const int EndTimeOfPastReservation)
{
	list<vector<int>>::iterator it = It;
	

	for (; it != SortedByBeginTime.end();)
	{
		if(it->at(STARTTIME) >= EndTimeOfPastReservation)
		{		
			return it;
		}
		else
			it++;
	}

	cout << endl;
	return SortedByBeginTime.end();
}

void EraseVectorIngredient(list<vector<int>>& erasingVector, const vector<int> removingIngredient)
{	
	list<vector<int>>::iterator it = erasingVector.begin();
	for (; it != erasingVector.end(); )
	{
		auto tempit = it;
		tempit++;

		if(*it == removingIngredient)
		{
			erasingVector.erase(it);
			break;
		}

		if(tempit == erasingVector.end())
			break;
		else
			it = tempit;	
	}
}
