#include <iostream>
#include <string>
#include <vector>

using namespace std;

//����һ��������λ֮��
int getSum(int number)
{
	int sum = 0;
	while (number > 0)
	{
		sum += number % 10;
		number /= 10;
	}
	return sum;
}

//��������ƶ�λ��
int moving(int threshold, int rows, int cols, int i, int j, bool* flag)
{
	int count = 0;
	//��鵱ǰλ���Ƿ���Է���
	if (i >= 0 && i < rows &&   //���ڷ�Χ��
		j >= 0 && j < cols &&   //���ڷ�Χ��
		getSum(i) + getSum(j) <= threshold &&  //x��y�������λ֮��С��threshold
		flag[i*cols + j] == false) //û�����ʹ�
	{
		flag[i*cols + j] = true;
		//��Ƿ��ʹ��������־flag����Ҫ���ݣ���ΪֻҪ�����ʹ����ɡ�
	   //��Ϊ����ܷ��ʣ����ʹ����1.���ܷ��ʣ�Ҳ�����·��ʹ���
		count = 1 + moving(threshold, rows, cols, i - 1, j, flag)
			+ moving(threshold, rows, cols, i, j - 1, flag)
			+ moving(threshold, rows, cols, i + 1, j, flag)
			+ moving(threshold, rows, cols, i, j + 1, flag);
	}
	return count;
}

int movingCount(int threshold, int rows, int cols)
{
	//�½�rows*cols�����񲢳�ʼ��
	bool* flag = new bool[rows * cols];
	for (int i = 0; i < rows * cols; i++)
		flag[i] = false;

	//�ӣ�0,0�����꿪ʼ����;
	int count = moving(threshold, rows, cols, 0, 0, flag);
	delete[] flag;
	return count;
}

int main()
{
	
	return 0;
}