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
		//如果stack2为空，先把stack1里面的都移过来
		if (stack2.empty())
		{
			int len = stack1.size();
			for (int i = 0; i < len; ++i) //clw note：上面这两句可以简写为while(!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		//直接从最上面开始弹
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