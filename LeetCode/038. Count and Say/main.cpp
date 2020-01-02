#include <iostream>
#include <string>
#include <vector>

using namespace std;

//我的方案
string countAndSay(int n) 
{
	string strOld, strNew;
	if (n == 1)
		return "1";
	else
		strOld = countAndSay(n - 1);
	int len = strOld.size();
	if (len == 1)
		return "11";  //strNew.append(strOld).append(to_string(count));
	
	int count = 1;
	for (int i = 0; i < len - 1; ++i)
	{
		if(strOld[i] != strOld[i + 1])
		{
			strNew.append(to_string(count)) += strOld[i];
			count = 1;
		}
		else
		{
			++count;
		}
		if(i == len - 2)
			strNew.append(to_string(count)) += strOld[i+1];
	}
	return strNew;
}


//网友更好的解决方案：
/*

//方案一
class Solution {
public:
	string countAndSay(int n) {
		string num = "1";
		for (int i = 1; i < n; i++) {
			num = say(num);
		}
		return num;
	}
private:
	string say(string num) {
		int n = num.size();
		string s;
		for (int i = 0, j = 1, k = 1; i < n; i = j, j = i + 1, k = 1) {
			while (j < n && num[j] == num[i]) {
				j++;
				k++;
			}
			s += char(k + '0');
			s += num[i];
		}
		return s;
	}
};

//方案二
string countAndSay(int n) {
	if (n == 0) return "";
	string res = "1";
	while (--n) {
		string cur = "";
		for (int i = 0; i < res.size(); i++) {
			int count = 1;
			 while ((i + 1 < res.size()) && (res[i] == res[i + 1])){
				count++;
				i++;
			}
			cur += to_string(count) + res[i];
		}
		res = cur;
	}
	return res;
}

*/

int main()
{
	//cout << countAndSay(1) << endl;
	//cout << countAndSay(2) << endl;
	cout << countAndSay(100) << endl;
	return 0;
}