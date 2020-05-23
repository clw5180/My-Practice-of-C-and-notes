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

//�������
void PreOrder(TreeNode* root)
{
	if (root == NULL)
		return;
	printf("data:%d\n", root->val);
	PreOrder(root->left);
	PreOrder(root->right);
}

//�������
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

	//�����ӡ����������֤�������
	PreOrder(myTree);

	InOrder(myTree);
}


/*
/////////////////////////////////
//////// �ٷ��������ٶȺ��ڴ涼���˺ܶ࣡

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

		// ǰ������еĵ�һ���ڵ���Ǹ��ڵ�
		int preorder_root = preorder_left;
		// ����������ж�λ���ڵ�
		int inorder_root = index[preorder[preorder_root]];

		// �ȰѸ��ڵ㽨������
		TreeNode* root = new TreeNode(preorder[preorder_root]);
		// �õ��������еĽڵ���Ŀ
		int size_left_subtree = inorder_root - inorder_left;
		// �ݹ�ع����������������ӵ����ڵ�
		// ��������С��� ��߽�+1 ��ʼ�� size_left_subtree����Ԫ�ؾͶ�Ӧ����������С��� ��߽� ��ʼ�� ���ڵ㶨λ-1����Ԫ��
		root->left = myBuildTree(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
		// �ݹ�ع����������������ӵ����ڵ�
		// ��������С��� ��߽�+1+�������ڵ���Ŀ ��ʼ�� �ұ߽硹��Ԫ�ؾͶ�Ӧ����������С��� ���ڵ㶨λ+1 �� �ұ߽硹��Ԫ��
		root->right = myBuildTree(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);
		return root;
	}

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		int n = preorder.size();
		// �����ϣӳ�䣬�������ǿ��ٶ�λ���ڵ�
		for (int i = 0; i < n; ++i)
		{
			index[inorder[i]] = i;
		}
		return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
	}
};
*/