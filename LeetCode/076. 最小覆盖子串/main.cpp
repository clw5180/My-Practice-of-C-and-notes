#define _CRT_SECURE_NO_WARINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// TODO：这种是通过distance衡量窗口中字符变化和t中字符的接近程度，可以总结为一种加法的思路；也可以写成减法的思路；
string minWindow(string s, string t)
{
	int lenS = s.size();
	int lenT = t.size();

	if (lenS == 0 || lenT == 0 || lenS < lenT)
		return "";

	// ascii('z')=122，因此123就可以，但是数组最好开辟2的整数幂次的空间
	int winFreq[128] = {0};
	int tFreq[128] = {0};
	for (char c : t)
		tFreq[c]++;
		
	//滑动窗口内部包含多少t中的字符，对应字符频数超过不重复计算；
	int distance = 0;
	int minLen = lenS + 1;
	int begin = 0;
	int left = 0;
	int right = 0;

	// [left, right)，左闭右开，语义上相减就是长度
	while (right < lenS)
	{
		//右边界移动
		if (tFreq[s[right]] == 0)    // TODO:可以和下面 if (tFreq[s[left]] == 0) 那里同时去掉，因为winFreq[s[right]]++ 对应后面还有 winFreq[s[left]]--;
		{ 
			right++;
			continue;
		}

		if (winFreq[s[right]] < tFreq[s[right]])
			distance++;  // 控制滑动窗口移动，主要是靠distance
		winFreq[s[right]]++;
		right++;

		while (distance == lenT)
		{
			//左边界移动之前，先要维护minLen
			if (right - left < minLen)   
			{
				minLen = right - left;
				begin = left;
			}

			//左边界移动
			if (tFreq[s[left]] == 0)  // TODO:可以和上面同时去掉
			{
				left++;
				continue;
			}

			if (winFreq[s[left]] == tFreq[s[left]]) // 也就是窗口左边界移动后，刚好窗口内元素刚好小于tFreq的元素个数
				distance--;
			winFreq[s[left]]--;
			left++;
		}
	}

	if (minLen == lenS + 1)
		return "";
	else
		return s.substr(begin, minLen);
}

int main()
{
	//string s = "ADOBECODEBANC";
	//string t = "ABC";
	string s = "ABC";
	string t = "B";
	cout << minWindow(s, t);
	return 0;
}