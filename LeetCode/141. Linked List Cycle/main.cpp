#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
//==============================================
struct ListNode 
{
	int val;
	int length = 0;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//注意：个人认为，这里是没有“头结点”的链表
//虽然也有所谓的pHead，但并不是头结点，而是链表的第一个元素，存储了数据信息。
//真正头结点的数据域一般不存储任何信息（当然也可以存储如线性表长度等类的附加信息）

//通过连续输入结点数值创建链表，-1结束
ListNode* createLinkList()
{
	int num;
	ListNode* pHead = NULL;
	ListNode* pTemp = NULL;
	cout << "please enter a node val(int type) of LinkList:";
	cin >> num;
	if (num == -1)
		return NULL;

	pHead = new ListNode(num);
	pHead->length++;
	pTemp = pHead;
	
	cout << "please enter a node val(int type) of LinkList:";
	cin >> num;
	while (num != -1)
	{
		//ListNode* pM = (ListNode*)malloc(sizeof(ListNode));
		//pM->val = num;
		ListNode* pM = new ListNode(num);
		pTemp->next = pM;
		pTemp = pM;
		pHead->length++;

		cout << "please enter a node val(int type) of LinkList:";
		cin >> num;
	}
	pTemp->next = NULL;
	return pHead;
}

//创建在pos位置循环的链表，pos=0,1,2,3....
ListNode* createCircleList(int pos)
{
	int num;
	ListNode* pHead = NULL;
	ListNode* pTemp = NULL;
	cout << "please enter a node val(int type) of CirCleLinkList:";
	cin >> num;
	if (num == -1)
		return NULL;

	pHead = new ListNode(num);
	pHead->length++;
	pTemp = pHead;

	cout << "please enter a node val(int type) of CirCleLinkList:";
	cin >> num;
	while (num != -1)
	{
		//ListNode* pM = (ListNode*)malloc(sizeof(ListNode));
		//pM->val = num;
		ListNode* pM = new ListNode(num);
		pTemp->next = pM;
		pTemp = pM;
		pHead->length++;

		cout << "please enter a node val(int type) of CirCleLinkList:";
		cin >> num;
	}

	//找到pos位置
	ListNode* pCur = pHead;
	for (int i = 0; i < pos; ++i)
	{
		pCur = pCur->next;
	}

	pTemp->next = pCur;
	return pHead;
}

int printLinkList(ListNode* pHead)
{
	if (pHead == NULL)
		return -1;
	ListNode* p = pHead;
	int count = 0; //clw note：防止循环链表一直打印
	while (p && count < 2 * pHead->length)
	{
		cout << "data of node is: " << p->val << endl;
		p = p->next;
		++count;
	}
	if (count >= 2 * pHead->length)
		cout << "此链表为循环链表，打印结束" << endl;
	return 0;
}

//删除顺序链表的重复元素
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
//==============================================


//==============================================
////循环链表
//typedef void CircleList;
//
//typedef struct _tag_CircleListNode
//{
//	struct _tag_CircleListNode * next;
//}CircleListNode;
//
//typedef struct _tag_CircleList
//{
//	CircleListNode header;
//	CircleListNode* slider;
//	int length;
//} TCircleList;
//
////创建链表
//CircleList* createCircleList()
//{
//	TCircleList* ret = (TCircleList*)malloc(sizeof(TCircleList));
//	if (ret == NULL)
//	{
//		return NULL;
//	}
//
//	ret->length = 0;
//	ret->header.next = NULL;
//	ret->slider = NULL;
//	return ret;
//}
//
////插入链表，个别地方和单向链表有区别
//int CircleList_Insert(CircleList* list, CircleListNode* node, int pos) // O(n)
//{
//	int ret = 0, i = 0;
//	TCircleList* sList = (TCircleList*)list;
//
//	if (list == NULL || node == NULL || pos < 0)
//	{
//		return -1;
//	}
//	//if( ret )
//	{
//		CircleListNode* current = (CircleListNode*)sList;   //引入辅助指针变量current指向链表头部
//
//		for (i = 0; (i < pos) && (current->next != NULL); i++)
//		{
//			current = current->next;    //辅助指针变量跳pos次
//		}
//
//		//current->next 0号结点的地址
//		node->next = current->next;   //1
//		current->next = node;              //2
//
//		//若第一次插入结点，此时slider还没建立
//		if (sList->length == 0)
//		{
//			sList->slider = node;  //让游标slider指向0号结点(pos=0)，即第1个业务结点
//		}
//		sList->length++;
//		/****************************************************************************************/
//		//clw note：这里和单向链表不一样！！
//		//（pos=0，跳0步，没有跳动，current仍然指向头部,说明用的是头插法！）
//		if (current == (CircleListNode*)sList)
//		{
//			//获取最后一个元素
//			CircleListNode* last = CircleList_Get(sList, sList->length - 1);
//			last->next = current->next;    //头插法额外需要的第3步操作，让尾部指针指向新结点，重要！
//			//具体原因可以分析一下上面的示意图，在pos等于0的位置插入的情况
//		}
//		/****************************************************************************************/
//	}
//	return ret;
//}
//==============================================


//判断链表是否有环
//想不出来，看了某个网友的思路如下 —— 使用快慢指针
/*
不适用额外内存空间的技巧是，即采用两个指针walker和runner，walker每次移动一步
而runner每次移动两步。当walker和runner第一次相遇时，证明链表有环
*/
bool hasCycle(ListNode *head) 
{
	ListNode *pRunner, *pWalker;
	pRunner = pWalker = head;
	int count = 0;
	while (pRunner)
	{
		pRunner = pRunner->next;

		if (count % 2 != 0)
			pWalker = pWalker->next;

		if (pWalker == pRunner) //快的指针从后面追上慢的指针，说明有环
			return true;

		++count;
	}
	return false;
}

//网友方案1：做链表反转，如果链表有环那么头结点转一圈还是原来的头结点
/*
ListNode* reverseList(ListNode* head)
{
	ListNode* prev = NULL;
	ListNode* follow = NULL;
	while (head)
	{
		follow = head->next;
		head->next = prev;
		prev = head;
		head = follow;
	}
	return prev;
}
bool hasCycle(ListNode *head)
{
	ListNode* rev = reverseList(head);
	if (head && head->next && rev == head)
	{
		return true;
	}
	return false;
}

//网友方案2：快慢指针；这个方案比我的方案用时长很多，不知道是什么原因
bool hasCycle(ListNode *head) 
{
	if (head == NULL || head->next == NULL) return false;

	ListNode *fast = head, *slow = head;

	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;

		if (fast == slow)
			return true;
	}

	return false;
}
*/

int main()
{
	//单向链表测试程序
	ListNode* SList = createLinkList();
	printLinkList(SList);
	if (hasCycle(SList))
		cout << "此链表有环" << endl;;
	//deleteDuplicates(SList);
	//printLinkList(SList);

	//循环链表测试程序
	ListNode* CList = createCircleList(1);
	cout << CList->length << endl;
	printLinkList(CList);
	if (hasCycle(CList))
		cout << "此链表有环" << endl;;

	return 0;
}




