#include <iostream>
#include <string>
#include <vector>

using namespace std;

//我的方案（基本和最佳网友方案一致）：
int maxProfit(vector<int>& prices) 
{
	int len = prices.size();
	if (len == 0)
		return 0;
	int minPrice = prices[0];
	int maxDiff = 0;
	for (int i = 1; i < len; ++i)
	{
		if (prices[i] < prices[i - 1])
		{
			if(prices[i] < minPrice)
				minPrice = prices[i];
		}
		else
		{
			if (maxDiff < prices[i] - minPrice)
				maxDiff = prices[i] - minPrice;
		}
	}
	return maxDiff;
}

//网友方案：
//int maxProfit(vector<int> &prices) 
//{
//	int maxPro = 0;
//	int minPrice = INT_MAX;
//	for (int i = 0; i < prices.size(); i++) 
//	{
//		minPrice = min(minPrice, prices[i]);
//		maxPro = max(maxPro, prices[i] - minPrice);
//	}
//	return maxPro;
//}

int main()
{
	vector<int> myVec = { 7,1,5,3,6,4 };
	vector<int> myVec2 = { 7,6,4,3,1 };
	cout << maxProfit(myVec) << endl;
	cout << maxProfit(myVec2) << endl;
	return 0;
}