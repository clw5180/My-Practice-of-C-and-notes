#include <iostream>
#include <string>
#include <vector>

using namespace std;

//�ҵķ���1���������1,2,3,4,5���ж�4,5,3,2,1�ǲ���һ���������У�
//���ҵ��ұ�vector��һ����4��Ȼ�����vector��4ǰ����3��2��1��˳��
//��ô�ұ�vectorҲ������3��2��1��˳�򣬷����ǵ������У�����4,3,5,1,2��
bool IsPopOrder(vector<int> pushV, vector<int> popV) 
{
	int pushVSize = pushV.size();
	int popVSize = popV.size();
	if (pushVSize == 0 || pushVSize != popVSize)
		return false;

	int i = pushVSize - 1;
	while (pushV[i] != popV[0])
	{
		i--;
	}
	int needCount = i; //��������vector������������ҵ�321�������Ϊ3��˵���ǵ�������
	i--;
	int count = 0;  //ʵ��ͳ�Ƶ���321�ĸ����������312����ôʵ��count=2��1�����Ե���

	int j = 1;
	while (i >= 0 && j <= popVSize - 1)
	{
		if (pushV[i] == popV[j])
		{
			i--;
			count++;
		}
		else
			j++;	
	}
	if (count == needCount)
		return true;
	else
		return false;
}

int main()
{
	vector<int> vec1 = { 1,2,3,4,5 };
	vector<int> vec2 = { 4,5,3,2,1 };
	vector<int> vec3 = { 4,3,5,1,2 };
	cout << IsPopOrder( vec1, vec2)<< endl;
	cout << IsPopOrder(vec1, vec3) << endl;
	return 0;
}