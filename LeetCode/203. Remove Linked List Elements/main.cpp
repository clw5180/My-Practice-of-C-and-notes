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

//ע�⣺������Ϊ��������û�С�ͷ��㡱������
//��ȻҲ����ν��pHead����������ͷ��㣬��������ĵ�һ��Ԫ�أ��洢��������Ϣ��
//����ͷ����������һ�㲻�洢�κ���Ϣ����ȻҲ���Դ洢�����Ա��ȵ���ĸ�����Ϣ��
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



//ע�⣺������Ϊ��������û�С�ͷ��㡱������
//��ȻҲ����ν��pHead����������ͷ��㣬��������ĵ�һ��Ԫ�أ��洢��������Ϣ��
//����ͷ����������һ�㲻�洢�κ���Ϣ����ȻҲ���Դ洢�����Ա��ȵ���ĸ�����Ϣ��

//ɾ��˳������ֵΪval��Ԫ�� 
//�ҵķ�����C++��28 ms�� faster than 99.70%�����ڴ�й¶��
ListNode* removeElements(ListNode* head, int val)
{
	if (head == NULL)
		return NULL;

	while (head->val == val) //��һ���ֲο����ѣ�����1->1Ȼ��ɾ��Ԫ��1�����������������
	{
		ListNode *tmp = head;
		head = head->next;
		delete tmp;
		if (head == NULL)
			return NULL;
	}

	//Ϊ�˱����ڴ�й¶������ɾ��Ԫ����Ҫ�õ�����ָ������¼λ�á�
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
	printf("after remove element��");
	ListNode* SListNew = removeElements(SList, 1);
	printLinkList(SListNew);
	return 0;
}




