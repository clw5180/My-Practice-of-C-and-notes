#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	if (pHead == NULL)
		return NULL;
	ListNode* pTmp = pHead;
	unordered_map<ListNode*, int> hashMap;
	while (pTmp)
	{
		hashMap[pTmp]++;
		if (hashMap[pTmp] >= 2)
			return pTmp;
		pTmp = pTmp->next;
	}
	return NULL;
}

int main()
{
	
	return 0;
}