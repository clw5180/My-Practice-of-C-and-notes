#include <iostream>
#include <string>
#include <vector>

using namespace std;

//�ҵķ������£�����������Ѵ���һ���ģ���Ȼһ���Ӿ��뵽�ˡ�������
int singleNumber(vector<int>& nums) 
{
	//��Ŀ˵��vector�ǿգ���˾Ͳ��ж�nums.empty()��
	int lenNums = nums.size();
	int tmp = nums[0];
	for (int i = 1; i < lenNums; ++i)
	{
		tmp ^= nums[i];
	}
	return tmp;
}

int main()
{
	vector<int> myVec1 = { 1,2,1,2 };
	vector<int> myVec2 = { 4,1,2,1,2 };
	cout << singleNumber(myVec2) << endl;
	return 0;
}