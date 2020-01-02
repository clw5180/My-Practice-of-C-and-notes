#include <iostream>
#include <string>
#include <vector>

using namespace std;

//我的方案：Time use还行但复杂了。
string convertToTitle(int n)
{
	if (n <= 0)
		return "";

	int quotient = n;  
	vector<int> convNumsVec; 
	while (quotient > 26)
	{
		//convNumsVec.insert(convNumsVec.begin(), quotient % 26); // 701 % 26 = 25
		convNumsVec.push_back(quotient % 26);  
		quotient /= 26;  // 701 / 26= 26
	}
	//convNumsVec.insert(convNumsVec.begin(), quotient);
	convNumsVec.push_back(quotient);
	
	string resultStr;
	int lenVec = convNumsVec.size();
	for (int i = 0; i < lenVec; ++i)
	{
		if (i == lenVec - 1 && convNumsVec[i] == 0)
			break;
		if (convNumsVec[i] == 0)
		{
			convNumsVec[i] = 26;
			convNumsVec[i + 1] -= 1;
		}
		//resultStr.push_back('A' + convNumsVec[i] - 1);
		resultStr.insert(resultStr.begin(), 'A' + convNumsVec[i] - 1);
		//resultStr.append('A' + remainder[i]);
	}
	return resultStr;
}

/*
网友方案：
1、一行解决
return n == 0 ? "" : convertToTitle(n / 26) + (char) (--n % 26 + 'A');

2、
string convertToTitle(int n) 
{
	string result;
	while (n) 
	{
		result.push_back('A' + (n - 1) % 26), n = (n - 1) / 26;
	}
	reverse(result.begin(), result.end());
	return result;
}

3、
string convertToTitle(int n) 
{
	string res="";
	while(n>0){
		res=char('A'+(n-1)%26)+res;
		n=(n-1)/26;
	}
	return res;
}
*/

int main()
{
	//cout << convertToTitle(701);
	//cout << convertToTitle(27);
	//cout << convertToTitle(703);
	cout << convertToTitle(702);
	//cout << convertToTitle(1);
	//cout << convertToTitle(52);
	return 0;
}