#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

//输入n个整数，找出其中最小的K个数。
//例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
vector<int> GetLeastNumbers_Solution(vector<int> input, int k) 
{
	int len = input.size();
	if (len <= 0 || len < k)
		return {};

	multiset<int> mult;
	for (int i = 0; i < k; ++i)
	{
		mult.insert(mult.begin(), input[i]);
	}
	
	for (int i = k; i < len; ++i)
	{
		set<int>::iterator iter = mult.end();
		iter--;
		if (input[i] < *iter)
		{
			mult.erase(iter);
			mult.insert(input[i]);
		}
    }

	vector<int> vec;
	set<int>::iterator iter = mult.begin();
	for (int i = 0; i < k; ++i)
	{
		vec.push_back(*iter);
		++iter;
	}
	return vec;
}


int main()
{
	//vector<int> vec = { 2,1,5,3,4 };
	vector<int> vec = { 4,5,1,6,2,7,3,8 };
	//vector<int> vec = { 2, 3 };
	vector<int> resultVec;
	resultVec = GetLeastNumbers_Solution(vec, 6);
	for (const auto &n : resultVec)
		cout << n << endl;
	return 0;
}