#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

//我的方案：
//子函数
void InorderKth(TreeNode *pRoot, int& k, TreeNode*& pNode)
{
	if (pRoot == NULL)
		return;
	if (k == 0)
		return;

	InorderKth(pRoot->left, k, pNode);
	k--;
	if (k == 0)
	{
		pNode = pRoot;
		return;
	}
	InorderKth(pRoot->right, k, pNode);
}

//主方法：
TreeNode* KthNode(TreeNode* pRoot, int k)
{
	//中序遍历
	int &a = k;
	TreeNode* pNode = NULL;
	InorderKth(pRoot, a, pNode);
	return pNode;
}

//创建一棵二叉树，便于调试
TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)
{
	if (pre.empty() || vin.empty())
		return NULL;
	int len = pre.size();
	if (len == 1)
	{
		TreeNode* leaveNode = new TreeNode(pre[0]);
		return leaveNode;
	}

	TreeNode* BiTreeNode = new TreeNode(pre[0]);

	vector<int> subPre_left, subVin_left, subPre_right, subVin_right;
	int index = -1;
	for (int i = 0; vin[i] != pre[0]; ++i)
	{
		subPre_left.push_back(pre[i + 1]);
		subVin_left.push_back(vin[i]);
		index = i;
	}
	for (int i = index + 2; i < len; ++i)
	{
		subPre_right.push_back(pre[i]);
		subVin_right.push_back(vin[i]);
	}


	BiTreeNode->left = reConstructBinaryTree(subPre_left, subVin_left);
	BiTreeNode->right = reConstructBinaryTree(subPre_right, subVin_right);

	return BiTreeNode;
}

int main()
{
	vector<int> pre = { 8,6,5,7,10,9,11 };
	vector<int> vin = { 5,6,7,8,9,10,11 };
	TreeNode *myTree = reConstructBinaryTree(pre, vin);
	TreeNode *p = NULL; 
	p = KthNode(myTree, 1);
	cout << p->val << endl;
	p = KthNode(myTree, 2);
	cout << p->val << endl;
	p = KthNode(myTree, 3);
	cout << p->val << endl;
	p = KthNode(myTree, 4);
	cout << p->val << endl;
	p = KthNode(myTree, 5);
	cout << p->val << endl;
	return 0;
}