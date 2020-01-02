#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
0��0�η��ǲ����ڵģ���ȷ�ĸ���Ӧ�����κη�0����0�η���Ϊ1��0���κη�0�η���Ϊ0.
����˵��Ϊʲô�κ�����0�η���Ϊ1�����ǳ����ж�������ģ����磺
2^4/2^4=2^0=1
��һ������0�η�����������κη�0�η�����a^b(a,b����Ϊ0)��������������̶���Ϊ����0�η���a^0=a^b/a^b=1
�����a��0�Ļ��������0^b/0^b(b��Ϊ0)����Ȼ0����0��û����ġ����0��0�η���������͵ȼ���0����0û����һ����
*/
//�ҵķ�����
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

//���ѷ�����
/**
 * 1.ȫ�濼��ָ���������������Ƿ�Ϊ��������
 * 2.д��ָ���Ķ����Ʊ�����13���Ϊ������1101��
 * 3.����:10^1101 = 10^0001*10^0100*10^1000��
 * 4.ͨ��&1��>>1����λ��ȡ1101��Ϊ1ʱ����λ����ĳ����۳˵����ս����
 */
	public double Power(double base, int n) {
	double res = 1, curr = base;
	int exponent;
	if (n > 0) {
		exponent = n;
	}
	else if (n < 0) {
		if (base == 0)
			throw new RuntimeException("��ĸ����Ϊ0");
		exponent = -n;
	}
	else {// n==0
		return 1;// 0��0�η�
	}
	while (exponent != 0) {
		if ((exponent & 1) == 1)
			res *= curr;
		curr *= curr;// ����
		exponent >>= 1;// ����һλ
	}
	return n >= 0 ? res : (1 / res);
}

int main()
{
	cout << Power(2, 3) << endl;
	cout << Power(2, -3) << endl;
	return 0;
}