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

//学习网友思路，自己写;
//链接：https://www.nowcoder.com/questionTerminal/f836b2c43afc4b35ad6adc41ec941dba
RandomListNode* Clone(RandomListNode* pHead)
{
	if (pHead == NULL)
		return NULL;

	
	//1、复制每个节点，如：复制节点A得到A1，将A1插入节点A后面，比如之前是1->2->3，
	//复制之后成了1->1->2->2->3->3
	RandomListNode *pCur = pHead;
	while (pCur)
	{
		RandomListNode *pM = new RandomListNode(pCur->label);
		pM->next = pCur->next;
		pCur->next = pM;
		pCur = pM->next;	
	}

	//2、遍历链表，A1->random = A->random->next;
	pCur = pHead; //pCur先回来
	while (pCur)
	{
		if (pCur->random != NULL)
		{
			pCur->next->random = pCur->random->next;
		}
		pCur = pCur->next->next;
	}

	//3、将链表拆分成原链表和复制后的链表
	RandomListNode *pCloneHead = pHead->next; //克隆后头结点位置pCloneHead
	RandomListNode *pTmp = NULL; //新建一个辅助指针变量
	pCur = pHead; //pCur先回来
	while (pCur->next)
	{
		//这里很巧妙，比如原来是1->1->2->2->3->3，第一轮让左边的1指向左边的2，
		//第二轮让右边的1指向右边的2，第三轮让左边的2指向右边的3，以此类推。。。
		//我一开始想的是，第一轮把1指向对应的2，第二轮把2指向对应的3，这样麻烦一些。。
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