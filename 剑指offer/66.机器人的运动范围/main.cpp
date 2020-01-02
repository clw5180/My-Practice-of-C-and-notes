#include <iostream>
#include <string>
#include <vector>

using namespace std;

//计算一个数各数位之和
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

//计算最大移动位置
int moving(int threshold, int rows, int cols, int i, int j, bool* flag)
{
	int count = 0;
	//检查当前位置是否可以访问
	if (i >= 0 && i < rows &&   //行在范围内
		j >= 0 && j < cols &&   //列在范围内
		getSum(i) + getSum(j) <= threshold &&  //x，y坐标的数位之和小于threshold
		flag[i*cols + j] == false) //没被访问过
	{
		flag[i*cols + j] = true;
		//标记访问过，这个标志flag不需要回溯，因为只要被访问过即可。
	   //因为如果能访问，访问过会加1.不能访问，也会标记下访问过。
		count = 1 + moving(threshold, rows, cols, i - 1, j, flag)
			+ moving(threshold, rows, cols, i, j - 1, flag)
			+ moving(threshold, rows, cols, i + 1, j, flag)
			+ moving(threshold, rows, cols, i, j + 1, flag);
	}
	return count;
}

int movingCount(int threshold, int rows, int cols)
{
	//新建rows*cols的网格并初始化
	bool* flag = new bool[rows * cols];
	for (int i = 0; i < rows * cols; i++)
		flag[i] = false;

	//从（0,0）坐标开始访问;
	int count = moving(threshold, rows, cols, 0, 0, flag);
	delete[] flag;
	return count;
}

int main()
{
	
	return 0;
}