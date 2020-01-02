#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4 X 4矩阵：
1  2  3  4  x
5  6  7  8  x 
9  10 11 12 x
13 14 15 16 x
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/

//我的方案：
vector<int> printMatrix(vector<vector<int> > matrix) 
{

	if (matrix.empty())
		return {};
	int row_origin = matrix.size();
	int col_origin = matrix[0].size();
	int row = row_origin;
	int col = col_origin;
	for (int i = 1; i < row; ++i)
	{
		if (matrix[i].size() != col)
			return {};
	}

	vector<int> resultVec;
	int index = 0;
	while (row > 0 && col > 0)
	{
		if (row == 1) //如果只有1行了，就把这一行全部扫一遍
		{
			for (int i = 0; i < col; ++i)
				resultVec.push_back(matrix[0 + index][i + index]);
		}
		else if (col == 1) //如果只有1列了，就把这一列全部扫一遍
		{
			for (int i = 0; i < row; ++i)
				resultVec.push_back(matrix[i][col - 1]);
		}
		else //否则，正常扫描
		{
			for (int i = 0; i < col - 1; ++i)
				resultVec.push_back(matrix[0 + index][i + index]);

			for (int i = 0; i < row - 1; ++i)
				resultVec.push_back(matrix[i + index][col_origin - 1 - index]);

			for (int i = col_origin - 1 - index; i > index; --i)
				resultVec.push_back(matrix[row_origin - 1 - index][i]);

			for (int i = row_origin - 1 - index; i > index; --i)
				resultVec.push_back(matrix[i][0 + index]);
		}
		row -= 2;
		col -= 2;
		++index;
	}

	return resultVec;
}


//网友方案，值得学习：
vector<int> printMatrix(vector<vector<int> > matrix) 
{
	int row = matrix.size();
	int col = matrix[0].size();
	vector<int> res;

	// 输入的二维数组非法，返回空的数组
	if (row == 0 || col == 0)  return res;

	// 定义四个关键变量，表示左上和右下的打印范围
	int left = 0, top = 0, right = col - 1, bottom = row - 1;
	while (left <= right && top <= bottom)
	{
		// left to right
		for (int i = left; i <= right; ++i)  res.push_back(matrix[top][i]);
		// top to bottom
		for (int i = top + 1; i <= bottom; ++i)  res.push_back(matrix[i][right]);
		// right to left
		if (top != bottom)
			for (int i = right - 1; i >= left; --i)  res.push_back(matrix[bottom][i]);
		// bottom to top
		if (left != right)
			for (int i = bottom - 1; i > top; --i)  res.push_back(matrix[i][left]);
		left++, top++, right--, bottom--;
	}
	return res;
}



int main()
{
	//vector<vector<int>> myVec = { {1}};
	//vector<vector<int>> myVec = { {1,2,3}, {4,5,6}, {7,8,9} };
	//vector<vector<int>> myVec = { {1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15} };
	//vector<vector<int>> myVec = { {1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10} };
	//vector<vector<int>> myVec = { {1, 2}, {4, 3} };
    vector<vector<int>> myVec = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	vector<int> vec = printMatrix(myVec);
	for (auto &n : vec)
		cout << n << " ";
	return 0;
}