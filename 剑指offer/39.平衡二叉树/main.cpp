#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

int TreeDepth(TreeNode* pRoot)
{
	if (pRoot == NULL)
		return 0;

	return max(TreeDepth(pRoot->left), TreeDepth(pRoot->right)) + 1;
}

bool IsBalanced_Solution(TreeNode* pRoot) 
{
	if (pRoot == NULL)
		return true;

	if (abs(TreeDepth(pRoot->left) - TreeDepth(pRoot->right)) <= 1)
		return true;
}

int main()
{
    
	return 0;
}