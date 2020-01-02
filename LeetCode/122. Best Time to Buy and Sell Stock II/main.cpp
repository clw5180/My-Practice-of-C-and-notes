#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
	�ҵķ�����̫�����ˣ�˼·��
	1�������ǰֵ����ǰһֵ��������ֵΪ��ǰֵ-��Сֵ����Сֵ��Ҫ�����������в��ϼ�¼��
	2��һ����ǰֵС��ǰһֵ����ǰһ���������������������ֵ���ӵ����������֮����Сֵ����Ϊ��ǰֵ������ֵ���㡣
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
    ���ѷ�����̰�ķ���ֻҪ�����������ǰ��ͰѲ�ֵ�ۻ�����������ܺ��У�
    ����2,5,7,3����5>2����ô5-2=3�ӽ�ȥ��Ȼ��7>5����ô7-5=2�ӽ�ȥ���ܹ�����3+2=5
    ���������ҵ�7Ȼ���ټ�ȥ2��Ч����һ���ģ������򵥺ܶࡣ����7�и㶨
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