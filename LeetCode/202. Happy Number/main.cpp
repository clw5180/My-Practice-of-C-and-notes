#include <iostream>
#include <string>
#include <vector>

using namespace std;


//我的方案：4 ms, faster than 100.00%, 7.9 MB, less than 98.86%
/*
	clw note：the type of number is int, so maybe the max is 199999999, 
	and compute it the max will be 649, compute again it may lower than 200, 
	at most it will be less than 200 next time . Once it's lower than 200, 
	it will be lower than 200 forever. So if we call isHappy(int n) more than 
	about 202 times, we can make sure that it's not a happy number. 
	(I also tried that just count > 10 can also meet the requirements：)
*/
bool isHappy(int n) 
{
	static int count = 0;
	int remainder, result = 0;
	if (n == 1)
		return true;
	while (n >= 10)
	{
		remainder = n % 10;
		result += remainder * remainder;
		n /= 10;
	}
	result += n * n;
	++count;
	if (count > 202)  //其实10次就可以满足了
	{
		count = 0;
		return false;
	}
	if (isHappy(result))
		return true;
	return false;
}

//网友最佳方案1：找到规律，如果不是happy数，会进入一个4的循环
//效果：4 ms, faster than 100.00%, 7.9 MB, less than 98.86%
//（4 16 37 58 89 145 42 20 4）
//bool isHappy(int n)
//{
//	while (true)
//	{
//		if (n == 1) { return true; }
//		if (n == 4) { return false; }
//		int next = 0;
//		while (n) { next += (n % 10) * (n % 10), n /= 10; }
//		n = next;
//	}
//}


//网友最佳方案2：自定义一个hashtable
//效果：4 ms, faster than 100.00%, 7.9 MB, less than 98.86%
//int tran(int n)
//{
//	int ans = 0;
//	while (n) {
//		ans += pow(n % 10, 2);
//		n /= 10;
//	}
//	return ans;
//}
//bool isHappy(int n)
//{
//	bool rep[1000];
//	memset(rep, 0, sizeof(rep));
//	n = tran(n);
//	while (!rep[n]) 
//	{
//		rep[n] = true;
//		if (n == 1)
//			return true;
//		n = tran(n);
//	}
//	return false;
//}


int main()
{
	cout << (isHappy(1) ? "is Happy number" : "is not Happy number") << endl;
	cout << (isHappy(19) ? "is Happy number" : "is not Happy number") << endl;
	cout << (isHappy(89) ? "is Happy number" : "is not Happy number") << endl;
	cout << (isHappy(2) ? "is Happy number" : "is not Happy number") << endl;
	cout << (isHappy(123) ? "is Happy number" : "is not Happy number") << endl;
	return 0;
}