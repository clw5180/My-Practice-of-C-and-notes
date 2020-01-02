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

//ע�⣺������Ϊ��������û�С�ͷ��㡱������
//��ȻҲ����ν��pHead����������ͷ��㣬��������ĵ�һ��Ԫ�أ��洢��������Ϣ��
//����ͷ����������һ�㲻�洢�κ���Ϣ����ȻҲ���Դ洢�����Ա��ȵ���ĸ�����Ϣ��

//ͨ��������������ֵ��������-1����
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

//������posλ��ѭ��������pos=0,1,2,3....
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

	//�ҵ�posλ��
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
	int count = 0; //clw note����ֹѭ������һֱ��ӡ
	while (p && count < 2 * pHead->length)
	{
		cout << "data of node is: " << p->val << endl;
		p = p->next;
		++count;
	}
	if (count >= 2 * pHead->length)
		cout << "������Ϊѭ��������ӡ����" << endl;
	return 0;
}

//ɾ��˳��������ظ�Ԫ��
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
			//�����һ��Ԫ��֮ǰԪ�ز��ȣ�������ֵ��Ȼ���������
			val = pCur->val;
			pPre = pCur;
			pCur = pCur->next;
			
			continue;
		}	 
		else
		{
			//ɾ�����
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
////ѭ������
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
////��������
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
////������������ط��͵�������������
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
//		CircleListNode* current = (CircleListNode*)sList;   //���븨��ָ�����currentָ������ͷ��
//
//		for (i = 0; (i < pos) && (current->next != NULL); i++)
//		{
//			current = current->next;    //����ָ�������pos��
//		}
//
//		//current->next 0�Ž��ĵ�ַ
//		node->next = current->next;   //1
//		current->next = node;              //2
//
//		//����һ�β����㣬��ʱslider��û����
//		if (sList->length == 0)
//		{
//			sList->slider = node;  //���α�sliderָ��0�Ž��(pos=0)������1��ҵ����
//		}
//		sList->length++;
//		/****************************************************************************************/
//		//clw note������͵�������һ������
//		//��pos=0����0����û��������current��Ȼָ��ͷ��,˵���õ���ͷ�巨����
//		if (current == (CircleListNode*)sList)
//		{
//			//��ȡ���һ��Ԫ��
//			CircleListNode* last = CircleList_Get(sList, sList->length - 1);
//			last->next = current->next;    //ͷ�巨������Ҫ�ĵ�3����������β��ָ��ָ���½�㣬��Ҫ��
//			//����ԭ����Է���һ�������ʾ��ͼ����pos����0��λ�ò�������
//		}
//		/****************************************************************************************/
//	}
//	return ret;
//}
//==============================================


//�ж������Ƿ��л�
//�벻����������ĳ�����ѵ�˼·���� ���� ʹ�ÿ���ָ��
/*
�����ö����ڴ�ռ�ļ����ǣ�����������ָ��walker��runner��walkerÿ���ƶ�һ��
��runnerÿ���ƶ���������walker��runner��һ������ʱ��֤�������л�
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

		if (pWalker == pRunner) //���ָ��Ӻ���׷������ָ�룬˵���л�
			return true;

		++count;
	}
	return false;
}

//���ѷ���1��������ת����������л���ôͷ���תһȦ����ԭ����ͷ���
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

//���ѷ���2������ָ�룻����������ҵķ�����ʱ���ܶ࣬��֪����ʲôԭ��
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
	//����������Գ���
	ListNode* SList = createLinkList();
	printLinkList(SList);
	if (hasCycle(SList))
		cout << "�������л�" << endl;;
	//deleteDuplicates(SList);
	//printLinkList(SList);

	//ѭ��������Գ���
	ListNode* CList = createCircleList(1);
	cout << CList->length << endl;
	printLinkList(CList);
	if (hasCycle(CList))
		cout << "�������л�" << endl;;

	return 0;
}




