#include <iostream>
#include <string>
#include <vector>

using namespace std;

void rotate(vector<int>& nums, int k) 
{
	int lenNums = nums.size();
	if (lenNums == 0)
		return;

	k %= lenNums;
	if (k == 0)
		return;
	int *arr = new int[k];  //In order to move K length directly, k elements need to be saved in advance.

	for (int i = 0; i < k; ++i)
	{
		arr[i] = nums[lenNums - k + i];  //save K elements in advance
	}

	for (int i = lenNums - k - 1; i >= 0; --i)  //Move lenNums - k  elements
	{
		nums[i + k] = nums[i];
	}

	for (int i = 0; i < k; ++i) //take out k elements saved before
	{
		nums[i] = arr[i];
	}

	delete [] arr;  //free memory
	return;
}

int main()
{
	//vector<int> myVec = { 1,2,3,4,5,6,7,8,9 };
	vector<int> myVec = { 1,2 };
	rotate(myVec, 3);
	for (auto &n : myVec)
		cout << n << " ";
	return 0;
}