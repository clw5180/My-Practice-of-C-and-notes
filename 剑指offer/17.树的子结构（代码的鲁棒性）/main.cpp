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

//输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
bool isSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	//边界1：pRoot1已经遍历完，但pRoot2没有遍历完（到叶子结点）
	if (pRoot2 && !pRoot1) {
		return false;
	}
	//边界2：pRoot2已经遍历完（已经到了叶子的叶子）
	else if (!pRoot2) {
		return true;
	}
	//核心逻辑
	else {
		if (pRoot2->val == pRoot1->val) {
			return (isSubtree(pRoot1->left, pRoot2->left) && isSubtree(pRoot1->right, pRoot2->right));
		}
		else {
			return false;
		}
	}
}

//输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	
	if (!pRoot1 || !pRoot2) {
		return false;
	}
	else {
		bool result = false;
		if (pRoot2->val == pRoot1->val) {
			result = isSubtree(pRoot1, pRoot2);
		}
		if (result) //是子树，就直接返回
		{
			return result;
		}
		else //如果不是子树，那么继续递归，看root的左子树，右子树是不是子结构
		{
			return (HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2));
		}
	}
}

int main()
{
    
	return 0;
}