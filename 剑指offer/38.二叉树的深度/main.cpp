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

//网友方案：非递归写法
//int TreeDepth(TreeNode* pRoot)
//{
//	queue<TreeNode*> q;
//	if (!pRoot) return 0;
//	q.push(pRoot);
//	int level = 0;
//	while (!q.empty()) {
//		int len = q.size();
//		level++;
//		while (len--) {
//			TreeNode* tem = q.front();
//			q.pop();
//			if (tem->left) q.push(tem->left);
//			if (tem->right) q.push(tem->right);
//		}
//	}
//	return level;
//}

int main()
{
    
	return 0;
}