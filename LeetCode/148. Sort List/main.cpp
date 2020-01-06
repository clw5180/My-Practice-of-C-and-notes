/************************************************************************/
/* 148. 排序链表
在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

示例 1:

输入: 4->2->1->3
输出: 1->2->3->4
示例 2:

输入: -1->5->3->4->0
输出: -1->0->3->4->5

链接：https://leetcode-cn.com/problems/sort-list
/************************************************************************/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createLinkList(vector<int> vec)
{
	int len = vec.size();
	if (len == 0)
	{
		cout << "无法创建长度为0的链表！" << endl;
		return NULL;
	}
		

	ListNode* pHead = NULL;
	ListNode* pTemp = NULL;

	pHead = new ListNode(vec[0]);
	pTemp = pHead;

	for (int i = 1; i < len; ++i)
	{
		ListNode* pM = new ListNode(vec[i]);
		pTemp->next = pM;
		pTemp = pM;
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

ListNode* cutList(ListNode* pNode, int step)
{
	
	while (pNode && step!=1)
	{
		pNode = pNode->next;
		step--;
	}
	if (pNode == NULL)
		return NULL;

	ListNode* pRight = pNode->next;
	pNode->next = NULL;
	return pRight;
}

ListNode* mergeList(ListNode* p1, ListNode* p2)
{
	ListNode* pHead = new ListNode(-1);
	ListNode* pTmp = pHead;

	while (p1 != NULL && p2 != NULL)
	{
		if (p1->val <= p2->val)
		{
			pTmp->next = p1;
			pTmp = p1;
			p1 = p1->next;
		}
		else
		{
			pTmp->next = p2;
			pTmp = p2;
			p2 = p2->next;
		}
	}

	pTmp->next = p1 ? p1 : p2;
	return pHead->next;
}

ListNode* sortList(ListNode* head) 
{
	//0、判断是否为NULL，求长度等
	if (head == NULL)
		return NULL;

	ListNode* pTmp = head;
	int length = 1;
	while (pTmp->next!= NULL)
	{
		pTmp = pTmp->next;
		length++;
	}

	ListNode* dummyHead = new ListNode(-1);
	dummyHead->next = head;


	
	for (int step = 1; step < length; step *= 2)
	{
		//ListNode* pCurrent = head;   //clw note：pCurrent、pTail在每次while循环结束，也就是一轮归并结束后都是变了的，需要归零操作，即回归到起始点重新遍历    
		ListNode* pCurrent = dummyHead->next;  //注意head是会变的，比如2->1->3->4head指向2，排好序后变成1->2->3->4，head依然指向2，这时就不是从头遍历了，而把1略去了，所以这里只能是dummyHead.next
		ListNode* pTail = dummyHead;          

		while (pCurrent)
		{
			ListNode* pLeft = pCurrent;
			ListNode* pRight = cutList(pCurrent, step);

			//1、cut
			pCurrent = cutList(pRight, step);

			//2、merge
			pTail->next = mergeList(pLeft, pRight); //第一轮是把dummyHead接上合并的链表，如dummyHead->1->2，

			while (pTail->next) 
			{
				pTail = pTail->next;  //接上之后，还需要让pTail需要走到最后，也就是2的位置，然后2在下一轮会接后面的3->4
			}
		}
	}

	return dummyHead->next;
}

int main()
{
	vector<int> vec = { 2,1,3,4,6,8,7,5 };
	ListNode* myList = createLinkList(vec);
	printLinkList(myList);
	ListNode* myListSorted = sortList(myList);
	printLinkList(myListSorted);
	return 0;
}