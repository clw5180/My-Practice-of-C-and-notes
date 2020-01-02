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

ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) 
{
	if (pHead1 == NULL || pHead2 == NULL)
		return NULL;

	ListNode* pTmp1 = pHead1;
	ListNode* pTmp2 = pHead2;
	int count1 = 0;
	int count2 = 0;
	while (pTmp1)
	{
		pTmp1 = pTmp1->next;
		count1++;
	}
	while (pTmp2)
	{
		pTmp2 = pTmp2->next;
		count2++;
	}
	
	pTmp1 = pHead1;
	pTmp2 = pHead2;
	if (count1 > count2)
	{
		int i = count1 - count2;
		while (i)
		{
			pTmp1 = pTmp1->next;
			i--;
		}
	}

	if (count2 > count1)
	{
		int i = count2 - count1;
		while (i)
		{
			pTmp2 = pTmp2->next;
			i--;
		}
	}

	while (pTmp1)
	{
		if (pTmp1 == pTmp2)
			return pTmp1;
		pTmp1 = pTmp1->next;
		pTmp2 = pTmp2->next;
	}
	return NULL;
}

int main()
{
	ListNode* sList = createLinkList();
	printLinkList(sList);
	return 0;
}