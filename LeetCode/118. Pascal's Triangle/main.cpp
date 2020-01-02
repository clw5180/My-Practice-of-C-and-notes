#include <iostream>
#include <string>
#include <vector>

using namespace std;

//�ҵķ��������������Զ࣬�������
vector<vector<int>> generate(int numRows) 
{
	if (numRows == 0)
		return {};
	vector<vector<int>> triangleVec;
	vector<int> tmpVec;
	triangleVec.push_back({ 1 });  //��ʼ��д����triangleVec[0][0] = 1; ������
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

//���ѷ�����������൱�ڰ�vector<int>������չ����1���11��121,1331,14641Ȼ��push��vector<vector<int>>
//         ��������������ÿ��Ҫ��vector<int>��գ�Ȼ����vector<vector<int>>����һ��������һ�С�
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
	myVec = generate(20);    //ע��int��������⣬���30+�е�λ��
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