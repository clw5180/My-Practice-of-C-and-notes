#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createLinkList()
{
	int num;
	ListNode* pHead = NULL;
	ListNode* pTemp = NULL;
	cout << "please enter a node val:";
	cin >> num;
	if (num == -1)
		return NULL;
	pHead = new ListNode(num);
	pTemp = pHead;
	cout << "please enter a node val:";
	cin >> num;
	while (num != -1)
	{
		//ListNode* pM = (ListNode*)malloc(sizeof(ListNode));
		//pM->val = num;
		ListNode* pM = new ListNode(num);
		pTemp->next = pM;
		pTemp = pM;

		cout << "please enter a node data:";
		cin >> num;
	}
	pTemp->next = NULL;
	return pHead;
}

int printLinkList(ListNode* pHead)
{
	if (pHead == NULL)
		return -1;
	ListNode* p = pHead;
	while (p)
	{
		cout << "data of node is: " << p->val << endl;
		p = p->next;
	}
	return 0;
}

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) 
{
	if (pListHead == NULL)
		return NULL;
	ListNode* tmp = pListHead;
	vector<ListNode*> vec;
	while (tmp)
	{
		vec.push_back(tmp);
		tmp = tmp->next;
	}
	int len = vec.size();
	if (k > len)
		return NULL;
	return vec[len - k];
}

int main()
{
	ListNode* sList = createLinkList();
	printLinkList(sList);
	ListNode* myNode = FindKthToTail(sList, 5);
	cout << myNode->val << endl;
	return 0;
}