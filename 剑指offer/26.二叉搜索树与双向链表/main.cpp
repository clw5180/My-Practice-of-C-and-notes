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

void Inorder(TreeNode* pRoot)
{
	if (pRoot == NULL)
		return;

	Inorder(pRoot->left);
	Inorder(pRoot->right);
}


// ����һ�ö��������������ö���������ת����һ�������˫������Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
// �ο�����˼·�����ӣ�https://www.nowcoder.com/questionTerminal/947f6eb80d944a84850b0538bf0ec3a5
TreeNode* Convert(TreeNode* pRootOfTree)
{
	if (pRootOfTree == NULL)
		return NULL;

	if (pRootOfTree->left == NULL && pRootOfTree->right == NULL)
		return pRootOfTree;

	//���㴦��
	//�������������˫��������������ͷ�ڵ㣨��ΪConvert�����ȷ������㣬��˻�һֱ�����ߣ�������ߣ�Ҳ��������ͷ����
	TreeNode* left = Convert(pRootOfTree->left);
	TreeNode* p = left;
	//��λ��������˫�������һ���ڵ�
	while (p != NULL && p->right != NULL) 
	{
		p = p->right;
	}
	//�������������Ϊ�յĻ�������ǰroot׷�ӵ�����������
	if (left != NULL) 
	{
		p->right = pRootOfTree;
		pRootOfTree->left = p;
	}

	//�ҽ�㴦��
	//�������������˫��������������ͷ�ڵ�
	TreeNode *right = Convert(pRootOfTree->right);
	//�������������Ϊ�յĻ�����������׷�ӵ�root�ڵ�֮��
	if (right != NULL)
	{
		right->left = pRootOfTree;
		pRootOfTree->right = right;
	}

	return left != NULL ? left : pRootOfTree;
}



//���������Ľ��ݹ��
//����˼·��
//˼·�뷽�����еĵݹ��һ�£����Ե�2���еĶ�λ�����޸ģ�����һ��ȫ�ֱ�����¼�����������һ���ڵ㡣
//// ��¼������������һ���ڵ㣬�ս��ֻ����Ϊֻ���������ķ�Ҷ�ڵ���Ҷ�ڵ�
//protected TreeNode leftLast = null;
//public TreeNode Convert(TreeNode root) {
//	if (root == null)
//		return null;
//	if (root.left == null && root.right == null) {
//		leftLast = root;// ����һ���ڵ����Ϊ���Ҳ��Ҷ�ڵ�
//		return root;
//	}
//	// 1.�������������˫��������������ͷ�ڵ�
//	TreeNode left = Convert(root.left);
//	// 3.�������������Ϊ�յĻ�������ǰroot׷�ӵ�����������
//	if (left != null) {
//		leftLast.right = root;
//		root.left = leftLast;
//	}
//	leftLast = root;// �����ڵ�ֻ��������ʱ����ø��ڵ�Ϊ���һ���ڵ�
//	// 4.�������������˫��������������ͷ�ڵ�
//	TreeNode right = Convert(root.right);
//	// 5.�������������Ϊ�յĻ�����������׷�ӵ�root�ڵ�֮��
//	if (right != null) {
//		right.left = root;
//		root.right = right;
//	}
//	return left != null ? left : root;
//}


//����һ���ǵݹ��
//����˼·��
//1.��������������ķǵݹ��㷨��
//2.�޸ĵ�ǰ�����ڵ���ǰһ�����ڵ��ָ��ָ��
//import java.util.Stack;
//public TreeNode ConvertBSTToBiList(TreeNode root) {
//	if (root == null)
//		return null;
//	Stack<TreeNode> stack = new Stack<TreeNode>();
//	TreeNode p = root;
//	TreeNode pre = null;// ���ڱ�������������е���һ�ڵ�
//	boolean isFirst = true;
//	while (p != null || !stack.isEmpty()) {
//		while (p != null) {
//			stack.push(p);
//			p = p.left;
//		}
//		p = stack.pop();
//		if (isFirst) {
//			root = p;// ��������������еĵ�һ���ڵ��Ϊroot
//			pre = root;
//			isFirst = false;
//		}
//		else {
//			pre.right = p;
//			p.left = pre;
//			pre = p;
//		}
//		p = p.right;
//	}
//	return root;
//}

int main()
{
    
	return 0;
}