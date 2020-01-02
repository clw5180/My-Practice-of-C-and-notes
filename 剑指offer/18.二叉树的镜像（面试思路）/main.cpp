#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void Mirror(TreeNode *pRoot) 
{
	if (pRoot == NULL)
		return;
	TreeNode* pTmp;
	pTmp = pRoot->left;
	pRoot->left = pRoot->right;
	pRoot->right = pTmp;
	Mirror(pRoot->left);
	Mirror(pRoot->right);
}

int main()
{
    
	return 0;
}