#include <iostream>
#include <string>
#include <vector>

using namespace std;

int jumpFloor(int number) 
{
	if (number <= 0)
		return -1;
	int pre = 1, cur = 2;
	while (--number)
	{
		cur = pre + cur;
		pre = cur - pre;
	}
	return pre;
}

int main()
{
	cout << jumpFloor(1) << endl;
	return 0;
}