#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

//��������ǿգ��Ҽ�������һ������
//�ҵķ�����hashmap
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
���ѺõĽ��������
����1��Ħ��ͶƱ������ѷ�����
֪���Ľ��ͣ��ص㣺�����뿼���������Ħ��ͶƱ���⣬�ҳ�һ�����������г��ִ�����������1/2������
�����Ҽ����������һ�����ڣ�����Ȼ�������ֻ������һ����Ħ��ͶƱ�㷨�ǻ��������ʵ��
ÿ�δ�������ѡ����������ͬ������ɾ���������Ϊ���������������ʣ��һ�����ֻ򼸸���ͬ�����֣�
���ǳ��ִ�����������һ����Ǹ���
�������ǵ�Ŀ����ǣ�ɾ����ɾ����ɾ����ɾ������ɾ��Ϊֹ��
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

2����ϣ��
int majorityElement(vector<int>& nums) 
{
	unordered_map<int, int> counts;
	int n = nums.size();
	for (int i = 0; i < n; i++)
		if (++counts[nums[i]] > n / 2) //��ע����ʵ֤������ÿ�ζ���if�ȽϺ�ʱ�������ҵķ����ȽϺ�
			return nums[i];
	return -1;
}

3������
int majorityElement(vector<int>& nums) {
	nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
	return nums[nums.size() / 2];
}

4�������
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

5������
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

6��λ����
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