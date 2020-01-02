#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

//网友方案1：栈解法，有点难理解
//int longestValidParentheses(string s) 
//{
//	stack<int> myStack;  
//	myStack.push(0);
//	int res = 0;
//	for (int i = 0; i < s.length(); i++) 
//	{
//		if (s[i] == '(') 
//		{
//			myStack.push(i + 1);
//		}
//		else 
//		{
//			myStack.pop();
//			if (myStack.size()) 
//			{
//				res = max(res, i + 1 - myStack.top());
//			}
//			else 
//			{
//				myStack.push(i + 1);
//			}
//		}
//	}
//	return res;
//}

/*
//网友方案2：栈解法好理解的版本
需要利用一个变量start来记录有效子串的起始下标，res表示答案。
遍历所有字符

如果当前字符s[index]为'('，将index入栈
否则判断栈是否为空：

如果为空，则说明这个右括号无效，不影响结果，start = index + 1
如果不为空，则出栈，即找到一个左括号和它匹配

如果栈空，则说明从start到index的匹配完了，res = max(res, index - start + 1)
如果栈不为空，则res = max(res, index - s[栈顶])，即栈顶 + 1 ~~index都匹配了

作者：xingzai
链接：https ://www.jianshu.com/p/e992c930ace7
*/

//int longestValidParentheses(string s) 
//{
//	int res = 0, start = 0;
//	stack<int> m;
//	for (int i = 0; i < s.size(); ++i) 
//	{
//		if (s[i] == '(')
//			m.push(i);
//		else 
//		{
//			if (m.empty())
//				start = i + 1;
//			else 
//			{
//				m.pop();
//				res = m.empty() ? max(res, i - start + 1) : max(res, i - m.top());
//			}
//		}
//	}
//	return res;
//}

//网友方案3：动态规划 逆向DP
//https://www.jianshu.com/p/e992c930ace7
int longestValidParentheses(string s) 
{
	if (s.empty()) return 0;
	vector<int> dp(s.size(), 0);
	int res = 0;
	for (int i = s.size() - 2; i >= 0; --i) 
	{
		if (s[i] == '(') {
			int j = i + dp[i + 1] + 1;
			if (s[j] == ')' && j < s.size()) 
			{
				dp[i] = dp[i + 1] + 2;
				if (j+1 < s.size())
					dp[i] += dp[j+1];
			}
			res = max(res, dp[i]);
		}
	}
	return res;
}

int main()
{
	//string myStr = "())(())()()";
	//string myStr = "(()())";
	//string myStr = "()";
	//string myStr = ")()())";
	string myStr = "((()))()";
	cout << longestValidParentheses(myStr) << endl;
	return 0;
}