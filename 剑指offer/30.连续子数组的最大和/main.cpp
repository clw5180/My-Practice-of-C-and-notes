#include <iostream>
#include <string>
#include <vector>

using namespace std;

int FindGreatestSumOfSubArray(vector<int> array) 
{
	if (array.empty())
		return 0;
	int len = array.size();
	
	int subSum = 0, subSumMax = 0;
	int negCount = 0;
	int negMax = array[0];
	for (int i = 0; i < len; ++i)
	{
		subSum += array[i];
		if (subSum > subSumMax)
			subSumMax = subSum;
		if (subSum < 0) //如果最大子数组之和小于0，清掉重来
			subSum = 0;

		if (array[i] < 0)
			negCount++;
		if (array[i] > negMax)
		{
			negMax = array[i];
		}
	}

	//如果全为负数，则挑选最大的
	if (negCount == len)
	{
		subSumMax = negMax;
	}
	
	return subSumMax;
}

int main()
{
	vector<int> vec = { 6,-3,-2,7,-15,1,2,2 };
	cout << FindGreatestSumOfSubArray(vec) << endl;
	return 0;
}