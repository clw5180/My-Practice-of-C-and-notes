#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};


vector<vector<int> > Print(TreeNode* pRoot)
{
	if (pRoot == NULL)
		return {};

	vector<vector<int>> resultVec;
	deque<TreeNode*> curDeque;

	int i = 0;
	curDeque.push_front(pRoot);
	while (curDeque.size())
	{
		deque<TreeNode*> nextDeque;
		vector<int> vec;
		while (curDeque.size())
		{
			TreeNode* pNode = curDeque.front();
			curDeque.pop_front();
			vec.push_back(pNode->val);

			if (i % 2 == 0) //判断行的奇偶
			{
				if (pNode->left)
					nextDeque.push_front(pNode->left); //如果该行是偶数行，则逆序进入nextDeque
				if (pNode->right)
					nextDeque.push_front(pNode->right);
			}
			else
			{
				if (pNode->right)  
					nextDeque.push_front(pNode->right); 
				if (pNode->left)
					nextDeque.push_front(pNode->left);
			}
		}
		resultVec.push_back(vec);
		curDeque = nextDeque;
		++i;
	}

	return resultVec;
}

int main()
{
	
	return 0;
}