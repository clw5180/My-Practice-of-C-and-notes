#include <iostream>
#include <string>
#include <vector>

using namespace std;

int romanToInt(string s) 
{
	int sum = 0, lastValue = -1, curValue;
	auto iter = s.end() - 1;
	while (1)
	{
		switch (*iter)
		{
		case 'I':
			curValue = 1;
			break;
		case 'V':
			curValue = 5;
			break;
		case 'X':
			curValue = 10;
			break;
		case 'L':
			curValue = 50;
			break;
		case 'C':
			curValue = 100;
			break;
		case 'D':
			curValue = 500;
			break;
		case 'M':
			curValue = 1000;
			break;
		default:
			return -1;
		}
		if (curValue >= lastValue)
			sum += curValue;
		else
			sum -= curValue;

		if (iter == s.begin())
			break;

		lastValue = curValue;
		iter--;
	}
	return sum;		
}

int main()
{
	cout << romanToInt("III") << endl;
	return 0;
}