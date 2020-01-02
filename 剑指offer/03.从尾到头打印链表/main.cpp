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

//我的方案1：
vector<int> printListFromTailToHead(ListNode* head)
{
	if (head == NULL)
		return {};

	vector<int> tmpVec;

	ListNode* pTmp = head;
	while (pTmp)
	{
		tmpVec.insert(tmpVec.begin(), pTmp->val);
		pTmp = pTmp->next;
	}
	return tmpVec;
}

//网友方案2：头插vector 效率太低，可以先vector.push_back  返回之前翻转vector，std::reverse(begin,end)
//vector<int> printListFromTailToHead(ListNode* head)
//{
//	if (head == NULL)
//		return {};
//
//	vector<int> tmpVec;
//
//	ListNode* pTmp = head;
//	while (pTmp)
//	{
//		tmpVec.push_back(pTmp->val);
//		pTmp = pTmp->next;
//	}
//	reverse(tmpVec.begin(), tmpVec.end());
//	return tmpVec;
//}



int main()
{
	ListNode* sList = createLinkList();
	printLinkList(sList);
	vector<int> vec = printListFromTailToHead(sList);
	for (auto &n : vec)
		cout << n << " ";
	return 0;
}