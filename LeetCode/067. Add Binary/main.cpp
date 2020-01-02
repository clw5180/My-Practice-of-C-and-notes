#include <iostream>
#include <string>
#include <vector>

using namespace std;

/***

总结：
（1）char数字字符转int的方法：ch - '0'
（2）注意string的insert()方法使用；
（3）另外char转string的方法：string(1, 'a'); 切记不能写成string('a')！！
（4）这个题目是求两个二进制的和，我这里直接把较短的数后面补0，保证长度相同，这样可以简化代码；

***/

//我的解决方案：
string addBinary(string a, string b) 
{
	int lenA = a.size();
	int lenB = b.size();

	int nCarry = 0;
	string nSum;

	if (lenB < lenA) // if b shorter than a, Residual bit fo b fill 0
	{
		for (int i = lenB; i < lenA; ++i)
		{
			b.insert(0, "0");
		}
		lenB = lenA;
	}
	else if (lenA < lenB) // if a shorter than b, Residual bit of a fill 0
	{
		for (int i = lenA; i < lenB; ++i)
		{
			a.insert(0, "0");
		}
		lenA = lenB;
	}

	for (int i = lenA; i >= 0; --i)
	{
		switch (a[i] - '0' + b[i] - '0' + nCarry)
		{
		case 0:
			nSum.insert(0, "0");
			nCarry = 0;
			break;
		case 1:
			nSum.insert(0, "1");
			nCarry = 0;
			break;
		case 2:
			nSum.insert(0, "0");
			nCarry = 1;
			break;
		case 3:
			nSum.insert(0, "1");
			nCarry = 1;
			break;
		default:
			break;
		}
	}

	if(nCarry == 1)  // final bit
		nSum.insert(0, "1");

	return nSum;
}

int main()
{
	//cout << addBinary("1", "11") << endl;
	//cout << addBinary("1010", "1011") << endl;
	cout << addBinary("100", "110010") << endl;
	return 0;
}