#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
	我的方案：太复杂了，思路是
	1、如果当前值大于前一值，则最大差值为当前值-最小值；最小值需要在整个过程中不断记录；
	2、一旦当前值小于前一值，则前一个区间的最大利润就是最大差值，加到最大利润上之后，最小值更新为当前值，最大差值清零。
 */
int maxProfit(vector<int>& prices) 
{
	if (prices.empty())
		return 0;
	int maxSum = 0;
	int maxDiff = 0;
	int minPrice = prices[0];
	int lenPrices = prices.size();
	for (int i = 1; i < lenPrices; ++i)
	{
		if (prices[i] <= minPrice)
			minPrice = prices[i];
		if (prices[i] > prices[i - 1])
			maxDiff = prices[i] - minPrice;
		else
		{
			maxSum += maxDiff;
			minPrice = prices[i];
			maxDiff = 0;
		}		
	}
	maxSum += (prices[lenPrices-1] - minPrice);
	return maxSum;
}

/*
    网友方案：贪心法，只要看到后项大于前项，就把差值累积到最大利润总和中；
    比如2,5,7,3，看5>2，那么5-2=3加进去，然后7>5，那么7-5=2加进去，总共加了3+2=5
    这样和我找到7然后再减去2的效果是一样的，代码会简单很多。。。7行搞定
 */
//int maxProfit(vector<int>& prices) 
//{
//	if (prices.size() <= 1) 
//		return 0;
//	int res = 0;
//	for (size_t i = 1; i < prices.size(); i++)
//		if (prices[i] - prices[i - 1] > 0)
//			res += prices[i] - prices[i - 1];
//	return res;
//}



int main()
{
	vector<int> myVec = { 1,2,3,4,5 }; //4
	vector<int> myVec2 = { 1,4,5,6,3,2,7 }; //10
	vector<int> myVec3 = { 7,1,5,3,6,4 }; //7
	vector<int> myVec4 = { 6,1,3,2,4,7 }; //7
	cout << maxProfit(myVec) << endl;
	cout << maxProfit(myVec2) << endl;
	cout << maxProfit(myVec3) << endl;
	cout << maxProfit(myVec4) << endl;
	return 0;
}