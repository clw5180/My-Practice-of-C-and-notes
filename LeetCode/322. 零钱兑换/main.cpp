#define _CRT_SECURE_NO_WARINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


/************************************************************************/
/*  �ⷨ1���ݹ飬���¶���
	״̬ת�Ʒ��̣�F(i) = min(F(i- cj)) + 1, for j = 0,1,2, ... ,n-1
	ִ����ʱ :116 ms, ������ C++ �ύ�л�����30.23%���û�
	�ڴ����� :14.2 MB, ������ C++ �ύ�л�����11.11%���û�
/************************************************************************/
int coinChange(vector<int>& coins, int amount)
{
	if (amount <= 0)
		return 0;

	int len = coins.size();
	if (len == 0)
		return -1;

	vector<int> dp(amount+1, amount+1); // ��������amount+1�ǹؼ���ǰ����������1+����������������ı�ʾӲ�����������ֵ����ΪӲ����С����1Ԫ��������󲻿��ܳ���1*amount+1
	dp[0] = 0;

	for (int i = 1; i <= amount; ++i)  //����1,2,5��13����ôdp[0]=0...dp[1]=1...dp[2]=1
	{
		for (int j = 0; j < len; ++j)
		{
			if(i - coins[j] >= 0)
			    dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
		}
	}
	if (dp[amount] == amount + 1)
		return -1;
	else
		return dp[amount];
}

//�ⷨ2��̰��+dfs��֦����ʱ8ms
//https://leetcode-cn.com/problems/coin-change/solution/322-by-ikaruga/

void main()
{
	vector<int> coins = { 1, 2, 5 };
	cout << coinChange(coins, 13) << endl;
}