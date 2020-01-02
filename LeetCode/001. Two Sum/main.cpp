#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) 
{
	vector<int> result;
	map<int, int> hashMap;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (hashMap.find(target - nums[i]) == hashMap.end())
		{
			hashMap[nums[i]] = i;
		}
		else
		{
			result.push_back(hashMap[target - nums[i]]);
			result.push_back(i);	
			break;
		}
	}
	return result;
}

int main()
{
	vector<int> myVec = { 1,2,5,7 };
	int target = 9;
	if(!twoSum(myVec, target).empty())
	cout << twoSum(myVec, target)[0] << endl;
	cout << twoSum(myVec, target)[1] << endl;
	return 0;
}