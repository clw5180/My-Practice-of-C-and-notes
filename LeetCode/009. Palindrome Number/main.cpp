#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsPalindromeNumber(int num)
{
	string str = to_string(num);
	auto iter_first = str.cbegin();
	auto iter_last = str.cend() - 1;
	while (iter_last - iter_first > 0)
	{
		if (*iter_first == *iter_last)
		{
			++iter_first;
			--iter_last;
		}
		else
			return false;
	}
	return true;
}

int main()
{
	int a = 12321;
	if (IsPalindromeNumber(a))
		cout << "Is Palindrom Number!!" << endl;
	else
		cout << "Isn't Palindrom Number!!" << endl;

	return 0;
}