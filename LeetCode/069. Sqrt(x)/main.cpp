#include <iostream>
#include <string>
#include <vector>

using namespace std;

int mySqrt(int x) 
{
	long long temp = x / 2;
	int last;
	while (1)
	{
		if (temp * temp > x)
		{
			last = temp;
			temp /= 2;
		}
		else if ((temp + 1) * (temp + 1) == x)
		{
			return temp + 1;
		}
		else if (temp * temp < x && (temp + 1) * (temp + 1) > x || temp * temp == x)
		{
			return temp;
		}
		else
		{
			temp = (temp + 1 + last) / 2;
		}
	}
	return -1;
}

int main()
{
	cout << mySqrt(1) << endl;
	cout << mySqrt(2) << endl;
	cout << mySqrt(3) << endl;
	cout << mySqrt(4) << endl;
	cout << mySqrt(8) << endl;
	cout << mySqrt(9) << endl;
	cout << mySqrt(22) << endl;
	cout << mySqrt(49) << endl;
	cout << mySqrt(10000000) << endl;
	return 0;
}