#include <iostream>
#include <cmath>

using namespace std;

int reverse(int x)
{
	int result = 0;
	if (abs(x / 10) > 0)
	{
		do
		{
			result = result * 10 + x % 10;
			x = x / 10;
		} while (abs(x) >= 10);

		if (INT_MIN / 10.0 < result && result < INT_MAX / 10.0)
		{
			result = result * 10 + x % 10;
			return result;
		}
		else
			return 0;
	}
	else
	{
		return x;
	}
}

int main()
{
	//int a = (-2147483647 - 1);
	//int a = -123;
	//int a = 1;
	int a = 1463847412;
	cout << reverse(a) << endl;
	return 0;
}