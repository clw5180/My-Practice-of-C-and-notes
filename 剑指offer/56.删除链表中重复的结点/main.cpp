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

//删除顺序链表的重复元素（重复元素一个都不保留！这一点和LeetCode83题不同）
//删除顺序链表的重复元素
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

	//首先添加一个头节点，以方便碰到第一个，第二个节点就相同的情况
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
			if (bDuplicated) //值已经不等了，但是之前元素还是重复的，还需要删一次，比如1 2 3 3 4 4 5，
				            //虽然是3和4不同，但由于3是Duplicated，也要把3删掉；但是2到3就不用删除3
			{
				//删除结点
				pTmp->next = pPre->next;
				delete pPre;
				bDuplicated = false;
			}
			else
			{
				pTmp = pPre; //上面的例子，2到3时候需要把pTmp从原来指向1变成指向2；但是3到4的时候，tmp就不用赋值。
			}
			val = pCur->val; //则存入该值，然后继续后移
			pPre = pCur;
			pCur = pCur->next;
		}
		else
		{
			bDuplicated = true;

			//删除结点
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