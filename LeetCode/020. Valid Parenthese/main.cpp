#include <iostream>
#include <stack>

using namespace std;

//我的方案：Runtime: 4 ms, faster than 97.76%
class Solution
{
public:
	bool IsMatch(const char& c1, const char& c2)
	{
		if ((c1 == '(' && c2 == ')') ||
			(c1 == '{' && c2 == '}') ||
			(c1 == '[' && c2 == ']'))
			return true;
		else
			return false;
	}

	bool isValid(string s)
	{
		stack<char> myStack;
		int len = s.size();
		for (int i = 0; i < len; ++i)
		{
			if (s[i] == '(' || s[i] == '{' || s[i] == '[')
				myStack.push(s[i]);
			else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
			{
				if (myStack.empty() || !IsMatch(myStack.top(), s[i]))
					return false;
				else
				{
					myStack.pop();
				}
			}
			else //防止除了括号的其他字符进来干扰
				return false;
		}
		return myStack.empty();
	}
};


int main()
{
	string myStr = "()[]{}";
	//string myStr = "([)";
	if (isValid(myStr))
	    cout << "Valid Parenthese!" << endl;
	else
		cout << "Invalid Parenthese!" << endl;
	return 0;
}
