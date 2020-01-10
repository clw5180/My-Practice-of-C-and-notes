/************************************************************************/
/* 2. 两数相加

给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

链接：https://leetcode-cn.com/problems/add-two-numbers



注意：
错误解法：遍历两个链表，把两个数相加，然后用结果创建链表；这样忽略了溢出的问题；

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

//我的方法1：直接把两个整数提出来，相加，然后用这个数创建链表
//错误原因：没有考虑大数溢出的问题；
//ListNode* createList(int num)
//{
//	int remainder = num % 10;
//	num /= 10;
//	ListNode* pHead = new ListNode(remainder);
//	ListNode* pTmp = pHead;
//	while (num != 0)
//	{
//		ListNode* pM = new ListNode(num % 10);
//		pTmp->next = pM;
//		pTmp = pTmp->next;
//		num /= 10;
//	}
//	return pHead;
//}
//
//ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
//{
//	int num1 = 0;
//	int num2 = 0;
//	int factor = 1;
//	while (l1 != NULL)
//	{
//		num1 = num1 + l1->val * factor;
//		l1 = l1->next;
//		factor *= 10;
//	}
//
//	factor = 1;
//	while (l2 != NULL)
//	{
//		num2 = num2 + l2->val * factor;
//		l2 = l2->next;
//		factor *= 10;
//	}
//
//	ListNode* p = createList(num1 + num2);
//	return p;
//}
//


//我的方法2：直接在链表上按位相加，考虑多种情况即可
//优势：该方法可以用于解决大数相加的问题；
/*
执行用时 :20 ms, 在所有 C++ 提交中击败了97.99 %的用户
内存消耗 :10.5 MB, 在所有 C++ 提交中击败了76.59 %
的用户
*/
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode* pDummyHead = new ListNode(-1);
	ListNode* pTmp = pDummyHead;
	int carry = 0;
	while (l1 != NULL && l2 != NULL)
	{
		pTmp->next = new ListNode((l1->val + l2->val + carry) % 10);
		pTmp = pTmp->next;
		carry = (l1->val + l2->val + carry) / 10;
		l1 = l1->next;
		l2 = l2->next;
	}

	if (l1 == NULL && l2 != NULL)
	{
		while (l2 != NULL)
		{
			pTmp->next = new ListNode((l2->val + carry) % 10);
			pTmp = pTmp->next;
			carry = (l2->val + carry) / 10;
			l2 = l2->next;
		}
	}

	else if (l2 == NULL && l1 != NULL)
	{
		while (l1 != NULL)
		{
			pTmp->next = new ListNode((l1->val + carry) % 10);
			pTmp = pTmp->next;
			carry = (l1->val + carry) / 10;
			l1 = l1->next;
		}
	}
	
	if (carry == 1) //对于从上面2个条件之一的while循环中跳出，或是l1、l2本身都为空的条件，都应该再做一个是否还有进位的判断
		pTmp->next = new ListNode(carry);
	
	return pDummyHead->next;
}