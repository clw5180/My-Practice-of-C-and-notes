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

//我的方案：
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
	if (l1 == NULL || l2 == NULL)
		return NULL;

	int number1 = 0, number2 = 0;
	int out = (l1->val + l2->val) % 10;
	int carry = (l1->val + l2->val) / 10;

	ListNode* pHead = NULL;
	pHead = new ListNode(out);
	ListNode* pTemp = pHead;

	//cout << out << " ";
	while (l1->next || l2->next || carry)
	{
		if (l1->next == NULL && l2->next == NULL)
		{
			number1 = number2 = 0;
		}
		else if (l1->next == NULL)
		{
			number1 = 0;
			l2 = l2->next;
			number2 = l2->val;
		}
		else if (l2->next == NULL)
		{
			number2 = 0;
			l1 = l1->next;
			number1 = l1->val;
		}
		else   //none is NULL
		{
			l1 = l1->next;
			l2 = l2->next;
			number1 = l1->val;
			number2 = l2->val;
		}

		out = (number1 + number2 + carry) % 10;
		carry = (number1 + number2 + carry) / 10;
		//cout << out << " ";

		ListNode *pM = new ListNode(out);
		pTemp->next = pM;
		pTemp = pM;
	}
	return pHead;
}
//网友方案，很简洁
/*
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* head = new ListNode(0);
		ListNode* cur = head;
		int carry = 0;
		while (l1 || l2 || carry) {
			int num = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
			carry = num / 10;
			cur->next = new ListNode(num % 10);
			cur = cur->next;
			if (l1) l1 = l1->next;
			if (l2) l2 = l2->next;
		}
		return head->next;
	}

*/

int main()
{
	ListNode* myList1 = createLinkList(); //3 2 1
	ListNode* myList2 = createLinkList(); //6 5 4 
	ListNode* resultList = addTwoNumbers(myList1, myList2);  //123+456=579 -> 9 7 5
	printLinkList(resultList);
	return 0;
}