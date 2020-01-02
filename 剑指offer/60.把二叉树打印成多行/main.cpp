#include <iostream>
#include <string>
#include <vector>
#include <queue>

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

	curDeque.push_back(pRoot);
	while (curDeque.size())
	{
		deque<TreeNode*> nextDeque;
		vector<int> vec;
		while (curDeque.size())
		{
			TreeNode* pNode = curDeque.front();
			curDeque.pop_front();
			vec.push_back(pNode->val);

			if (pNode->left)
				nextDeque.push_back(pNode->left);
			if (pNode->right)
				nextDeque.push_back(pNode->right);
		}

		resultVec.push_back(vec);
		curDeque = nextDeque;
	}

	return resultVec;
}


int main()
{

	return 0;
}