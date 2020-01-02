#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֣����磬�����������4 X 4����
1  2  3  4  x
5  6  7  8  x 
9  10 11 12 x
13 14 15 16 x
�����δ�ӡ������1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/

//�ҵķ�����
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
		if (row == 1) //���ֻ��1���ˣ��Ͱ���һ��ȫ��ɨһ��
		{
			for (int i = 0; i < col; ++i)
				resultVec.push_back(matrix[0 + index][i + index]);
		}
		else if (col == 1) //���ֻ��1���ˣ��Ͱ���һ��ȫ��ɨһ��
		{
			for (int i = 0; i < row; ++i)
				resultVec.push_back(matrix[i][col - 1]);
		}
		else //��������ɨ��
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


//���ѷ�����ֵ��ѧϰ��
vector<int> printMatrix(vector<vector<int> > matrix) 
{
	int row = matrix.size();
	int col = matrix[0].size();
	vector<int> res;

	// ����Ķ�ά����Ƿ������ؿյ�����
	if (row == 0 || col == 0)  return res;

	// �����ĸ��ؼ���������ʾ���Ϻ����µĴ�ӡ��Χ
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