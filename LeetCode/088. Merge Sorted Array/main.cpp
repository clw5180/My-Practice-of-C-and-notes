#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
	我的方案：考虑先将nums2合并到nums1，然后快排
	Runtime: 4 ms, faster than 100.00% of C++ online submissions for Merge Sorted Array.
	Memory Usage: 8.8 MB, less than 100.00% of C++ online submissions for Merge Sorted Array.
	但是比较麻烦，因为题目有一个已知条件是nums1和nums2已经是有序数组了，这里当成无序来处理的
	所以应该能找到更简单的方案
*/
int partition(vector<int>& nums, int low, int high)
{
	int pivot = nums[low];  //相当于nums[low]这里有一个空位

	int temp;
	while (low < high)
	{
		while (low < high && nums[high] >= pivot)
		{
			--high;
		}
		temp = nums[low];
		nums[low] = nums[high];
		nums[high] = temp;

		while (low < high && nums[low] <= pivot)
		{
			++low;
		}
		temp = nums[low];
		nums[low] = nums[high];
		nums[high] = temp;
	}
	//结束后low和high均指向pivot，因此返回哪个都行
	return low;
}

void quickSort(vector<int>& nums, int low, int high) 
{
	if (low < high)
	{
		//Step 1：partition
		int pivot = partition(nums, low, high);

		//Step 2：sort
		//（1）对左边子序列排序
		quickSort(nums, low, pivot - 1);

		//（2）对右边子序列排序
		quickSort(nums, pivot + 1, high);
	}
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
	//考虑先将nums2合并到nums1
	int len2 = nums2.size();
	for (int i = m, j=0; i < m + len2; ++i, ++j)
	{
		nums1[i] = nums2[j];
	}

	//然后快排
	int low = 0;
	int high = nums1.size() - 1;
	quickSort(nums1, low, high);

	return;
}


/*网友方案：三行解决。。。
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
	{
		int i = m - 1, j = n - 1, tar = m + n - 1;
		while (j >= 0) 
		{
			nums1[tar--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
		}
	}
*/


int main()
{
	vector<int> nums1 = { 1,2,3,0,0,0 };
	vector<int> nums2 = { 2,5,6 };
	merge(nums1, 3, nums2, 3);
	for (auto &c : nums1)
		cout << c << " ";
	return 0;
}