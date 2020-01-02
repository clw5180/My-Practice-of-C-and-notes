#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣�
���е�ż��λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣
*/
//�ҵķ�����
void reOrderArray(vector<int> &array)
{
	int len = array.size();
	vector<int> oddVec, evenVec;
	for (int i = 0; i < len; ++i)
	{
		if (array[i] % 2 != 0) //����
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