#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int FirstNotRepeatingChar(string str) 
{
	if (str.empty())
		return -1;
	map<char, int> hashMap;
	int len = str.size();
	for (int i = 0; i < len; ++i)
	{
		++hashMap[str[i]];
	}
	for (int i = 0; i < len; ++i)
	{
		if (hashMap[str[i]] == 1)
			return i;
	}
	return 0;
}

int main()
{
	cout << FirstNotRepeatingChar("ababababacd");
	return 0;
}