#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool IsContinuous(vector<int> numbers) 
{
	int len = numbers.size();
	if (len < 5)
		return false;

	sort(numbers.begin(), numbers.end());

	int num = numbers[len - 1];
	int count_zero = 0;
	int blank = 0;
	for (int i = len - 2; i >= 0; --i)
	{
		//����ж���һ������0��Ԫ�أ�ֱ��false��
		if (numbers[i] == num && num != 0)
			return false;
		else
			num = numbers[i];

		//ͳ���м���0���м�����ȱ
		if (numbers[i] == 0)
			count_zero++;
		else
			blank += numbers[i+1] - numbers[i] - 1;
	}

	if (count_zero >= blank)
		return true;
	else
		return false;
}

int main()
{
	//IsContinuous({2,1,4,5,3});
	IsContinuous({ 0,3,2,6,4 });
	return 0;
}