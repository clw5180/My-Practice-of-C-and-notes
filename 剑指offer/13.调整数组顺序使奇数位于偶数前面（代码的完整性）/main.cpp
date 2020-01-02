#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/
//我的方案：
void reOrderArray(vector<int> &array)
{
	int len = array.size();
	vector<int> oddVec, evenVec;
	for (int i = 0; i < len; ++i)
	{
		if (array[i] % 2 != 0) //奇数
			oddVec.push_back(array[i]);
		else
			evenVec.push_back(array[i]);
	}
	int oddLen = oddVec.size();
	int evenLen = evenVec.size();
	for (int i = 0; i < oddLen; ++i)
	{
		array[i] = oddVec[i];
	}
	for (int i = 0; i < evenLen; ++i)
	{
		array[i + oddLen] = evenVec[i];
	}
}

int main()
{
	vector<int> myVec = { 3,4,1,5,2,8,7,6 };
	reOrderArray(myVec);
	for (auto &n : myVec)
		cout << n << " ";
	return 0;
}