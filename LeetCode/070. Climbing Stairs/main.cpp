#include <iostream>
#include <string>
#include <vector>

using namespace std;

/***

�ܽἸ�㣺
��1���������������ֵݹ��ʱ̫�����ܲ��õݹ�Ͳ��õݹ顣��ʵ����һ��쳲���������
							if (n == 1)
								return 1;
							if (n == 2)
								return 2;
							return climbStairs(n - 1) + climbStairs(n - 2);
��2��ע�������Ӧ�ü�����������ȷ�����������ѷ�����pre��cur��
��3����3��¥�ķ������� = 쳲��������е�indexΪ2�����˿ɼ����ѷ�����
***/


//�ҵķ����������벻����ࣩ
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
���Ѹ����ķ�����ֵ��ѧϰ������
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

//����2��
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