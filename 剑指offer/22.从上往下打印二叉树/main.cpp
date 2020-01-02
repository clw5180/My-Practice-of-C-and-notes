#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//没做出来，参考剑指offer的思路，P171~173
vector<int> PrintFromTopToBottom(TreeNode* root) 
{
	if (root == NULL)
		return {};
	vector<int> vec;
	deque<TreeNode*> deque;

	
	deque.push_back(root);

	while (deque.size())
	{
		TreeNode *pNode = deque.front();
		deque.pop_front();

		vec.push_back(pNode->val);

		if(pNode->left)
			deque.push_back(pNode->left);
		if(pNode->right)
			deque.push_back(pNode->right);
	}

	return vec;
}

int main()
{
    
	return 0;
}