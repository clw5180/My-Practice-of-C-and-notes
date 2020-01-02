#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

//我的方案1：
int jumpFloorII(int number) 
{
	if (number <= 0)
		return -1;
	unordered_map<int, int> hashMap;
	hashMap[1] = 1;
	hashMap[2] = 2;
	for (int i = 2; i < number; ++i)
	{
		for (int j = 1; j < i + 1; ++j)
		{
			hashMap[i + 1] += hashMap[j];
		}
		++hashMap[i + 1]; //还要加上f(0)，也就是直接从地面上去的情况
	}
	return hashMap[number];
}

//我的方案2：return pow(2, number-1);

//网友方案3（最佳）：return 1<<(number-1); 乘2或者除2应该用移位操作。。

int main()
{
	cout << jumpFloorII(1) << endl;
	cout << jumpFloorII(2) << endl;
	cout << jumpFloorII(3) << endl;
	cout << jumpFloorII(4) << endl;
	cout << jumpFloorII(5) << endl;
	return 0;
}