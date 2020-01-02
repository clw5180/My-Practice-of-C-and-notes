#include <iostream>
#include <string>
#include <vector>
#include <AccCtrl.h>
using namespace std;

/*
把质因子只包含2、3和5的数称作丑数（Ugly Number）。
例如6、8都是丑数，但14不是，因为它包含质因子7。 习惯上我们把1当做是第一个丑数。
求按从小到大的顺序的第N个丑数。
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

//网友方案1：注意这个判断丑数的方法
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
思路：丑数列表中的下一个数字，一定是之前某一个数字乘以2、或乘以3、或乘以5。
初始分别用2、3、5 乘以 1，取三个乘积中最小的 2*1；
接下来，3 和 5 还是乘以 1，而 2 可以乘以列表中的下一个数字 2，还是取三个乘积中最小的
丑数列表：  i2  i3  i5
1           0   0   0
1,2         1   0   0
1,2,3       1   1   0
1,2,3,4     2   1   0
*/
//网友方案2：
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