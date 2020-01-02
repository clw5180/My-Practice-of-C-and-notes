#include <iostream>
#include <string>
#include <vector>

using namespace std;

int FindNumber(vector<int> data, int k)
{
	int len = data.size();
	int left = 0, right = len - 1;
	int mid;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (data[mid] < k)
			left = mid + 1;
		else if (data[mid] > k)
			right = mid;
		else
			return mid;
	}
	if (data[left] == k)
		return left;
	return -1;
}

int GetNumberOfK(vector<int> data, int k)
{
	if (data.empty())
		return 0;
	int len = data.size();
	int index = FindNumber(data, k);
	int count = 0;
	if (index == -1)
		return 0;
	else
	{	
		int i = index, j = index;
		while (data[i] == k)
		{
			count++;
			i++;
			if (i >= len)
				break;
		}
		while(data[j] == k)
		{
			count++;
			j--;
			if (i < 0)
				break;
		}
		count--;
	}
	return count;
}

int main()
{
	//vector<int> vec = { 1,2,2,4,5,6 };
	vector<int> vec = { 1,3,3,3,4,5};
	cout << GetNumberOfK(vec, 2);
	return 0;
}