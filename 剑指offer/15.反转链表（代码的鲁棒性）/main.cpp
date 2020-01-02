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

ListNode* ReverseList(ListNode* pHead) 
{
	if (pHead == NULL)
		return NULL;
	ListNode* pPre = pHead;
	ListNode* pCur = pHead->next;
	pHead->next = NULL; //很重要，否则链表头部成环
	ListNode* pTmp;
	while (pCur)
	{
		pTmp = pCur;
		pCur = pCur->next;
		pTmp->next = pPre;
		pPre = pTmp;
	}
	return pPre;
}

int main()
{
	ListNode* sList = createLinkList();
	printLinkList(sList);
	ListNode* sListNew = ReverseList(sList);
	printLinkList(sListNew);
	//cout << n << " ";
	return 0;
}