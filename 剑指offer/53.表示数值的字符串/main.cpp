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
	//int m = 0;   //指数形如m*E的n次方

	for(int i=0;string[i]!='\0';++i)
	{
		//判断正负号
		if (string[i] == '-' || string[i] == '+')
		{
			//如果第一次出现+-且不在最前面或e、E处，或者第二次出现+-不在e或E处
			if ((!bSign && i != 0 && (string[i - 1] != 'e' && string[i - 1] != 'E')) || 
				(bSign && (string[i-1] != 'e' || string[i - 1] != 'E')))
				return false;
			else
				bSign = true;
		}

		//判断小数点
		else if (string[i] == '.')
		{
			if (bDot || bExponent) //clw note：注意，E后面不能接小数点，注意！
				return false;
			else
				bDot = true;
		}

		//判断e或E
		else if (string[i] == 'e' || string[i] == 'E')
		{
			if(bExponent)
				return false;
			else  //第一次出现e或E 
			{
				//好像不需要保证前面是1~9.0~9或1~9的形式
				if (i == strlen(string) - 1)
					return false;
				bExponent = true;
			}
		}

		//除上述字符和0~9之外的其他字符，则false
		else if (string[i] - '0' < 0 || string[i] - '0' > 9)
			return false;
	}
	return true;
}


//网友方案1：常规解法
//bool isNumeric(char* str) {
//	// 标记符号、小数点、e是否出现过
//	bool sign = false, decimal = false, hasE = false;
//	for (int i = 0; i < strlen(str); i++) {
//		if (str[i] == 'e' || str[i] == 'E') {
//			if (i == strlen(str) - 1) return false; // e后面一定要接数字
//			if (hasE) return false;  // 不能同时存在两个e
//			hasE = true;
//		}
//		else if (str[i] == '+' || str[i] == '-') {
//			// 第二次出现+-符号，则必须紧接在e之后
//			if (sign && str[i - 1] != 'e' && str[i - 1] != 'E') return false;
//			// 第一次出现+-符号，且不是在字符串开头，则也必须紧接在e之后
//			if (!sign && i > 0 && str[i - 1] != 'e' && str[i - 1] != 'E') return false;
//			sign = true;
//		}
//		else if (str[i] == '.') {
//			// e后面不能接小数点，小数点不能出现两次
//			if (hasE || decimal) return false;
//			decimal = true;
//		}
//		else if (str[i] < '0' || str[i] > '9') // 不合法字符
//			return false;
//	}
//	return true;
//}


//网友方案2：正则表达式
////正则表达式解法
//public class Solution {
//	public boolean isNumeric(char[] str) {
//		String string = String.valueOf(str);
//		return string.matches("[\\+\\-]?\\d*(\\.\\d+)?([eE][\\+\\-]?\\d+)?");
//	}
//}
///*
//以下对正则进行解释:
//[\\+\\-]?            -> 正或负符号出现与否
//\\d*                 -> 整数部分是否出现，如-.34 或 +3.34均符合
//(\\.\\d+)?           -> 如果出现小数点，那么小数点后面必须有数字；
//						否则一起不出现
//([eE][\\+\\-]?\\d+)? -> 如果存在指数部分，那么e或E肯定出现，+或-可以不出现，
//						紧接着必须跟着整数；或者整个部分都不出现
//*/
//
//
////参见剑指offer
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
//		return start < index; //是否存在整数
//	}
//}



int main()
{
	cout << isNumeric("+500");
	cout << isNumeric("123.45e+6");
	return 0;
}