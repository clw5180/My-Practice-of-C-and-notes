#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> FindNumbersWithSum(vector<int> array, int sum) 
{
	if (array.empty())
		return {};

	int len = array.size();
	int *pLeft = &array[0];
	int *pRight = &array[len - 1] ;
	while (*pLeft < *pRight)
	{
		if (*pLeft + *pRight > sum)
			pRight--;
		else if (*pLeft + *pRight < sum)
			pLeft++;
		else
		{
			vector<int> vec;
			vec.push_back(*pLeft);
			vec.push_back(*pRight);
			return vec;
		}
	}
	return {};
}

int main()
{
    
	return 0;
}