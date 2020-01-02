#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

//===================== clwclw Rank：1925/4860

//vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) 
//{
//	map<int, vector<vector<int>>> myMap;
//	vector<int> tmpVec;
//	vector<vector<int>> result;
//	int distance = 0;
//	for (int i = 0; i < R; ++i)
//	{
//		for(int j = 0; j < C;++j)
//		{
//			distance = abs(i - r0) + abs(j - c0);
//			tmpVec = { i, j };
//			myMap[distance].push_back(tmpVec);
//		}
//	}
//	for (map<int, vector<vector<int>>>::iterator iter = myMap.begin(); iter != myMap.end(); ++iter)
//	{
//		for (vector<vector<int>>::iterator it = iter->second.begin(); it != iter->second.end(); ++it)
//		{
//			result.push_back(*it);
//		}
//	}
//	return result;
//}

//int twoCitySchedCost(vector<vector<int>>& costs) 
//{
//	int sum = 0;
//	multimap<int, int> myMap;
//	int len = costs.size();
//	for (int i = 0; i < len; ++i)
//	{
//		for (int j = 0; j < 2; ++j)
//		{
//			myMap.insert(pair<int, int>(costs[i][j], j));
//		}
//	}
//	//删掉最大值
//	//for (myMap.)
//	return sum;
//}

int twoCitySchedCost(vector<vector<int>>& costs)
{
	vector<vector<int>> mycosts = costs;
	int sum = 0;
	int costsMax = -1;
	int iMax, jMax;
	int countZero = 0;
	int countOne = 0;
	int len = costs.size();
	int tmpLen = len;
	while (countZero != len / 2 && countOne != len / 2)
	{
		for (int i = 0; i < tmpLen; ++i)
		{
			//for (int j = 0; j < 2; ++j)
			//{
				if (abs(mycosts[i][1] - mycosts[i][0]) > costsMax)
				{
					costsMax = abs(mycosts[i][1] - mycosts[i][0]);
					if (mycosts[i][1] > mycosts[i][0])
					{
						iMax = i;
						jMax = 1;
					}
					else
					{
						iMax = i;
						jMax = 0;
					}
				}
			/*}*/
		}
		sum += mycosts[iMax][1-jMax];
		//删除最大值对应的vector
		mycosts.erase(mycosts.begin() + iMax);
		costsMax = -1;
		--tmpLen;
		if (jMax == 1) //记录下标0的次数
			countZero++;
		else if (jMax == 0)
			countOne++;
	}
	if (countZero == len / 2)
	{
		for (int k = 0; k < tmpLen; ++k)
		{
			sum += mycosts[k][1];
		}
	}
	else if(countOne == len / 2)
	{
		for (int k = 0; k < tmpLen; ++k)
		{
			sum += mycosts[k][0];
		}
	}
	return sum;
}

int main()
{
	//allCellsDistOrder(2, 2, 0, 1);
	//vector<vector<int>> myVec = { {10, 20},{30, 200},{400, 50},{30, 20} };
	vector<vector<int>> myVec = { {259, 770}, {448, 54}, {926, 667}, {184, 139}, {840, 118}, {577, 469} };
	twoCitySchedCost(myVec);
	return 0;
}