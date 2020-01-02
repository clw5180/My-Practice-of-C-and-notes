#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool findPath(char* matrix, bool* pFindedBoxes, int row, int col, int rows, int cols, char* str)
{
	char *myStr = str;
	if (*myStr == '\0')
		return true;

	if (row >= 0 && row < rows &&
		col >= 0 && col < cols &&
		pFindedBoxes[row * cols + col] != true &&
		matrix[row * cols + col] == *myStr)
	{
		pFindedBoxes[row * cols + col] = true;
		myStr++;
		cout << "找到：" << matrix[row * cols + col] << endl; //clw note：测试用
		//找到符合条件的点
		return findPath(matrix, pFindedBoxes, row - 1, col, rows, cols, myStr) ||
			findPath(matrix, pFindedBoxes, row, col - 1, rows, cols, myStr) ||
			findPath(matrix, pFindedBoxes, row + 1, col, rows, cols, myStr) ||
			findPath(matrix, pFindedBoxes, row, col + 1, rows, cols, myStr);
	}
	else
		return false;
}

bool hasPath(char* matrix, int rows, int cols, char* str)
{
	int total = rows * cols;
	bool* pFindedBoxes = new bool[total];
	for (int i = 0; i < total; ++i)
	{
		pFindedBoxes[i] = false;
	}

	int row = 0;
	int col = 0;

	int len = strlen(matrix);
	for (int i = 0; i < len; ++i)
	{
		if (matrix[i] == *str)
		{
			row = i / cols; //找到首字母所在的行、列
			col = i % cols;
			if (findPath(matrix, pFindedBoxes, row, col, rows, cols, str))
				return true;
			else
			{
				//如果找不到，之前经过的格子也要恢复false，相当于没走过
				for (int i = 0; i < total; ++i)
				{
					pFindedBoxes[i] = false;
				}
			}
				
		}
	}
	return false;
}

int main()
{
	//cout << hasPath("abcesfcsadee", 3, 4, "bcced");
	cout << hasPath("ABCESFCSADEE", 3, 4, "SEE");
	
	return 0;
}