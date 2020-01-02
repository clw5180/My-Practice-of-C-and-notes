#include <iostream>
#include <string>
#include <vector>

using namespace std;

//我的方案1：注意这也是一种动态规划的思想！
int Fibonacci(int n) 
{
	if (n == 0)
		return 0;
	int pre = 0, cur = 1;
	for (int i = 1; i < n; ++i)
	{
		cur = pre + cur;
		pre = cur - pre;
	}
	return cur;
}

//网友方案2：c++动态规划版
/*
链接：https://www.nowcoder.com/questionTerminal/c6c7742f5ba7442aada113136ddea0c3
来源：牛客网
*/
int Fibonacci(int n)
{
	int f = 0, g = 1;
	while (n--) 
	{
		g += f;
		f = g - f;
	}
	return f;
}



int main()
{
	cout << Fibonacci(3) << endl;
	cout << Fibonacci(10) << endl;
	return 0;
}