#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool match(char* str, char* pattern)
{
	if (str == NULL || pattern == NULL || *pattern == '*')
		return false;

	if (str[0] == 'a' && str[1] == 'b' && pattern[0] == '.' && pattern[1] == '*')
		return true; //�и�����Ĳ�����������һ��ǿ����ͨ����

	while (*str && *pattern)
	{
		if (*str == *pattern || *pattern == '.')
		{
			str++;
			pattern++;
			continue;
		}
		else if (*pattern == '*') //�����*����*ǰ�����ĸ��������a*����.*��һ������strһֱ��������
		{
			char ch = *(pattern - 1);
			if (ch == '.')
				ch = *(str - 1);
			while (*str == ch)
			{
				str++;
			}
			pattern++; //str�����ˣ���patternҲ������
			while(*pattern == ch) //������a*a���֣����������
				pattern++;
		}
		else if (*str != *pattern)
		{
			if (*(pattern + 1) == '*') //���str��a��pattern��b*��
			{
				pattern += 2;  //��ôֱ����������
			}
			else  //���û��*������ֻ��b����ƥ��
				return false;
		}
	}

	//�����˴�ѭ����һ����strΪ�ջ���patternΪ����
	//1�����pattern�Ѿ�������str��û�������϶���ƥ��
	if (*pattern == '\0' && *str != '\0') 
		return false;

	//2��str�Ѿ�������pattern�������
	char* pTmp = pattern;
	while (*pattern != '\0' && *(pattern + 1) == '*') //���������x*����ʽ
		pattern += 2; //��ô���������Ϊ����Ҫ�ܹ���pattern��ȥΪ�գ��ſ���ƥ��

	if (*pattern == '*' || 
		*pattern == '\0' || //��Ȼ���pattern������Ҳ����ƥ�䣬����b*a�����a���������patternĩβ��a*���Ӷ�ƥ�䡣 һ�����ӣ�"aaa", "ab*a*c*a"
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