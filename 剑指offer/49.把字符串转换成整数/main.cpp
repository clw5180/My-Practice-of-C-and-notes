#include <iostream>
#include <string>
#include <vector>

using namespace std;

int StrToInt(string str) 
{
	int len = str.size();
	int result = 0;

	bool minus = false;
	if (str[0] == '-') //注意第一个字符有可能是+-号
		minus = true;

	int i = 0;
	if (str[0] == '+' || str[0] == '-') //注意第一个字符有可能是+-号
		i = 1;
	while(i < len)
	{
		//如果存在非0~9的字符，则无效
		if (str[i] - '0' < 0 || str[i] - '0' > 9) 
			return 0;
		result = result * 10 + (str[i] - '0');
		++i;
	}
	if (minus)
		result *= -1;
	return result;
}

int main()
{
	cout << StrToInt("12345") << endl;
	cout << StrToInt("-12345") << endl;
	cout << StrToInt("") << endl;
	return 0;
}