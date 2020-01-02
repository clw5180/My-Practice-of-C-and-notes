#include <iostream>
#include <string>
#include <vector>

using namespace std;

/***

�ܽ᣺
��1��char�����ַ�תint�ķ�����ch - '0'
��2��ע��string��insert()����ʹ�ã�
��3������charתstring�ķ�����string(1, 'a'); �мǲ���д��string('a')����
��4�������Ŀ�������������Ƶĺͣ�������ֱ�Ӱѽ϶̵������油0����֤������ͬ���������Լ򻯴��룻

***/

//�ҵĽ��������
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