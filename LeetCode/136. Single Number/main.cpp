#include <iostream>
#include <string>
#include <vector>

using namespace std;

//我的方案如下：（和最佳网友答案是一样的，居然一下子就想到了。。。）
int singleNumber(vector<int>& nums) 
{
	//题目说了vector非空，因此就不判断nums.empty()了
	int lenNums = nums.size();
	int tmp = nums[0];
	for (int i = 1; i < lenNums; ++i)
	{
		tmp ^= nums[i];
	}
	return tmp;
}

int main()
{
	vector<int> myVec1 = { 1,2,1,2 };
	vector<int> myVec2 = { 4,1,2,1,2 };
	cout << singleNumber(myVec2) << endl;
	return 0;
}