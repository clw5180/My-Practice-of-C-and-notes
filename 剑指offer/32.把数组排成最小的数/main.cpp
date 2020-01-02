#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Smaller(int a, int b)
{
	string StrA = to_string(a);
	string StrB = to_string(b);
	int nMergeAB = atoi((StrA + StrB).c_str());
	int nMergeBA = atoi((StrB + StrA).c_str());
	if (nMergeAB <= nMergeBA)
		return true;
	else
		return false;
}

string PrintMinNumber(vector<int> numbers) 
{
	if (numbers.empty())
		return "";

	sort(numbers.begin(), numbers.end(), Smaller);

	string result = "";
	int len = numbers.size();
	for(int i=0;i<len;++i)
	{
		result += to_string(numbers[i]);
	}
	return result;
}

int main()
{
	string str = PrintMinNumber({ 3,32,321 });
	cout << str << endl;
	return 0;
}