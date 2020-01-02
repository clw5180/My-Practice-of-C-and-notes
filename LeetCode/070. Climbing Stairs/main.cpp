#include <iostream>
#include <string>
#include <vector>

using namespace std;

/***

总结几点：
（1）类似于下面这种递归耗时太长！能不用递归就不用递归。其实就是一个斐波那契数列
							if (n == 1)
								return 1;
							if (n == 2)
								return 2;
							return climbStairs(n - 1) + climbStairs(n - 2);
（2）注意变量名应该简洁而且意义明确，如下面网友方案的pre和cur。
（3）爬3层楼的方案总数 = 斐波那契数列的index为2的项；因此可见网友方案：
***/


//我的方案：（代码不够简洁）
int climbStairs(int n) 
{
	if (n == 1)
		return 1;
	int a = 1;
	int b = 2;
	int an = 2;
	for (int i = 2; i < n; ++i)
	{
		an = a + b;
		a = b;
		b = an;
	}
	return an;
}

/***
网友更简洁的方案（值得学习！）：
int climbStairs(int n)
{
	int cur = 1, pre = 0;
	for (int i = 0; i < n; i++)
	{
		cur = pre + cur;
		pre = cur - pre;
	}
	return cur;
}

//网友2：
int climbStairs(int n) 
{
	// dp[n] = dp[n - 1] + dp[n - 2]
	//          1 steps     2 steps

	if (n == 1)
		return 1;
	if (n < 1)
		return 0;

	int dp[n];
	dp[0] = 1;
	dp[1] = 2;

	for (auto i = 2; i < n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	return dp[n - 1];
}
***/


int main()
{
	cout << climbStairs(5) << endl;
	return 0;
}