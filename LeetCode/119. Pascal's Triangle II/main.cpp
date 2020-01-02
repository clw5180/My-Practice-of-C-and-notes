#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
 *  �ҵķ������ʼֱ�Ӳ���C(n, m) = n! / (m! * (n-m)!)�����Ǻܿ�������
 *  ���ǿ���ĳ�����ѷ�����������ʵ��������Ĺ�ϵ���������湫ʽ�Ƶ�������(n - m + 1) / m;
 *  ���Է��������ý׳���������ķ�����������
 */
//long long getFactorial(int n)
//{
//	if (n == 0)
//		return 1;
//	long long result = 1;
//	for (int i = 2; i <= n; ++i)
//	{
//		result *= i;
//	}
//	return result;
//}
//
//int getCombinationNumber(int n, int m)
//{
//	int result = getFactorial(n) / getFactorial(m) / getFactorial(n - m);
//	return result;
//}


//�ҵķ���2���������ѷ��������޸ģ���
vector<int> getRow(int rowIndex) //ע�����������������ǵڼ���
{
	vector<int> vec;
	int temp = 1;
	if (rowIndex % 2 != 0)
	{
		for (int i = 0 ; i <= (rowIndex - 1) / 2; ++i)
		{
			vec.insert(vec.begin() + i, temp);
			vec.insert(vec.end() - i, temp);
			temp = (long)temp * (rowIndex - i) / (i + 1); //�����������ϵΪ (rowIndex - (i + 1) + 1) / (i + 1);
				//ע�����ﲻҪд��temp*= ������������ĳ������Ͳ�һ���������ˣ�
			    //��Ϊ������ǽ��һ��������������һ��Ҫ�����˷����������������ҳ�����һ����������
			    //����LeetCode�Ǹ���������Ҫ��(long)����������
		}  
	}
	else
	{
		for (int i = 0; i <= rowIndex / 2 - 1; ++i)
		{
			vec.insert(vec.begin() + i, temp);
			vec.insert(vec.end() - i, temp);
			temp = temp * (rowIndex - i) / (i + 1);
		}
		int middle = rowIndex / 2;
		vec.insert(vec.begin() + middle, temp);
	}
	return vec;
}

//���ѷ�����4 lines
//vector<int> getRow(int rowIndex) 
//{
//	vector<int> res(rowIndex + 1, 1);
//	for (int k = 1; k <= (rowIndex + 1) / 2; k++)
//		res[k] = res[rowIndex - k] = (long)res[k - 1] * (long)(rowIndex - k + 1) / k;
//	return res;
//}

int main()
{
	vector<int> myVec = getRow(12);
	for (auto &n : myVec)
		cout << n << " ";
	return 0;
}
