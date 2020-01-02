#include <iostream>
#include <string>
#include <vector>

using namespace std;

string LeftRotateString(string str, int n) 
{
	if (str.empty() || n <= 0)
		return str;

	int len = str.size();
	while (n--)
	{
		char tmp = str[0];
		for (int i = 0; i < len - 1; ++i)
		{
			str[i] = str[i + 1];
		}
		str[len - 1] = tmp;
	}
	return str;
}

int main()
{
	LeftRotateString("abcdefg", 2);
	return 0;
}