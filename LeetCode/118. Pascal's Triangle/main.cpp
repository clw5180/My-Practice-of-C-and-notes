#include <iostream>
#include <string>
#include <vector>

using namespace std;

//我的方案：代码行数略多，不够简洁
vector<vector<int>> generate(int numRows) 
{
	if (numRows == 0)
		return {};
	vector<vector<int>> triangleVec;
	vector<int> tmpVec;
	triangleVec.push_back({ 1 });  //开始误写成了triangleVec[0][0] = 1; 。。。
	for (int i = 1; i < numRows; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			if (j == 0 || j == i)
				tmpVec.push_back(1); 
			else
				tmpVec.push_back(triangleVec[i - 1][j - 1] + triangleVec[i - 1][j]); 
		}
		triangleVec.push_back(tmpVec);
		tmpVec.clear();
	}
	return triangleVec;
}

//网友方案：很巧妙，相当于把vector<int>进行扩展，从1变成11，121,1331,14641然后push进vector<vector<int>>
//         而不是像我那样每次要把vector<int>清空，然后用vector<vector<int>>的上一行来求下一行。
//vector<vector<int>> generate(int numRows)
//{
//	vector<vector<int>> result;
//
//	vector<int> row;
//	for (int i = 0; i < numRows; i++) 
//	{
//		row.push_back(1);
//		for (int j = i - 1; j > 0; j--) 
//		{
//			row[j] = row[j - 1] + row[j];
//		}
//		result.push_back(row);
//	}
//	return result;
//}

int main()
{
	vector<vector<int>> myVec;
	myVec = generate(20);    //注意int溢出的问题，大概30+行的位置
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			cout << myVec[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}