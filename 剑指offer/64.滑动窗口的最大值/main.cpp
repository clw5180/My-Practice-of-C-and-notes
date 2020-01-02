#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

/*
1��˼·  ���https://cuijiahua.com/blog/2018/02/basis_64.html
���ǿ���ʹ��һ��˫�˶���deque��

���ǿ�����STL�е�deque��ʵ�֣�����������������{2,3,4,2,6,2,5,1}Ϊ������ϸ˵����˼·��

����ĵ�һ��������2��������������С��ڶ���������3����2������2�������ǻ��������е����ֵ����˰�2�Ӷ�����ɾ�����ٰ�3��������С�������������4����3��ͬ����ɾ3��4����ʱ�����������Ѿ���3�����֣����������ֵ4λ�ڶ��е�ͷ����

���ĸ�����2��4С�����ǵ�4����֮���������п��ܳ�Ϊ���ֵ�ģ��������ǰ�2������е�β������һ��������6����4��2����ɾ4��2����6�����������ν��У����ֵ��Զλ�ڶ��е�ͷ����

�������������жϻ��������Ƿ����һ�����֣�Ӧ���ڶ����������������������±꣬��������ֵ����һ�����ֵ��±��뵱ǰ��������ֵ��±�֮����ڻ�������ڻ������ڴ�Сʱ����������Ѿ��Ӵ����л��������ԴӶ�����ɾ����


*/
//���磬�����������{2,3,4,2,6,2,5,1}���������ڵĴ�С3����ôһ������6���������ڣ����ǵ����ֵ�ֱ�Ϊ{4,4,6,6,6,5}�� 
vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
	if (num.size() < size || size == 0)
		return {};

	deque<int> deqIndex;  //clw note�����ݺ�����߼����������Ҳ����3������6,5,4,2,1,1

	//����ǰsize-1������deque��������������"���ʵ�size����Ȼ��дmax"�Ϳ���ѭ�������ˡ����ʱ�򻬶�����û����
	for (unsigned int i = 0; i < size - 1; i++) 
	{
		// ���deqIndex�ǿգ������µ����ִ��ڵ��ڶ�������С�����֣���ɾ����������С������
		// ����������Ϊ��Ȼ�µ����ֱȶ������С�����ǿ��ܻ�������������ͳ����ֵ�ˣ�����6,5,4,2,1,1
		while (!deqIndex.empty() && num[i] >= num[deqIndex.back()]) 
		{
			deqIndex.pop_back();
		}
		deqIndex.push_back(i);  //
	}

	vector<int> maxInWindows;
	for (unsigned int i = size - 1; i < num.size(); i++)  //��i=3��ʼ
	{
		//���Ҫ���������ȶ���β������Сֵ���򵯳�β����ֵ
		while (!deqIndex.empty() && num[i] >= num[deqIndex.back()])
		{
			deqIndex.pop_back();
		}

		//���i�Ѿ���Զ������i=6��size=3����ô������ֻ��6,5,4����ʱindex=3��Ӧ��ֵ�Ѿ��������ã�Ӧ���Ƴ�����
		if (!deqIndex.empty() && deqIndex.front() <= int(i - size))

		{
			deqIndex.pop_front();
		}

		//���������
		//���ֵ����β����ʵҲ�Ƕ�ͷ����֮ǰ��������5��4��Ҫ����6��5��4�ھ����������ᵯ������˶���ֻ��6һ������
		//�������ֵ������β����֮ǰ��������5��3��������β��ȡ����λ�ڶ�ͷ�����ֵ5��
		deqIndex.push_back(i);

		//ȡ��ͷ���ֵ
		maxInWindows.push_back(num[deqIndex.front()]);
	}

	return maxInWindows;
}

int main()
{
	//vector<int> vec = maxInWindows({ 2, 3, 4, 2, 6, 2, 5, 1 }, 3);
	vector<int> vec = maxInWindows({ 2, 3, 4, 2, 6, 2, 5, 1 }, 3);
	//vector<int> vec = maxInWindows({ -2, -3, -4, -2, -6, -2, -5, -1 }, 3);
	for (const auto &n : vec)
		cout << n << endl;
	return 0;
}