#define _CRT_SECURE_NO_WARINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int FindPos(vector<int>& inorder, int val)
{
	int len = inorder.size();
	for (int i=0; i<= len; ++i)
	{
		if (inorder[i] == val)
			return i;
	}
	return -1;
}


TreeNode* PreInCreate(vector<int>& preorder, vector<int>& inorder)
{
	TreeNode* root = NULL;
	int len = preorder.size();
	if (len > 0)
	{
		root = new TreeNode(preorder[0]);
		int pos = FindPos(inorder, preorder[0]);
		if (pos == -1)
			return NULL;
		vector<int> preLeft(preorder.begin() + 1, preorder.begin() + pos + 1);
		vector<int> inLeft(inorder.begin(), inorder.begin() + pos);
		root->left = PreInCreate(preLeft, inLeft);
		
		vector<int> preRight(preorder.begin() + pos + 1, preorder.begin() + len);
		vector<int> inRight(inorder.begin() + pos + 1, inorder.begin() + len);
		root->right = PreInCreate(preRight, inRight);
	}
	return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
	int lenPre = preorder.size();
	int lenIn = inorder.size();
	if (lenPre <= 0 || lenIn <= 0 || lenPre != lenIn)
		return NULL;
	return PreInCreate(preorder, inorder);
};

//先序遍历
void PreOrder(TreeNode* root)
{
	if (root == NULL)
		return;
	printf("data:%d\n", root->val);
	PreOrder(root->left);
	PreOrder(root->right);
}

//中序遍历
void InOrder(TreeNode* root)
{
	if (root == NULL)
		return;
	InOrder(root->left);
	printf("data:%d\n", root->val);
	InOrder(root->right);
}

int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = { 9, 3, 15, 20, 7 };
    TreeNode *myTree = buildTree(preorder, inorder);

	//先序打印二叉树，验证上述结果
	PreOrder(myTree);

	InOrder(myTree);
}


/*
/////////////////////////////////
//////// 官方做法：速度和内存都好了很多！

class Solution
{
private:
	unordered_map<int, int> index;

public:
	TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right)
	{
		if (preorder_left > preorder_right)
		{
			return nullptr;
		}

		// 前序遍历中的第一个节点就是根节点
		int preorder_root = preorder_left;
		// 在中序遍历中定位根节点
		int inorder_root = index[preorder[preorder_root]];

		// 先把根节点建立出来
		TreeNode* root = new TreeNode(preorder[preorder_root]);
		// 得到左子树中的节点数目
		int size_left_subtree = inorder_root - inorder_left;
		// 递归地构造左子树，并连接到根节点
		// 先序遍历中「从 左边界+1 开始的 size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
		root->left = myBuildTree(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
		// 递归地构造右子树，并连接到根节点
		// 先序遍历中「从 左边界+1+左子树节点数目 开始到 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
		root->right = myBuildTree(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);
		return root;
	}

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		int n = preorder.size();
		// 构造哈希映射，帮助我们快速定位根节点
		for (int i = 0; i < n; ++i)
		{
			index[inorder[i]] = i;
		}
		return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
	}
};
*/