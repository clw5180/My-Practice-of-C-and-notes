#define _CRT_SECURE_NO_WARINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


/************************************************************************/
/*  解法1：递归，自下而上
	状态转移方程：F(i) = min(F(i- cj)) + 1, for j = 0,1,2, ... ,n-1
	执行用时 :116 ms, 在所有 C++ 提交中击败了30.23%的用户
	内存消耗 :14.2 MB, 在所有 C++ 提交中击败了11.11%的用户
/************************************************************************/
int coinChange(vector<int>& coins, int amount)
{
	if (amount <= 0)
		return 0;

	int len = coins.size();
	if (len == 0)
		return -1;

	vector<int> dp(amount+1, amount+1); // 这里两个amount+1是关键；前者是总问题1+子问题数量，后面的表示硬币数量的最大值，因为硬币最小就是1元，所以最大不可能超过1*amount+1
	dp[0] = 0;

	for (int i = 1; i <= amount; ++i)  //比如1,2,5凑13，那么dp[0]=0...dp[1]=1...dp[2]=1
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

//解法2：贪心+dfs剪枝；用时8ms
//https://leetcode-cn.com/problems/coin-change/solution/322-by-ikaruga/

void main()
{
	vector<int> coins = { 1, 2, 5 };
	cout << coinChange(coins, 13) << endl;
}