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

//我的方案：有问题，比如值全部相同的时候做不出来，比如：5555##55#5
//void Mirror(TreeNode* pRoot)
//{
//	if (pRoot == NULL)
//		return;
//
//	TreeNode* pTmp = pRoot->left;
//	pRoot->left = pRoot->right;
//	pRoot->right = pTmp;
//
//	Mirror(pRoot->left);
//	Mirror(pRoot->right);
//}
//
//void PreOrder(TreeNode* pRoot, vector<int>& vec)
//{
//	if (pRoot == NULL)
//		return;
//
//	vec.push_back(pRoot->val);
//	PreOrder(pRoot->left, vec);
//	PreOrder(pRoot->right, vec);
//}
//
//void InOrder(TreeNode* pRoot, vector<int>& vec)
//{
//	if (pRoot == NULL)
//		return;
//
//	InOrder(pRoot->left, vec);
//	vec.push_back(pRoot->val);
//	InOrder(pRoot->right, vec);
//}
//
//bool isSymmetrical(TreeNode* pRoot)
//{
//	vector<int> vec1;
//	vector<int> vec2;
//	vector<int> vec3;
//	vector<int> vec4;
//	PreOrder(pRoot, vec1);
//	InOrder(pRoot, vec2);
//	Mirror(pRoot);
//	PreOrder(pRoot, vec3);
//	InOrder(pRoot, vec4);
//	if (vec1 == vec3 && vec2 == vec4)
//		return true;
//	else
//		return false;
//}

//网友方案1：递归
bool isSame(TreeNode* p1, TreeNode* p2)
{
	if (p1 == NULL && p2 != NULL)return false;
	if (p2 == NULL && p1 != NULL)return false;
	if (p1 == NULL && p2 == NULL)return true;
	if (p1->val == p2->val) return isSame(p1->right, p2->left) && isSame(p1->left,p2->right);
	else
		return false;
}
bool isSymmetrical(TreeNode* pRoot)
{
	if (pRoot == NULL)return true;
	return isSame(pRoot->left, pRoot->right);
}

int main()
{
	
	return 0;
}