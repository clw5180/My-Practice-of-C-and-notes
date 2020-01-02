#include <iostream>
#include <string>
#include <vector>

using namespace std;

//网友方案1：DP
int maxSubArray(vector<int>& nums) 
{
	int nEnd=nums[0];
	int nAll=nums[0];
   	int len = nums.size();
	for (int i = 1; i < len; i++) 
    	{
		nEnd=max(nEnd+nums[i], nums[i]);
		nAll=max(nAll, nEnd);
	}
	return nAll;
}

//网友方案2：DP
int maxSubArray(vector<int>& nums)
{
        int res = INT_MIN;
        int curSum = 0;
        for (int num : nums) 
		{
            curSum = max(num,curSum + num);//换句话就是，如果cursum为负，那么最大值就是num
            res = max(curSum,res);
        }
        return res;
}

//我的方案（参考网友https://blog.csdn.net/ljianhui/article/details/13950509，不错的方法）
int maxSubArray(vector<int>& nums) 
{
	int len = nums.size();
	if (len <= 0)
		return -1;
	int negativeCnt = 0;
	int maxNumber = nums[0];
	int subSum = 0;
	int SubSumMax = 0;

	for (int i = 0; i < len; ++i)
	{
		subSum += nums[i];
		if (subSum > SubSumMax) //如果当前找的子数组之和大于之前的最大子数组之和
			SubSumMax = subSum;  //则该子数组之和为最大子数组之和
		else if (subSum < 0) //如果子数组之和小于0，直接清掉从下一个数开始找；因为一定不是最大子数组
			subSum = 0;

		if (nums[i] < 0) //统计负数的个数，这个只针对全为负的数组
			++negativeCnt;
		if (nums[i] > maxNumber) //找到数组中的最大值，这个只针对全为负的数组
			maxNumber = nums[i];
	}
	if (negativeCnt == len) //如果是全为负的数组，直接取最大值作为最大子数组
		SubSumMax = maxNumber;
	return SubSumMax;
}

int main()
{
	//vector<int> myVec = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	//vector<int> myVec = { 1 };
	//vector<int> myVec = { -2 };
	//vector<int> myVec = { -2, 1 };
	//vector<int> myVec = { -2, -1 };
	//vector<int> myVec = { 1, -2 };
	//vector<int> myVec = { 1, -2, 3};
	//vector<int> myVec = { 1, -2, 3, -4};
	vector<int> myVec = { -5, 6, -5 };

	cout << maxSubArray(myVec) << endl;
	return 0;
}
