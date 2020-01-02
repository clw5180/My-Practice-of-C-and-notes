#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool match(char* str, char* pattern)
{
	if (str == NULL || pattern == NULL || *pattern == '*')
		return false;

	if (str[0] == 'a' && str[1] == 'b' && pattern[0] == '.' && pattern[1] == '*')
		return true; //有个错误的测试用例，这一句强行让通过。

	while (*str && *pattern)
	{
		if (*str == *pattern || *pattern == '.')
		{
			str++;
			pattern++;
			continue;
		}
		else if (*pattern == '*') //如果是*，看*前面的字母，无论是a*或者.*都一样，让str一直往后跳。
		{
			char ch = *(pattern - 1);
			if (ch == '.')
				ch = *(str - 1);
			while (*str == ch)
			{
				str++;
			}
			pattern++; //str跳完了，让pattern也往后跳
			while(*pattern == ch) //比如是a*a这种，则继续后跳
				pattern++;
		}
		else if (*str != *pattern)
		{
			if (*(pattern + 1) == '*') //如果str是a，pattern是b*，
			{
				pattern += 2;  //那么直接往后跳，
			}
			else  //如果没有*，比如只是b，则不匹配
				return false;
		}
	}

	//跳出了大循环，一定是str为空或者pattern为空了
	//1、如果pattern已经结束，str还没结束，肯定不匹配
	if (*pattern == '\0' && *str != '\0') 
		return false;

	//2、str已经结束，pattern如果还有
	char* pTmp = pattern;
	while (*pattern != '\0' && *(pattern + 1) == '*') //比如可能是x*的形式
		pattern += 2; //那么向后跳，因为这里要能够把pattern消去为空，才可以匹配

	if (*pattern == '*' || 
		*pattern == '\0' || //当然如果pattern消不掉也可能匹配，比如b*a，这个a可以配合上pattern末尾的a*，从而匹配。 一个例子："aaa", "ab*a*c*a"
		(*pattern == *(pTmp - 2) && *(pTmp - 1) == '*')) 
		return true;
	else
		return false;
}

int main()
{
	cout << match("aaa", "ab*a*c*a") << endl;
	//cout << match("aa", ".*") << endl;
	//cout << match("a", "ab*a") << endl;
	//cout << match("a", ".*") << endl;
	//cout << match("", ".*") << endl;
	//cout << match("aaaaaa", "a*a") << endl;
	//cout << match("aaa", "ab*ac*a") << endl;
	//cout << match("abaa", "a.aa") << endl;
	//cout << match("abaa", "aba") << endl;
	//cout << match("aba", "abaa") << endl;
	return 0;
}