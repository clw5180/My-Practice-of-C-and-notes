#include <iostream>
#include <string>
#include <vector>
#include <AccCtrl.h>
using namespace std;

/*
��������ֻ����2��3��5��������������Ugly Number����
����6��8���ǳ�������14���ǣ���Ϊ������������7�� ϰ�������ǰ�1�����ǵ�һ��������
�󰴴�С�����˳��ĵ�N��������
*/
//bool IsPrime(int num)
//{
//	if (num <= 1)
//		return false;
//	
//	int sqrtNum = sqrt(num);
//	for (int i = 2; i <= sqrtNum; ++i)
//	{
//		if (num % i == 0)
//			return false;
//	}
//	return true;
//}
//
//
//bool IsUglyNumber(int num)
//{
//	if (num <= 0)
//		return false;
//	if (num == 1)
//		return true;
//
//	int count = 0;
//	for (int i = 2; i < num; ++i)
//	{
//		if (num % i == 0 && IsPrime(i) && (i != 2 && i != 3 && i != 5))
//			return false;
//	}
//	if (num % 2 == 0 || num % 3 == 0 || num % 5 == 0)
//		return true;
//
//	return false;
//}
//
//
//int GetUglyNumber_Solution(int index) 
//{
//	if (index <= 0)
//		return -1;
//
//	int count = 0;
//	int i = 1;
//	while(1)
//	{
//		if (IsUglyNumber(i))
//			count++;
//		if (count == index)
//			return i;
//		i++;
//	}
//}

//���ѷ���1��ע������жϳ����ķ���
//bool IsUglyNumber(int num)
//{
//	while ((num % 2) == 0)
//	{
//		num /= 2;
//	}
//	while ((num % 3) == 0)
//	{
//		num /= 3;
//	}
//	while ((num % 5) == 0)
//	{
//		num /= 5;
//	}
//	return (num == 1) ? true : false;
//}

/*
˼·�������б��е���һ�����֣�һ����֮ǰĳһ�����ֳ���2�������3�������5��
��ʼ�ֱ���2��3��5 ���� 1��ȡ�����˻�����С�� 2*1��
��������3 �� 5 ���ǳ��� 1���� 2 ���Գ����б��е���һ������ 2������ȡ�����˻�����С��
�����б�  i2  i3  i5
1           0   0   0
1,2         1   0   0
1,2,3       1   1   0
1,2,3,4     2   1   0
*/
//���ѷ���2��
int GetUglyNumber_Solution(int index)
{
	if (index < 7) return index;
	vector<int> res(index);
	res[0] = 1;
	int t2 = 0, t3 = 0, t5 = 0, i;
	for (i = 1; i < index; ++i)
	{
		res[i] = min(res[t2] * 2, min(res[t3] * 3, res[t5] * 5));
		if (res[i] == res[t2] * 2) t2++;
		if (res[i] == res[t3] * 3) t3++;
		if (res[i] == res[t5] * 5) t5++;
	}
	return res[index - 1];
}

int main()
{
	//cout << IsPrime(2);
	//cout << IsPrime(3);
	//cout << IsPrime(4);
	//cout << IsPrime(5);
	//cout << IsPrime(6);
	//cout << IsPrime(7);
	//cout << IsPrime(8);
	cout << GetUglyNumber_Solution(1) << endl;
	cout << GetUglyNumber_Solution(2) << endl;
	cout << GetUglyNumber_Solution(3) << endl;
	cout << GetUglyNumber_Solution(4) << endl;
	cout << GetUglyNumber_Solution(5) << endl;
	cout << GetUglyNumber_Solution(6) << endl;
	cout << GetUglyNumber_Solution(7) << endl;
	cout << GetUglyNumber_Solution(8) << endl;
	cout << GetUglyNumber_Solution(9) << endl;
	cout << GetUglyNumber_Solution(10) << endl;
	cout << GetUglyNumber_Solution(11) << endl;
	cout << GetUglyNumber_Solution(100) << endl;
	cout << GetUglyNumber_Solution(1500) << endl;
	return 0;
}