#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isNumeric(char* string)
{
	if (string == NULL)
		return false;
	
	bool bDot = false;
	bool bExponent = false;
	bool bSign = false;
	//int m = 0;   //ָ������m*E��n�η�

	for(int i=0;string[i]!='\0';++i)
	{
		//�ж�������
		if (string[i] == '-' || string[i] == '+')
		{
			//�����һ�γ���+-�Ҳ�����ǰ���e��E�������ߵڶ��γ���+-����e��E��
			if ((!bSign && i != 0 && (string[i - 1] != 'e' && string[i - 1] != 'E')) || 
				(bSign && (string[i-1] != 'e' || string[i - 1] != 'E')))
				return false;
			else
				bSign = true;
		}

		//�ж�С����
		else if (string[i] == '.')
		{
			if (bDot || bExponent) //clw note��ע�⣬E���治�ܽ�С���㣬ע�⣡
				return false;
			else
				bDot = true;
		}

		//�ж�e��E
		else if (string[i] == 'e' || string[i] == 'E')
		{
			if(bExponent)
				return false;
			else  //��һ�γ���e��E 
			{
				//������Ҫ��֤ǰ����1~9.0~9��1~9����ʽ
				if (i == strlen(string) - 1)
					return false;
				bExponent = true;
			}
		}

		//�������ַ���0~9֮��������ַ�����false
		else if (string[i] - '0' < 0 || string[i] - '0' > 9)
			return false;
	}
	return true;
}


//���ѷ���1������ⷨ
//bool isNumeric(char* str) {
//	// ��Ƿ��š�С���㡢e�Ƿ���ֹ�
//	bool sign = false, decimal = false, hasE = false;
//	for (int i = 0; i < strlen(str); i++) {
//		if (str[i] == 'e' || str[i] == 'E') {
//			if (i == strlen(str) - 1) return false; // e����һ��Ҫ������
//			if (hasE) return false;  // ����ͬʱ��������e
//			hasE = true;
//		}
//		else if (str[i] == '+' || str[i] == '-') {
//			// �ڶ��γ���+-���ţ�����������e֮��
//			if (sign && str[i - 1] != 'e' && str[i - 1] != 'E') return false;
//			// ��һ�γ���+-���ţ��Ҳ������ַ�����ͷ����Ҳ���������e֮��
//			if (!sign && i > 0 && str[i - 1] != 'e' && str[i - 1] != 'E') return false;
//			sign = true;
//		}
//		else if (str[i] == '.') {
//			// e���治�ܽ�С���㣬С���㲻�ܳ�������
//			if (hasE || decimal) return false;
//			decimal = true;
//		}
//		else if (str[i] < '0' || str[i] > '9') // ���Ϸ��ַ�
//			return false;
//	}
//	return true;
//}


//���ѷ���2��������ʽ
////������ʽ�ⷨ
//public class Solution {
//	public boolean isNumeric(char[] str) {
//		String string = String.valueOf(str);
//		return string.matches("[\\+\\-]?\\d*(\\.\\d+)?([eE][\\+\\-]?\\d+)?");
//	}
//}
///*
//���¶�������н���:
//[\\+\\-]?            -> ���򸺷��ų������
//\\d*                 -> ���������Ƿ���֣���-.34 �� +3.34������
//(\\.\\d+)?           -> �������С���㣬��ôС���������������֣�
//						����һ�𲻳���
//([eE][\\+\\-]?\\d+)? -> �������ָ�����֣���ôe��E�϶����֣�+��-���Բ����֣�
//						�����ű�����������������������ֶ�������
//*/
//
//
////�μ���ָoffer
//public class Solution {
//	private int index = 0;
//
//	public boolean isNumeric(char[] str) {
//		if (str.length < 1)
//			return false;
//
//		boolean flag = scanInteger(str);
//
//		if (index < str.length && str[index] == '.') {
//			index++;
//			flag = scanUnsignedInteger(str) || flag;
//		}
//
//		if (index < str.length && (str[index] == 'E' || str[index] == 'e')) {
//			index++;
//			flag = flag && scanInteger(str);
//		}
//
//		return flag && index == str.length;
//
//	}
//
//	private boolean scanInteger(char[] str) {
//		if (index < str.length && (str[index] == '+' || str[index] == '-'))
//			index++;
//		return scanUnsignedInteger(str);
//
//	}
//
//	private boolean scanUnsignedInteger(char[] str) {
//		int start = index;
//		while (index < str.length && str[index] >= '0' && str[index] <= '9')
//			index++;
//		return start < index; //�Ƿ��������
//	}
//}



int main()
{
	cout << isNumeric("+500");
	cout << isNumeric("123.45e+6");
	return 0;
}