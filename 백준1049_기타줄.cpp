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


	int MinPackagePrice = INT32_MAX, MinSinglePirce = INT32_MAX;


	for (auto a : Cases)
	{
		if(MinPackagePrice > a.PackagePrice)
			MinPackagePrice = a.PackagePrice;

		if(MinSinglePirce > a.SinglePrice)
			MinSinglePirce = a.SinglePrice;
	}
	vector<int> prices;
	int packNum = BrokenString % 6 == 0 ? BrokenString / 6 : (BrokenString / 6) + 1;	

	prices.push_back(BrokenString * MinSinglePirce);
	prices.push_back(packNum * MinPackagePrice);

	/*int allSinglePrice = BrokenString * MinSinglePirce;
	int allPackagePrice = packNum * MinPackagePrice;*/

	
	if (BrokenString % 6 != 0)
	{
		prices.push_back(MinPackagePrice * (packNum - 1) + MinSinglePirce * (BrokenString - 6 * (packNum  - 1)));
	}


	int result = INT32_MAX;
	for (int a : prices)
	{
		if(result > a)
			result = a;
	}
	
	cout << result;	
}