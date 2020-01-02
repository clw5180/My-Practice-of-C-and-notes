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

//�������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��
bool isSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	//�߽�1��pRoot1�Ѿ������꣬��pRoot2û�б����꣨��Ҷ�ӽ�㣩
	if (pRoot2 && !pRoot1) {
		return false;
	}
	//�߽�2��pRoot2�Ѿ������꣨�Ѿ�����Ҷ�ӵ�Ҷ�ӣ�
	else if (!pRoot2) {
		return true;
	}
	//�����߼�
	else {
		if (pRoot2->val == pRoot1->val) {
			return (isSubtree(pRoot1->left, pRoot2->left) && isSubtree(pRoot1->right, pRoot2->right));
		}
		else {
			return false;
		}
	}
}

//�������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��
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
		if (result) //����������ֱ�ӷ���
		{
			return result;
		}
		else //���������������ô�����ݹ飬��root�����������������ǲ����ӽṹ
		{
			return (HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2));
		}
	}
}

int main()
{
    
	return 0;
}