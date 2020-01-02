#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
 *  我的方案：最开始直接采用C(n, m) = n! / (m! * (n-m)!)，但是很快就溢出了
 *  于是看到某个网友分析，发现其实相邻两项的关系可以用上面公式推导，就是(n - m + 1) / m;
 *  所以放弃下面用阶乘求组合数的方法，重新做
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


//我的方案2（根据网友方案进行修改）：
vector<int> getRow(int rowIndex) //注意是行索引，而不是第几行
{
	vector<int> vec;
	int temp = 1;
	if (rowIndex % 2 != 0)
	{
		for (int i = 0 ; i <= (rowIndex - 1) / 2; ++i)
		{
			vec.insert(vec.begin() + i, temp);
			vec.insert(vec.end() - i, temp);
			temp = (long)temp * (rowIndex - i) / (i + 1); //相邻两项倍数关系为 (rowIndex - (i + 1) + 1) / (i + 1);
				//注意这里不要写成temp*= 否则会先算后面的除法，就不一定是整数了；
			    //因为杨辉三角结果一定是整数，所以一定要先做乘法，再做除法，而且除出来一定是整数！
			    //另外LeetCode那个编译器需要加(long)，否则会溢出
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

//网友方案：4 lines
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
