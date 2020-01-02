#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

//假设数组非空，且假设众数一定存在
//我的方案：hashmap
int majorityElement(vector<int>& nums) 
{
	int lenNums = nums.size();
	map<int, int> hashMap;
	for (int i = 0; i < lenNums; ++i)
	{
		hashMap[nums[i]]++;
	}
	map<int, int>::iterator iter;
	for (iter = hashMap.begin(); iter != hashMap.end(); ++iter)
	{
		if (iter->second > lenNums / 2)
		{
			return iter->first;
		}		
	}
	return -1;
}

/*
网友好的解决方案：
☆☆☆1、摩尔投票法（最佳方案）
知乎的解释：重点：首先请考虑最基本的摩尔投票问题，找出一组数字序列中出现次数大于总数1/2的数字
（并且假设这个数字一定存在）。显然这个数字只可能有一个。摩尔投票算法是基于这个事实：
每次从序列里选择两个不相同的数字删除掉（或称为“抵消”），最后剩下一个数字或几个相同的数字，
就是出现次数大于总数一半的那个。
所以我们的目标就是：删除，删除，删除。删到不能删除为止。
int majorityElement(vector<int>& nums) 
{
	int major, counts = 0, n = nums.size();
	for (int i = 0; i < n; i++) 
	{
		if (!counts)
		{
			major = nums[i];
			counts = 1;
		}
		else 
			counts += (nums[i] == major) ? 1 : -1;
	}
	return major;
}

2、哈希表
int majorityElement(vector<int>& nums) 
{
	unordered_map<int, int> counts;
	int n = nums.size();
	for (int i = 0; i < n; i++)
		if (++counts[nums[i]] > n / 2) //自注：事实证明这样每次都进if比较耗时，还是我的方案比较好
			return nums[i];
	return -1;
}

3、排序
int majorityElement(vector<int>& nums) {
	nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
	return nums[nums.size() / 2];
}

4、随机化
int majorityElement(vector<int>& nums) {
	int n = nums.size();
	srand(unsigned(time(NULL)));
	while (true) {
		int idx = rand() % n;
		int candidate = nums[idx];
		int counts = 0;
		for (int i = 0; i < n; i++)
			if (nums[i] == candidate)
				counts++;
		if (counts > n / 2) return candidate;
	}
}

5、分治
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		return majority(nums, 0, nums.size() - 1);
	}
private:
	int majority(vector<int>& nums, int left, int right) {
		if (left == right) return nums[left];
		int mid = left + ((right - left) >> 1);
		int lm = majority(nums, left, mid);
		int rm = majority(nums, mid + 1, right);
		if (lm == rm) return lm;
		return count(nums.begin() + left, nums.begin() + right + 1, lm) > count(nums.begin() + left, nums.begin() + right + 1, rm) ? lm : rm;
	}
};

6、位运算
int majorityElement(vector<int>& nums) {
	int major = 0, n = nums.size();
	for (int i = 0, mask = 1; i < 32; i++, mask <<= 1) {
		int bitCounts = 0;
		for (int j = 0; j < n; j++) {
			if (nums[j] & mask) bitCounts++;
			if (bitCounts > n / 2) {
				major |= mask;
				break;
			}
		}
	}
	return major;
}

*/
int main()
{
	vector<int> myVec1 = { 3,2,3 };
	vector<int> myVec2 = { 2,2,1,1,1,2,2 };
	cout << majorityElement(myVec1) << endl;
	cout << majorityElement(myVec2) << endl;
	return 0;
}