#include <iostream>
#include <string>
#include <vector>

using namespace std;

//我的方案：用时和占用内存基本已经最佳，就是不够简洁
bool isPalindrome(string s) 
{
	int lenStr = s.size();
	if (lenStr == 0)
		return true;
	char tmp;
	int j = lenStr - 1;
	for (int i = 0; i < lenStr;++i)
	{
		if (isalpha(s[i]) || isdigit(s[i]))
		{
			tmp = s[i];
			while (j > 0)
			{
				if ((isalpha(s[j]) && tolower(s[j]) != s[i] && toupper(s[j]) != s[i])
					|| (isdigit(s[j]) && s[j]!=s[i]))
					return false;
				else if (!isalpha(s[j]) && !isdigit(s[j]))
					--j;
				else
				{
					--j;
					break;
				}
					
			}
		}
		if (i >= j)
			return true;
	}
	return false;
}

/*
	网友方案：
	I think this problem, if asked at an interview, is to test whether a candidate 
	is able to handle all edge cases systematically and write clean codes :-)
	To avoid using if-else to handle lowercase and uppercase letters, I call tolower to 
	convert all of them to lower case ones before comparison. And tolower will not change a number.

bool isPalindrome(string s)
{
	int n = s.size(), l = 0, r = n - 1;
	while (l < r)
	{
		while (l < r && !isalnum(s[l]))
		{
			l++;
		}
		while (l < r && !isalnum(s[r]))
		{
			r--;
		}
		if (tolower(s[l++]) != tolower(s[r--]))
		{
			return false;
		}
	}
	return true;
}

 */



int main()
{
	//cout << isPalindrome(string("1b1")) << endl;
	string myStr = "A man, a plan, a canal: Panama";
	cout << isPalindrome(myStr) << endl;
	//cout << isPalindrome(string("asdfdsb")) << endl;
	//cout << isPalindrome(string("0P")) << endl;
	return 0;
}