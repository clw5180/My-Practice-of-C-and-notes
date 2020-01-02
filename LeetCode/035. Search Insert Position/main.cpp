#include <iostream>
#include <string>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target)
{
	int numsSize = nums.size();
	int nBegin = 0, nEnd = numsSize - 1;
	int nMid;

	if (numsSize == 0 || target > nums[nEnd]) //注意顺序不要反了，否则来了空的vector就会宕掉
		return numsSize;

	if (target < nums[0])
		return 0;

	while (nBegin <= nEnd)
	{
		nMid = (nBegin + nEnd) / 2;
		if (target > nums[nMid])
		{
			nBegin = nMid + 1;
			if (nums[nBegin] >= target)
				return nBegin;
		}
		else if (target < nums[nMid])
		{
			nEnd = nMid - 1;
			if (nums[nEnd] < target)
				return nMid;
			else if (nums[nEnd] == target)
				return nEnd;
		}
		else
			return nMid;
	}
	return -1;
}


//网友更好的答案：
//int searchInsert(vector<int>& nums, int target)
//{
//	if (nums.size() == 0 || target > nums[nums.size() - 1])
//	{
//		return nums.size();
//	}
//	int i = 0, j = nums.size() - 1;
//	while (i < j)
//	{
//		int mid = (i + j) / 2;
//		if (nums[mid] >= target)
//		{
//			j = mid;
//		}
//		else
//		{
//			i = mid + 1;
//		}
//	}
//	return i;
//}


int main()
{
	//vector<int> nums = { 1, 2, 3, 4, 7, 8, 10};
	vector<int> nums = { 1, 3, 5, 6};
	//vector<int> nums = { 1, 3, 5};
	//vector<int> nums = {};
	cout << "the index of insert number is: " << searchInsert(nums, 2) << endl;
	return 0;
}