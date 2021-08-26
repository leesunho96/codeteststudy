#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book)
{
	sort(phone_book.begin(), phone_book.end());
	for (size_t i = 0; i < phone_book.size() - 1; i++)
	{
		if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].length()))
			return false;
	}
	return true;
}

// true = 1, false = 0

int main()
{
	vector<string> inputdata = { "12","123","1235","567","88" };

	bool result = solution(inputdata);
	cout << result;

}