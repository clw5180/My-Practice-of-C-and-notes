#include <iostream>
#include <string>
#include <vector>

using namespace std;

//�ҵķ�����
vector<int> plusOne(vector<int>& digits) 
{
	int lenVec = digits.size();
	for (int i = lenVec - 1; i >= 0; --i)
	{
		if (digits[i] != 9)
		{
			++digits[i];
			return digits;
		}
		else
		{
			digits[i] = 0;
		}
	}
	digits.insert(digits.begin(), 1);
	//���Ѷ���9,99,999�������ݵ���һ�ִ���ʽ��
	//digits[0] = 1;
	//digits.push_back(0);
	return digits;
}

int main()
{
	//vector<int> myVec = { 1,2,3,4 };
	//vector<int> myVec = { 1,2,9,9 };
	vector<int> myVec = { 9,9 };
	vector<int> outVec = plusOne(myVec);
	for (auto &c : outVec)
	{
		cout << c << " ";
	}
	return 0;
}