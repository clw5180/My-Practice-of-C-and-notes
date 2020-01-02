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


// 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
// 参考网友思路，链接：https://www.nowcoder.com/questionTerminal/947f6eb80d944a84850b0538bf0ec3a5
TreeNode* Convert(TreeNode* pRootOfTree)
{
	if (pRootOfTree == NULL)
		return NULL;

	if (pRootOfTree->left == NULL && pRootOfTree->right == NULL)
		return pRootOfTree;

	//左结点处理：
	//将左子树构造成双链表，并返回链表头节点（因为Convert都是先访问左结点，因此会一直往左走，到最左边，也就是链表头部）
	TreeNode* left = Convert(pRootOfTree->left);
	TreeNode* p = left;
	//定位至左子树双链表最后一个节点
	while (p != NULL && p->right != NULL) 
	{
		p = p->right;
	}
	//如果左子树链表不为空的话，将当前root追加到左子树链表
	if (left != NULL) 
	{
		p->right = pRootOfTree;
		pRootOfTree->left = p;
	}

	//右结点处理：
	//将右子树构造成双链表，并返回链表头节点
	TreeNode *right = Convert(pRootOfTree->right);
	//如果右子树链表不为空的话，将该链表追加到root节点之后
	if (right != NULL)
	{
		right->left = pRootOfTree;
		pRootOfTree->right = right;
	}

	return left != NULL ? left : pRootOfTree;
}



//方法二：改进递归版
//解题思路：
//思路与方法二中的递归版一致，仅对第2点中的定位作了修改，新增一个全局变量记录左子树的最后一个节点。
//// 记录子树链表的最后一个节点，终结点只可能为只含左子树的非叶节点与叶节点
//protected TreeNode leftLast = null;
//public TreeNode Convert(TreeNode root) {
//	if (root == null)
//		return null;
//	if (root.left == null && root.right == null) {
//		leftLast = root;// 最后的一个节点可能为最右侧的叶节点
//		return root;
//	}
//	// 1.将左子树构造成双链表，并返回链表头节点
//	TreeNode left = Convert(root.left);
//	// 3.如果左子树链表不为空的话，将当前root追加到左子树链表
//	if (left != null) {
//		leftLast.right = root;
//		root.left = leftLast;
//	}
//	leftLast = root;// 当根节点只含左子树时，则该根节点为最后一个节点
//	// 4.将右子树构造成双链表，并返回链表头节点
//	TreeNode right = Convert(root.right);
//	// 5.如果右子树链表不为空的话，将该链表追加到root节点之后
//	if (right != null) {
//		right.left = root;
//		root.right = right;
//	}
//	return left != null ? left : root;
//}


//方法一：非递归版
//解题思路：
//1.核心是中序遍历的非递归算法。
//2.修改当前遍历节点与前一遍历节点的指针指向。
//import java.util.Stack;
//public TreeNode ConvertBSTToBiList(TreeNode root) {
//	if (root == null)
//		return null;
//	Stack<TreeNode> stack = new Stack<TreeNode>();
//	TreeNode p = root;
//	TreeNode pre = null;// 用于保存中序遍历序列的上一节点
//	boolean isFirst = true;
//	while (p != null || !stack.isEmpty()) {
//		while (p != null) {
//			stack.push(p);
//			p = p.left;
//		}
//		p = stack.pop();
//		if (isFirst) {
//			root = p;// 将中序遍历序列中的第一个节点记为root
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