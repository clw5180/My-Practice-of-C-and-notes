#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//我的方案：
//string ReverseSentence(string str) 
//{
//	if (str.empty())
//		return "";
//
//	int len = str.size();
//	string result = "";
//
//	int start = 0;
//	int end = str.find(" ", 0);
//	if (end == str.npos)
//		return str;
//
//	//先找一次
//	string subStr = str.substr(start, end - start);
//	result = subStr + result;
//	start = end + 1;
//	end = str.find(" ", end + 1);
//
//	while (end != str.npos)
//	{
//		subStr = str.substr(start, end - start);
//		result = subStr + " " + result;
//		start = end + 1;
//		end = str.find(' ', end +1);
//	}
//
//	//最后找一次
//	subStr = str.substr(start, len - start);
//	result = subStr + " " + result;
//
//	return result;
//}


string ReverseSentence(string str)
{
	if (str.empty())
		return "";

	int len = str.size();
	reverse(str.begin(), str.end());

	int index = 0;
	string::iterator itBegin = str.begin();
	string::iterator itEnd;
	do 
	{
		index = str.find(' ', index + 1);
		if (index == str.npos)
			index = len;
		itEnd = str.begin() + index;
		reverse(itBegin, itEnd);
		itBegin = itEnd + 1;
	} while (index != len);

	return str;
}

int main()
{
	string str = "student a am I";
	cout << ReverseSentence(str) << endl;
	return 0;
}