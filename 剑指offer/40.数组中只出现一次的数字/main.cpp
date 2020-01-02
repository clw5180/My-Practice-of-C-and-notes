#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) 
{
	if (data.empty())
		return;
	int len = data.size();
	map<int, int> hashMap;
	for (int i = 0; i < len; ++i)
	{
		hashMap[data[i]]++;
	}

	int count = 0;
	for (int i = 0; i < len; ++i)
	{	
		if (hashMap[data[i]] == 1 && count % 2 == 0)
		{
			*num1 = data[i];
			count++;
		}
		else if (hashMap[data[i]] == 1 && count % 2 == 1)
		{
			*num2 = data[i];
			return;
		}
	}
	
}

int main()
{
	return 0;
}