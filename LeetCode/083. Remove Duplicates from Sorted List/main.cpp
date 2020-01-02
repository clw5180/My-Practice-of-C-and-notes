#define _CRT_SECURE_NO_WARNINGS
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

//注意：个人认为，这里是没有“头结点”的链表
//虽然也有所谓的pHead，但并不是头结点，而是链表的第一个元素，存储了数据信息。
//真正头结点的数据域一般不存储任何信息（当然也可以存储如线性表长度等类的附加信息）
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



//注意：个人认为，这里是没有“头结点”的链表
//虽然也有所谓的pHead，但并不是头结点，而是链表的第一个元素，存储了数据信息。
//真正头结点的数据域一般不存储任何信息（当然也可以存储如线性表长度等类的附加信息）

//删除顺序链表的相邻重复元素
ListNode* deleteDuplicates(ListNode* phead)
{
	if (phead == NULL)
	{
		return NULL;
	}
	if (phead->next == NULL) 
	{
		return phead;
	}

	ListNode* pPre = phead;
	ListNode* pCur = phead->next;
	int val = pPre->val;
	while (pCur)
	{		
		if (pCur->val != val)
		{
			//如果下一个元素之前元素不等，则存入该值，然后继续后移
			val = pCur->val;
			pPre = pCur;
			pCur = pCur->next;
			
			continue;
		}	 
		else
		{
			//删除结点
			pPre->next = pCur->next;
			//free(pCur);
			delete pCur;
			pCur = pPre->next;
			
		}
	}
	return phead;
}

int main()
{
	ListNode* SList = createLinkList();
	//printLinkList(SList);
	deleteDuplicates(SList);
	printLinkList(SList);
	return 0;
}




