#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int rob(vector<int>& nums) 
{
	if (nums.empty())
		return 0;

	int len = nums.size();
	if (len == 1)
		return nums[0];
	
	int pre = nums[0], cur = max(nums[0], nums[1]);
	int result = cur;
	for (int i = 2; i < len; ++i)
	{
		result = max(cur, pre + nums[i]);
		pre = cur;
		cur = result;
		//cout << result << endl;
	}
	return result;
}


//网友方案1：
int rob(vector<int>& nums) 
{
	int n = nums.size(), pre = 0, cur = 0;
	for (int i = 0; i < n; i++) 
	{
		int temp = max(pre + nums[i], cur);
		pre = cur;
		cur = temp;
	}
	return cur;
}

//网友方案2：
int rob(vector<int>& nums) 
{
	int x = 0, y = 0;
	for (int i = 0; i < nums.size(); ++i) 
	{
		if (i & 1) //奇数情况
			x = max(x + nums[i], y);   //x是奇数对应最大值
		else 
			y = max(y + nums[i], x);  //y是偶数对应最大值
	}
	return max(x, y);
}
 

int main()
{
	vector<int> vec = { 1,1 };
	//vector<int> vec = { 1,2,3,5,4 };
	cout << rob(vec) << endl;
	return 0;
}

