#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
	�ҵķ����������Ƚ�nums2�ϲ���nums1��Ȼ�����
	Runtime: 4 ms, faster than 100.00% of C++ online submissions for Merge Sorted Array.
	Memory Usage: 8.8 MB, less than 100.00% of C++ online submissions for Merge Sorted Array.
	���ǱȽ��鷳����Ϊ��Ŀ��һ����֪������nums1��nums2�Ѿ������������ˣ����ﵱ�������������
	����Ӧ�����ҵ����򵥵ķ���
*/
int partition(vector<int>& nums, int low, int high)
{
	int pivot = nums[low];  //�൱��nums[low]������һ����λ

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
	//������low��high��ָ��pivot����˷����ĸ�����
	return low;
}

void quickSort(vector<int>& nums, int low, int high) 
{
	if (low < high)
	{
		//Step 1��partition
		int pivot = partition(nums, low, high);

		//Step 2��sort
		//��1�����������������
		quickSort(nums, low, pivot - 1);

		//��2�����ұ�����������
		quickSort(nums, pivot + 1, high);
	}
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
	//�����Ƚ�nums2�ϲ���nums1
	int len2 = nums2.size();
	for (int i = m, j=0; i < m + len2; ++i, ++j)
	{
		nums1[i] = nums2[j];
	}

	//Ȼ�����
	int low = 0;
	int high = nums1.size() - 1;
	quickSort(nums1, low, high);

	return;
}


/*���ѷ��������н��������
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