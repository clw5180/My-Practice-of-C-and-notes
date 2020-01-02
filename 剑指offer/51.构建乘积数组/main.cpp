#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> multiply(const vector<int>& A)
{
	if (A.empty())
		return {};

	int len = A.size();
	vector<int> vecB;
	for (int i = 0; i < len; ++i)
	{
		int mult = 1;
		for (int j = 0; j < len; ++j)
		{
			if(j == i)
				continue;
			mult *= A[j];
		}
		vecB.push_back(mult);
	}
	return vecB;
}

int main()
{
	vector<int> vec = multiply({ 1,2,3,4,5 });
	return 0;
}