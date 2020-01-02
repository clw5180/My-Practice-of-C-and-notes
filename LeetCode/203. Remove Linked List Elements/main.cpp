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

//删除顺序链表值为val的元素 
//我的方案：C++，28 ms， faster than 99.70%，无内存泄露，
ListNode* removeElements(ListNode* head, int val)
{
	if (head == NULL)
		return NULL;

	while (head->val == val) //这一部分参考网友，处理1->1然后删除元素1的链表这种特殊情况
	{
		ListNode *tmp = head;
		head = head->next;
		delete tmp;
		if (head == NULL)
			return NULL;
	}

	//为了避免内存泄露，链表删除元素需要用到两个指针来记录位置。
	ListNode* pPre = head;
	ListNode* pCur = head->next;
	while (pCur)
	{
		if (pCur->val == val)
		{

			pPre->next = pCur->next;
			delete pCur;
			pCur = pPre->next;
		}
		else
		{
			pPre = pCur;
			pCur = pCur->next;
		}
	}
	return head;
}

int main()
{
	ListNode* SList = createLinkList();
	printLinkList(SList);
	//deleteDuplicates(SList);
	//printLinkList(SList);
	printf("after remove element：");
	ListNode* SListNew = removeElements(SList, 1);
	printLinkList(SListNew);
	return 0;
}




