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

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL)
		return pHead2;
	if (pHead2 == NULL)
		return pHead1;
	ListNode *pTmp1 = pHead1;
	ListNode *pTmp2 = pHead2;
	ListNode *pHead, *pTmp, *pM;

	if (pTmp1->val <= pTmp2->val)
	{
		pHead = new ListNode(pTmp1->val);
		pTmp = pHead;
		pTmp1 = pTmp1->next;
	}
	else
	{
		pHead = new ListNode(pTmp2->val);
		pTmp = pHead;
		pTmp2 = pTmp2->next;
	}

	while (pTmp1)
	{
		if (pTmp1->val <= pTmp2->val)
		{
			pM = new ListNode(pTmp1->val);
			pTmp->next = pM;
			pTmp = pM;
			pTmp1 = pTmp1->next;
		}
		else
		{
			pM = new ListNode(pTmp2->val);
			pTmp->next = pM;
			pTmp = pM;
			pTmp2 = pTmp2->next;
		}
	}

	while (pTmp2)
	{
		pM = new ListNode(pTmp2->val);
		pTmp->next = pM;
		pTmp = pM;
		pTmp2 = pTmp2->next;
	}

	return pHead;
}

//网友方案：

//递归版本：
/*
public ListNode Merge(ListNode list1, ListNode list2) {
	if (list1 == null) {
		return list2;
	}
	if (list2 == null) {
		return list1;
	}
	if (list1.val <= list2.val) {
		list1.next = Merge(list1.next, list2);
		return list1;
	}
	else {
		list2.next = Merge(list1, list2.next);
		return list2;
	}
}
*/

//非递归版本
/*
if(list1 == null){
			return list2;
		}
		if(list2 == null){
			return list1;
		}
		ListNode mergeHead = null;
		ListNode current = null;
		while(list1!=null && list2!=null){
			if(list1.val <= list2.val){
				if(mergeHead == null){
				   mergeHead = current = list1;
				}else{
				   current.next = list1;
				   current = current.next;
				}
				list1 = list1.next;
			}else{
				if(mergeHead == null){
				   mergeHead = current = list2;
				}else{
				   current.next = list2;
				   current = current.next;
				}
				list2 = list2.next;
			}
		}
		if(list1 == null){
			current.next = list2;
		}else{
			current.next = list1;
		}
		return mergeHead;
*/

int main()
{
	ListNode* sList1 = createLinkList();
	printLinkList(sList1);
	ListNode* sList2 = createLinkList();
	printLinkList(sList2);
	ListNode* sListNew = Merge(sList1, sList2);
	printLinkList(sListNew);
	return 0;
}