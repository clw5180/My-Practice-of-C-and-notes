#include <iostream>
#include <string>
#include <vector>

using namespace std;

//�ҵķ������ο���ָofferP180~182
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
			return false; //������������ҵ�С�ڸ���ֵ��˵�����Ǻ������
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

	//clw note������������д�ģ�һ����˼
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