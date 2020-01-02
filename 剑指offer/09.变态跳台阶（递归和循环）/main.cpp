#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

//�ҵķ���1��
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
		++hashMap[i + 1]; //��Ҫ����f(0)��Ҳ����ֱ�Ӵӵ�����ȥ�����
	}
	return hashMap[number];
}

//�ҵķ���2��return pow(2, number-1);

//���ѷ���3����ѣ���return 1<<(number-1); ��2���߳�2Ӧ������λ��������

int main()
{
	cout << jumpFloorII(1) << endl;
	cout << jumpFloorII(2) << endl;
	cout << jumpFloorII(3) << endl;
	cout << jumpFloorII(4) << endl;
	cout << jumpFloorII(5) << endl;
	return 0;
}