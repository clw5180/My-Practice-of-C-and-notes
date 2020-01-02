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

char* Serialize(TreeNode *root) 
{
	if (root == NULL)
	{
		return "#";
	}
	string str = to_string(root->val) + string(Serialize(root->left)) + string(Serialize(root->left));
	return (char*)str.c_str();
}

TreeNode* Deserialize(char *str) 
{
	if (str == NULL || *str == '\0')
		return NULL;

	TreeNode *pRoot = NULL;

	int num = 0;
	while (*str != ',')
		num = num * 10 + (*(str++) - '0');
	str++;

	if (*str != '#')
	{
		pRoot = new TreeNode(num);
		pRoot->left = Deserialize(str);
		pRoot->right = Deserialize(str);
	}
	return pRoot;
}

int main()
{
	
	return 0;
}