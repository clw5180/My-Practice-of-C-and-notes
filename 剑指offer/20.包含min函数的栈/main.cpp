#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

/*
����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��������СԪ�ص�min����
��ʱ�临�Ӷ�ӦΪO��1����
*/
class Solution {
public:
	void push(int value) 
	{
		if (m_stack_data.empty())
		{
			m_stack_data.push(value);
			m_stack_min.push(value);
		}
		else
		{
			if (value <= m_stack_data.top())
			{

				m_stack_min.push(value);
			}
			else
			{
				m_stack_min.push(m_stack_min.top());
			}
			m_stack_data.push(value);
		}	
	}
	void pop() 
	{
		m_stack_data.pop();
		m_stack_min.pop();
	}
	int top() 
	{
		return m_stack_data.top();
	}
	int min() 
	{
		return m_stack_min.top();
	}
private:
	stack<int> m_stack_data;
	stack<int> m_stack_min;
};

int main()
{
	Solution solution;
	solution.push(2);
	solution.push(3);
	solution.push(1);
	solution.push(4);
	cout << solution.min();
	solution.pop();
	cout << solution.min();
	return 0;
}