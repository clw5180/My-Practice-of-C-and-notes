#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
0的0次方是不存在的，正确的概念应该是任何非0数的0次方都为1，0的任何非0次方都为0.
下面说明为什么任何数的0次方都为1，这是除法中定义出来的，比如：
2^4/2^4=2^0=1
即一个数的0次方是这个数的任何非0次方比如a^b(a,b均不为0)，除以它本身的商定义为它的0次方：a^0=a^b/a^b=1
而如果a是0的话，这就如0^b/0^b(b不为0)，显然0除以0是没意义的。因此0的0次方的无意义就等价于0除以0没意义一样的
*/
//我的方案：
double Power(double base, int exponent) 
{
	if (base == 0 && exponent <= 0)
		return -1;
	else if (exponent == 0 && base != 0)
		return 1;

	double result = 1;
	int reverseExponent;
	if (exponent < 0)
		reverseExponent = -exponent;
	else
		reverseExponent = exponent;
		
	for (int i = 0; i < reverseExponent; ++i)
	{
		result *= base;
	}
	if (exponent < 0)
		result = 1 / result;
	return result;
}

//网友方案：
/**
 * 1.全面考察指数的正负、底数是否为零等情况。
 * 2.写出指数的二进制表达，例如13表达为二进制1101。
 * 3.举例:10^1101 = 10^0001*10^0100*10^1000。
 * 4.通过&1和>>1来逐位读取1101，为1时将该位代表的乘数累乘到最终结果。
 */
	public double Power(double base, int n) {
	double res = 1, curr = base;
	int exponent;
	if (n > 0) {
		exponent = n;
	}
	else if (n < 0) {
		if (base == 0)
			throw new RuntimeException("分母不能为0");
		exponent = -n;
	}
	else {// n==0
		return 1;// 0的0次方
	}
	while (exponent != 0) {
		if ((exponent & 1) == 1)
			res *= curr;
		curr *= curr;// 翻倍
		exponent >>= 1;// 右移一位
	}
	return n >= 0 ? res : (1 / res);
}

int main()
{
	cout << Power(2, 3) << endl;
	cout << Power(2, -3) << endl;
	return 0;
}