#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void swap(char &a, char &b)
{
	char tmp = a;
	a = b;
	b = tmp;
}

void FindCombination(string str, int start, vector<string>& resultVec)
{
	int len = str.size();
	if (start == len)
	{
		//cout << str << endl;
		resultVec.push_back(str);
		return;
	}

	for (int i = start; i < len; ++i)
	{
		if (i != start && str[i] == str[start])//有重复字符时，跳过
			continue;
		swap(str[start], str[i]);
		FindCombination(str, start + 1, resultVec);
		swap(str[i], str[start]);
	}
	return;
}


vector<string> Permutation(string str)
{
	if (str.empty())
		return {};

	vector<string> resultVec;
	FindCombination(str, 0, resultVec);
	sort(resultVec.begin(), resultVec.end());
	return resultVec;
}

int main()
{
	Permutation("abc");
	return 0;
}