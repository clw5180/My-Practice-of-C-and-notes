#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

//我的答案。。。
//int removeDuplicates(vector<int>& nums)   
//{
//	if (nums.empty())
//		return 0;
//
//	int offset = 0;
//	int sumOffset = 0;
//	int count = 0;
//	int repeatCount = 0;
//	map<int, int> hashMap;
//	for (auto &n : nums)
//	{
//		++hashMap[n];
//		if (hashMap[n] > 1)
//		{
//			repeatCount++;
//		}
//	}
//	int i = 0;
//	int numsSize = nums.size();
//	while(i < numsSize - 1)
//	{
//		sumOffset += hashMap[nums[i]] - 1;
//		offset = hashMap[nums[i]] - 1;
//
//		if ((i += offset + 1) >= numsSize)
//			break;
//
//		nums[i - sumOffset] = nums[i];
//	}
//
//	return nums.size() - repeatCount;
//}

//网友答案1（个人感觉最佳，思路：在for循环中额外引入一个可以自己掌控的索引j，方便更新数组）
int removeDuplicates(vector<int>& A) 
{
	int N = A.size();
	if (N <= 1) return A.size();
	int j = 0; // prev
	for (int i = 1; i < A.size(); i++) 
	{ // i-> current
		if (A[i] > A[j]) 
		{
			A[j + 1] = A[i];
			j++;
		}
	}
	return j + 1; // length
}

////网友答案2
//int removeDuplicates(vector<int>& nums) {
//
//	auto numsSize = nums.size();
//
//	if (numsSize < 1) return 0; // if vector has 0 elements then return
//
//	int counter = 0;
//
//	for (int i = 0; i < numsSize - 1; i++)
//		if (nums[i] != nums[i + 1]) nums[counter++] = nums[i];
//
//	// since we miss the last element either (1) there was a duplicate like ....5,5 and we iterated over it 
//	// or (2) there was a unique element and we only put one of them like 5,6 --> 5 enters and we miss 6
//	nums[counter++] = nums[numsSize - 1];
//
//	return counter;
//}

int main()
{
	//vector<int> nums = { 1, 2, 3, 3, 3, 3, 4, 4, 5, 5, 7 };
	//vector<int> nums = {1, 1, 1, 2, 2};
	vector<int> nums = { 5,6 };

	// nums is passed in by reference. (i.e., without making a copy)
	int len = removeDuplicates(nums);

	// any modification to nums in your function would be known by the caller.
	// using the length returned by your function, it prints the first len elements.
	for (int i = 0; i < len; i++) 
	{
		cout << nums[i] << " ";
	}
	cout << endl;
	cout << "len: " << len << endl;
	return 0;
}