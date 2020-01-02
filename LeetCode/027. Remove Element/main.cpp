#include <iostream>
#include <string>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) 
{
	int nMovStep = 0;
	int numsSize = nums.size();
	for (int i = 0; i < numsSize; ++i)
	{
		if (nMovStep > 0)
		{
			nums[i - nMovStep] = nums[i];
		}
		if (nums[i] == val)
		{
			++nMovStep;
		}
	}
	return numsSize - nMovStep;
}

//网友更简洁的答案：
//int removeElement(vector<int>& nums, int val) 
//{
//	int j = 0;
//	int len = nums.size();
//	for (int i = 0; i < len; ++i) 
//	{
//		if (nums[i] != val) 
//		{
//			nums[j++] = nums[i];
//		}
//	}
//	return j;
//}

int main()
{
	vector<int> nums = { 1, 2, 3, 1, 2, 3 };
	int val = 2;
	int length = removeElement(nums, val);
	for (auto &n : nums)
		cout << n << " ";
	cout << "after remove, length:" << length << endl;
	return 0;
}