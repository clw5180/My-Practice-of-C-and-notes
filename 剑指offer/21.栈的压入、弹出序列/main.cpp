#include <iostream>
#include <string>
#include <vector>

using namespace std;

//我的方案1：比如对于1,2,3,4,5，判断4,5,3,2,1是不是一个弹出序列，
//先找到右边vector第一个数4，然后看左边vector，4前面是3，2，1的顺序，
//那么右边vector也必须是3，2，1的顺序，否则不是弹出序列，比如4,3,5,1,2。
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
	int needCount = i; //遍历左右vector，如果能依次找到321，则个数为3，说明是弹出序列
	i--;
	int count = 0;  //实际统计到的321的个数，如果是312，那么实际count=2，1被忽略掉了

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