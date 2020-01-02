#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

//ɾ��˳��������ظ�Ԫ�أ��ظ�Ԫ��һ��������������һ���LeetCode83�ⲻͬ��
//ɾ��˳��������ظ�Ԫ��
ListNode* deleteDuplicates(ListNode* pHead)
{
	if (pHead == NULL)
	{
		return NULL;
	}
	if (pHead->next == NULL)
	{
		return pHead;
	}

	//�������һ��ͷ�ڵ㣬�Է���������һ�����ڶ����ڵ����ͬ�����
	ListNode* pMyHead = new ListNode(pHead->val - 1);
	pMyHead->next = pHead;
	ListNode* pTmp = pMyHead;
	ListNode* pPre = pMyHead;
	ListNode* pCur = pMyHead->next;
	int val = pPre->val;
	bool bDuplicated = false;

	while (pCur)
	{
		if (pCur->val != val)
		{
			if (bDuplicated) //ֵ�Ѿ������ˣ�����֮ǰԪ�ػ����ظ��ģ�����Ҫɾһ�Σ�����1 2 3 3 4 4 5��
				            //��Ȼ��3��4��ͬ��������3��Duplicated��ҲҪ��3ɾ��������2��3�Ͳ���ɾ��3
			{
				//ɾ�����
				pTmp->next = pPre->next;
				delete pPre;
				bDuplicated = false;
			}
			else
			{
				pTmp = pPre; //��������ӣ�2��3ʱ����Ҫ��pTmp��ԭ��ָ��1���ָ��2������3��4��ʱ��tmp�Ͳ��ø�ֵ��
			}
			val = pCur->val; //������ֵ��Ȼ���������
			pPre = pCur;
			pCur = pCur->next;
		}
		else
		{
			bDuplicated = true;

			//ɾ�����
			pTmp->next = pPre->next;
			delete pPre;
			pPre = pCur;
			pCur = pCur->next;
		}
	}
	if (bDuplicated)
	{
		delete pPre;
		pTmp->next = NULL;
	}

	return pMyHead->next;
}

int main()
{
	ListNode* SList = createLinkList();
	printLinkList(SList);
	SList = deleteDuplicates(SList);
	printLinkList(SList);
	return 0;
}