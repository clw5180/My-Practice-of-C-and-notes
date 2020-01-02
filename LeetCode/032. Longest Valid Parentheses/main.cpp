#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

//���ѷ���1��ջ�ⷨ���е������
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
//���ѷ���2��ջ�ⷨ�����İ汾
��Ҫ����һ������start����¼��Ч�Ӵ�����ʼ�±꣬res��ʾ�𰸡�
���������ַ�

�����ǰ�ַ�s[index]Ϊ'('����index��ջ
�����ж�ջ�Ƿ�Ϊ�գ�

���Ϊ�գ���˵�������������Ч����Ӱ������start = index + 1
�����Ϊ�գ����ջ�����ҵ�һ�������ź���ƥ��

���ջ�գ���˵����start��index��ƥ�����ˣ�res = max(res, index - start + 1)
���ջ��Ϊ�գ���res = max(res, index - s[ջ��])����ջ�� + 1 ~~index��ƥ����

���ߣ�xingzai
���ӣ�https ://www.jianshu.com/p/e992c930ace7
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

//���ѷ���3����̬�滮 ����DP
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