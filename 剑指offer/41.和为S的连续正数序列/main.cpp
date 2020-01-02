#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int> > FindContinuousSequence(int sum) 
{
	vector<vector<int>> result;
	for (int i = 2; i < sum; ++i)
	{
		if (sum / i - (i - 1) / 2 <= 0)
			break;
		int nResult = sum / i;
		if (sum % i == 0) //如果能整除
		{
			if (i % 2 == 0) //偶数跳过
				continue;
			else //奇数则进入
			{
				vector<int> tmp;
				int j = (i - 1) / 2;
				for (int k = nResult - j; k < nResult - j + i; ++k)
				{
					tmp.push_back(k);
				}
				result.insert(result.begin(),tmp);
			}
		}
		else if(sum * 1.0 / i - sum / i == 0.5) //比如100/8=12.5，可以
		{
			int n = sum / i - (i / 2 - 1);
			vector<int> tmp;
			for (int m = n; m < n + i; m++)
			{
				tmp.push_back(m);
			}
			result.insert(result.begin(), tmp);
		}
	}
	return result;
}

int main()
{
	FindContinuousSequence(100);
	return 0;
}