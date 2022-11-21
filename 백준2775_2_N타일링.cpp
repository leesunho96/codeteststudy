#include <iostream>
#include <vector>

using namespace std;



int main()
{
	vector<int> CaseByWidth;
	int Width;
	cin >> Width;

	 
	CaseByWidth.push_back(1);
	CaseByWidth.push_back(2);

	for (size_t i = 2; i < Width; i++)
	{
		CaseByWidth.push_back((CaseByWidth.at(i - 1) + CaseByWidth.at(i - 2)) % 10007);
	}



	cout << CaseByWidth.at(Width - 1);

}