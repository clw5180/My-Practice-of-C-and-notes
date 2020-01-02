#include <iostream>
#include <string>
#include <vector>

using namespace std;

int titleToNumber(string s) 
{
	int lenStr = s.size();
	//if (lenStr == 0)
	//	return -1;
	int result = 0;

	//method 1
	//for (int i = lenStr - 1; i >= 0; --i)
	//{
	//	result += pow(26, lenStr - i - 1) * (s[i] - 'A' + 1);
	//}

	//method 2
	for (int i = 0; i < lenStr; ++i)
	{
		result = result * 26 + (s[i] - 'A' + 1);
	}
	return result;
}

int main()
{
	//string str = "ZY";
	//string str = "AAA";
	string str = "AB";
	cout << titleToNumber(str) << endl;
	return 0;
}