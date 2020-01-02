#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
	void push(int node) 
	{
		stack1.push(node);
	}

	int pop() 
	{
		//���stack2Ϊ�գ��Ȱ�stack1����Ķ��ƹ���
		if (stack2.empty())
		{
			int len = stack1.size();
			for (int i = 0; i < len; ++i) //clw note��������������Լ�дΪwhile(!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		//ֱ�Ӵ������濪ʼ��
		int tmp = stack2.top();  
		stack2.pop();
		return tmp;	 
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};


int main()
{
	Solution solution;
	solution.push(1);
	solution.push(2);
	cout << solution.pop() << " ";
	cout << solution.pop() << " ";
	
	return 0;
}