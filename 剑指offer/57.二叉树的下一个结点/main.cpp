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

	//������Һ��ӣ��ҵ�����Ľ��
	if (pNode->right)
	{
		TreeLinkNode* pTmp = pNode->right;
		while (pTmp->left)
		{
			pTmp = pTmp->left;
		}
		return pTmp;
	}
	
	//����û���Һ��ӣ������ϱ������Ҹ��ס�
	while(pNode->next) 
	{
		TreeLinkNode *pRoot = pNode->next;
		if (pNode == pRoot->left) //һֱ�ж�����ý�����丸������ӣ������丸���
		{
			return pRoot;
		}
		pNode = pRoot;
	}

	return NULL; //���������ѭ�������ˣ������ֿ��ܣ�
	/*
		   1��ֻ�и�������������û����������ֱ��GetNext(�����)��
			   ����NULL��
		   2��GetNext(�����������һ�����)��һ·�������������Ȼû����
			while����������Ȼ��return��ֱ�����GetNext(�����)������NULL��
	*/
}

int main()
{
	
	return 0;
}