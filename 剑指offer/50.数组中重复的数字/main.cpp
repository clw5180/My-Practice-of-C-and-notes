#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool duplicate(int numbers[], int length, int* duplication) 
{
	map<int, int> hashMap;
	if (numbers == NULL || duplication == NULL || length <= 0)
		return false;
	for (int i = 0; i < length; ++i)
	{
		hashMap[numbers[i]]++;
	}
	for (int i = 0; i < length; ++i)
	{
		if (hashMap[numbers[i]] > 1)
		{
			*duplication = numbers[i];
			return true;
		}		
	}
	return false;
}

int main()
{
    
	return 0;
}