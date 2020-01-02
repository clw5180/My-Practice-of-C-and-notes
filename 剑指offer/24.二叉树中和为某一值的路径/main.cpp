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
		val(x), left(NULL), right(NULL)
	{}
};


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


void FindEqual(TreeNode* root, int expectNumber, vector<int> vec, vector<vector<int>>& resultVec)
{
	if (root == NULL)
	{
		if (expectNumber == 0)
		{
			resultVec.push_back(vec);
		}
		return;
	}
		
	vec.push_back(root->val);
	if(root->left == NULL && root->right == NULL) //如果左右子树都为空，只记录一次
		FindEqual(root->left, expectNumber - root->val, vec, resultVec);
	else
	{
		FindEqual(root->left, expectNumber - root->val, vec, resultVec);
		FindEqual(root->right, expectNumber - root->val, vec, resultVec);
	}
}

static bool CompareVsize(vector<int> vec1, vector<int> vec2)
{
	return vec1.size() > vec2.size();
}

vector<vector<int> > FindPath(TreeNode* root, int expectNumber)
{
	if (root == NULL)
		return {};

	vector<int> vec;
	vector<vector<int>> resultVec;
	FindEqual(root, expectNumber, vec, resultVec);
	
	//题目要求数组长度大的数组靠前
	sort(resultVec.begin(), resultVec.end(), CompareVsize);

	return resultVec;
}

int main()
{
	//vector<int> pre = { 8,6,5,7,10,9,11 };
	//vector<int> vin = { 5,6,7,8,9,10,11 };
	/*vector<int> pre = { 8,10,5,7,6,9,11 };
	vector<int> vin = { 5,10,7,8,9,6,11 };*/
	vector<int> pre = { 1,2,7,2,3,4, };
	vector<int> vin = { 7,2,1,2,3,4 };
	TreeNode *myTree = reConstructBinaryTree(pre, vin);
	//FindPath(myTree, 23);
	FindPath(myTree, 10);
	return 0;
}