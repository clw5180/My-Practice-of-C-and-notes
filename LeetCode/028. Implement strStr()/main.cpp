#include <iostream>
#include <string>
#include <vector>

using namespace std;

//我的解答，蛮力法。。。
int strStr(string haystack, string needle) 
{
	if (needle.empty())
		return 0;
	int fullStrLength = haystack.size();
	int subStrLength = needle.size();
	if (fullStrLength < subStrLength)
		return -1;
	int index;
	for (int i = 0; i <= fullStrLength - subStrLength; ++i)
	{
		index = i;
		for (int j = 0; j < subStrLength; ++j)
		{
			if (haystack[index] != needle[j])
				break;
			++index;
		}
		if (index >= i + subStrLength)
			return i;
	}
	return -1;
}

//大佬网友的解读与解答，值得学习：
/*
C++ Brute-Force and KMP
https://leetcode.com/problems/implement-strstr/discuss/12956/C%2B%2B-Brute-Force-and-KMP

Traverse all the possible starting points of haystack (from 0 to haystack.length() - needle.length()) and see if the following characters in haystack match those of needle.

class Solution {
public:
	int strStr(string haystack, string needle) {
		int m = haystack.size(), n = needle.size();
		for (int i = 0; i <= m - n; i++) {
			int j = 0;
			for (; j < n; j++) {
				if (haystack[i + j] != needle[j]) {
					break;
				}
			}
			if (j == n) {
				return i;
			}
		}
		return -1;
	}
};
The following is another implementation, shorter but harder to understand.

class Solution {
public:
	int strStr(string haystack, string needle) {
		int m = haystack.size(), n = needle.size(), p = 0;
		while (p + n - 1 < m) {
			if (haystack.substr(p, n) == needle) {
				return p;
			}
			while (p++ + n - 1 < m && haystack[p] != needle[0]);
		}
		return -1;
	}
};
Finally comes the KMP algorithm. You may refer to KMP on jBoxer's blog and KMP on geeksforgeeks for some explanations. I rewrote the code from the second link.

class Solution {
public:
	int strStr(string haystack, string needle) {
		int m = haystack.size(), n = needle.size();
		if (!n) {
			return 0;
		}
		vector<int> lps = kmpProcess(needle);
		for (int i = 0, j = 0; i < m;) {
			if (haystack[i] == needle[j]) {
				i++, j++;
			}
			if (j == n) {
				return i - j;
			}
			if (i < m && haystack[i] != needle[j]) {
				j ? j = lps[j - 1] : i++;
			}
		}
		return -1;
	}
private:
	vector<int> kmpProcess(string needle) {
		int n = needle.size();
		vector<int> lps(n, 0);
		for (int i = 1, len = 0; i < n;) {
			if (needle[i] == needle[len]) {
				lps[i++] = ++len;
			} else if (len) {
				len = lps[len - 1];
			} else {
				lps[i++] = 0;
			}
		}
		return lps;
	}
};

*/


int main()
{
	string haystack = "hello";
	string needle = "ll";
	//string haystack = "aaa";
	//string needle = "aaaa";
	cout << strStr(haystack, needle) << endl;
	return 0;
}