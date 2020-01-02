#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) 
{
	if (strs.empty())
		return "";
	int nStrMinLen = strs[0].size();
	string strSub;
	for (auto &str : strs)
	{
		if (str.size() < nStrMinLen)
			nStrMinLen = str.size();
	}

	int count = 0;
	for (int i = 0; i < nStrMinLen; ++i)
	{
		char c = strs[0][i];
		for (auto &str : strs)
		{
			if (str[i] == c)
				count++;
		}
		if (count == strs.size())
		{
			strSub.push_back(strs[0][i]);
			count = 0;
		}
		else
			return strSub;
	}
	return strSub;
}

int main()
{
	vector<string> myVec = { "abc", "cba"};
	//vector<string> myVec = { "abcd", "abcaa", "abciii", "abcadsf" };
	//vector<string> myVec = {};
	cout << longestCommonPrefix(myVec) << endl;
	return 0;
}