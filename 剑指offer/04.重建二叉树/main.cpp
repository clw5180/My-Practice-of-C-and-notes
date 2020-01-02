#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
����ĳ��������ǰ���������������Ľ�������ؽ����ö����������������ǰ���������������Ľ��
�ж������ظ������֡���������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}��
���ؽ������������ء�
*/

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
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
		subPre_left.push_back(pre[i+1]);
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
	vector<int> pre = {1, 2, 4, 7, 3, 5, 6, 8};
	vector<int> vin = {4, 7, 2, 1, 5, 3, 8, 6};
	TreeNode *myTree = reConstructBinaryTree(pre, vin);
	return 0;
}