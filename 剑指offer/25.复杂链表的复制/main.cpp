#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};

//ѧϰ����˼·���Լ�д;
//���ӣ�https://www.nowcoder.com/questionTerminal/f836b2c43afc4b35ad6adc41ec941dba
RandomListNode* Clone(RandomListNode* pHead)
{
	if (pHead == NULL)
		return NULL;

	
	//1������ÿ���ڵ㣬�磺���ƽڵ�A�õ�A1����A1����ڵ�A���棬����֮ǰ��1->2->3��
	//����֮�����1->1->2->2->3->3
	RandomListNode *pCur = pHead;
	while (pCur)
	{
		RandomListNode *pM = new RandomListNode(pCur->label);
		pM->next = pCur->next;
		pCur->next = pM;
		pCur = pM->next;	
	}

	//2����������A1->random = A->random->next;
	pCur = pHead; //pCur�Ȼ���
	while (pCur)
	{
		if (pCur->random != NULL)
		{
			pCur->next->random = pCur->random->next;
		}
		pCur = pCur->next->next;
	}

	//3���������ֳ�ԭ����͸��ƺ������
	RandomListNode *pCloneHead = pHead->next; //��¡��ͷ���λ��pCloneHead
	RandomListNode *pTmp = NULL; //�½�һ������ָ�����
	pCur = pHead; //pCur�Ȼ���
	while (pCur->next)
	{
		//������������ԭ����1->1->2->2->3->3����һ������ߵ�1ָ����ߵ�2��
		//�ڶ������ұߵ�1ָ���ұߵ�2������������ߵ�2ָ���ұߵ�3���Դ����ơ�����
		//��һ��ʼ����ǣ���һ�ְ�1ָ���Ӧ��2���ڶ��ְ�2ָ���Ӧ��3�������鷳һЩ����
		pTmp = pCur->next; 
		pCur->next = pTmp->next;
		pCur = pTmp;
	}
	return pCloneHead;
}

RandomListNode* createLinkList()
{
	int num;
	RandomListNode* pHead = NULL;
	RandomListNode* pTemp = NULL;
	cout << "please enter a node label:";
	cin >> num;
	if (num == -1)
		return NULL;
	pHead = new RandomListNode(num);
	pTemp = pHead;
	cout << "please enter a node label:";
	cin >> num;
	while (num != -1)
	{
		//RandomListNode* pM = (RandomListNode*)malloc(sizeof(RandomListNode));
		//pM->label = num;
		RandomListNode* pM = new RandomListNode(num);
		pTemp->next = pM;
		pTemp = pM;

		cout << "please enter a node data:";
		cin >> num;
	}
	pTemp->next = NULL;
	return pHead;
}

int printLinkList(RandomListNode* pHead)
{
	if (pHead == NULL)
		return -1;
	RandomListNode* p = pHead;
	while (p)
	{
		cout << "data of node is: " << p->label << endl;
		p = p->next;
	}
	return 0;
}


int main()
{
	RandomListNode* sList = createLinkList();
	printLinkList(sList);
	RandomListNode* myList = Clone(sList);
	printLinkList(myList);
	return 0;
}