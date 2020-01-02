#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;

//我的方案：速度太慢，但是不需要额外空间存储。
//bool IsPrime(int num)
//{
//	if (num <= 1)
//		return false;
//	//if (num == 2 || num == 3 || num == 5)
//	//	return true;
//	//if (num % 6 != 1 && num % 6 != 5)
//	//	return false;
//	int sqrtNum = sqrt(num);
//	for (int i = 2; i <= sqrtNum; ++i)
//	{
//		if (num % i == 0)
//			return false;
//	}
//	return true;
//}
//
////Count the number of prime numbers less than a non-negative number, n.
//int countPrimes(int n) 
//{
//	if (n <= 2)
//		return 0;
//	if (n == 3)
//		return 1;
//	if (n == 4 || n == 5)
//		return 2;
//	if (n == 6)
//		return 3;
//
//	int count = 3;
//	for (int i = 7; i < n; i += 6)
//	{
//		if (IsPrime(i))
//			++count;
//	}
//	for (int i = 11; i < n; i += 6)
//	{
//		if (IsPrime(i))
//			++count;
//	}
//	return count;
//}


//国外网友的最佳答案：从2开始在while循环中，用自己的平方反复加自己，如2*2+2+2，3*3+3+3...
//这样会排除所有合数，写一些就知道了！
//很好的思路，值得学习！！
int countPrimes(int n) 
{
	//Sieve of Erantothoses

	//vector<bool> check(n + 1, true);//clw note：leetcode commit use this  LeetCode用这个提交
	bool* check = new bool[n+1]; //clw note：faster than the code above  VS测试用这个

	//Because 0 and 1 are not primes
	check[0] = false;
	check[1] = false;

	//OPtimization 2: Do only till rootn since all numbers after that are handled
	//The remaining values are already true
	for (int i = 2; i*i <= n; i++)
	{
		//If already visited
		if (check[i] == false) continue;

		//Optimation 1 : 3*2 is already handled by 2*3. Toh directly start from 9
		int j = i * i;
		while (j <= n)
		{
			check[j] = false;
			j = j + i;
		}

	}
	int count = 0;
	//Checking all the numbers which are prime (less than n)
	for (int i = 1; i < n; i++)
		if (check[i]) count++;

	return count;
}

int main()
{
	//cout << IsPrime(1) << endl;
	//cout << IsPrime(2) << endl;
	//cout << IsPrime(3) << endl;
	//cout << IsPrime(4) << endl;
	//cout << IsPrime(5) << endl;
	//cout << countPrimes(20) << endl;
	//cout << countPrimes(1000000) << endl;
	cout << countPrimes(980000000) << endl;
	cout << countPrimes(9800000) << endl;
	return 0;
}