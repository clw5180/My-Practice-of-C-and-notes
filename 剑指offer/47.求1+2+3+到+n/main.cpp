#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Sum_Solution(int n) 
{
	if (n == 0)
		return 0;

	static int sum = 0;
	sum = Sum_Solution(n - 1) + n;
	return sum;
}


int main()
{
	cout << Sum_Solution(4);
	return 0;
}