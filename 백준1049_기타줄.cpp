#include "stdafx.h"


struct BrandCase
{
	int PackagePrice;
	int SinglePrice;
};

int main()
{
	int BrandNum, BrokenString;
	vector<BrandCase> Cases;

	cin >> BrokenString >> BrandNum;

	for (size_t i = 0; i < BrandNum; i++)
	{
		BrandCase temp;
		cin >> temp.PackagePrice >> temp.SinglePrice;
		Cases.emplace_back(temp);
	}
}