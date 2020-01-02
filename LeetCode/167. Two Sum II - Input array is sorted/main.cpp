#include <iostream>
#include <string>
#include <vector>

using namespace std;

//�ҵķ�����������������ѷ�����ȫһ��
vector<int> twoSum(vector<int>& numbers, int target) 
{
	if (numbers.empty())
		return {};
	vector<int> resultVec;
	int lenVec = numbers.size();
	for (int i = 0, j = lenVec - 1; i < lenVec;)
	{
		if (numbers[i] + numbers[j] < target)
			++i;
		else if (numbers[i] + numbers[j] > target)
			--j;
		else
		{
			resultVec.push_back(i + 1);
			resultVec.push_back(j + 1);
			break;
		}
	}
	return resultVec;
}

//���ѷ�������΢���һЩ
//vector<int> twoSum(vector<int>& numbers, int target)
//{
//	int l = 0;
//	int r = numbers.size() - 1;
//	while (l < r) 
//	{
//		if (numbers[l] + numbers[r] == target)
//		{
//			vector<int> res{ l + 1,r + 1 };
//			return res;
//		}
//		else if (numbers[l] + numbers[r] > target)
//		{
//			r--;
//		}
//		else
//		{
//			l++;
//		}
//	}
//	return {};
//}

int main()
{
	vector<int> myVec = { 2,7,11,15 };
	vector<int> resultVec = twoSum(myVec, 9);
	for (auto &n : resultVec)
		cout << n << endl;
	return 0;
}
