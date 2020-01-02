#include <iostream>
#include <string>
#include <vector>

using namespace std;

//我的方案：参考剑指offerP180~182
bool VerifySquenceOfBST(vector<int> sequence) 
{
	if (sequence.empty())
		return false;
	int len = sequence.size();
	int root = sequence[len - 1];
	
	vector<int> leftTreeSequence;
	vector<int> rightTreeSequence;

	int i = 0;
	while (i < len - 1)
	{
		if (sequence[i] > root)
			break; 
		leftTreeSequence.push_back(sequence[i]);
		++i;
	}

	int j = i;
	while (j < len - 1)
	{
		if (sequence[j] < root)
			return false; //如果在右子树找到小于根的值，说明不是后序遍历
		rightTreeSequence.push_back(sequence[j]);
		++j;
	}

	/*bool bLeft, bRight;
	if (leftTreeSequence.size() <= 1)
		return true;
	if (rightTreeSequence.size() <= 1)
		return true;
	bLeft = VerifySquenceOfBST(leftTreeSequence);
	bRight = VerifySquenceOfBST(rightTreeSequence);
	*/

	//clw note：书上是这样写的，一个意思
	bool bLeft = true;
	bool bRight = true;
	if (i > 0)
		bLeft = VerifySquenceOfBST(leftTreeSequence);
	if (i < len - 1)
		bRight = VerifySquenceOfBST(rightTreeSequence);

	return (bLeft && bRight);
}

int main()
{
	vector<int> vec = { 5,7,6,9,11,10,8 };
	cout << VerifySquenceOfBST(vec) << endl;
	return 0;
}