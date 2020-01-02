#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

/*
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数
（时间复杂度应为O（1））
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