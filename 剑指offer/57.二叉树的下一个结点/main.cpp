#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};

TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
	if (pNode == NULL)
		return NULL;

	//如果有右孩子，找到最左的结点
	if (pNode->right)
	{
		TreeLinkNode* pTmp = pNode->right;
		while (pTmp->left)
		{
			pTmp = pTmp->left;
		}
		return pTmp;
	}
	
	//否则（没有右孩子），向上遍历，找父亲。
	while(pNode->next) 
	{
		TreeLinkNode *pRoot = pNode->next;
		if (pNode == pRoot->left) //一直判断如果该结点是其父结点左孩子，返回其父结点
		{
			return pRoot;
		}
		pNode = pRoot;
	}

	return NULL; //如果从上面循环出来了，有两种可能：
	/*
		   1、只有根结点和左子树，没有右子树，直接GetNext(根结点)，
			   返回NULL；
		   2、GetNext(右子树的最后一个结点)，一路上来到根结点依然没有在
			while中满足条件然后return，直到最后GetNext(根结点)，返回NULL；
	*/
}

int main()
{
	
	return 0;
}