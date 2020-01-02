#include <iostream>
#include <string>
#include <vector>

using namespace std;

int NumberOf1Between1AndN_Solution(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; ++i)
	{
		int remainder = 0;
		int num = i;
		while (num)
		{
			remainder = num % 10;
			num /= 10;
			if (remainder == 1)
				++sum;
		}
	}
	return sum;
}

int main()
{
	//cout << NumberOf1Between1AndN_Solution(10) << endl;
	cout << NumberOf1Between1AndN_Solution(100) << endl;
	return 0;
}