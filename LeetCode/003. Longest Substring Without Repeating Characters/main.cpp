#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

//题目解析：https://www.cnblogs.com/ariel-dreamland/p/8668286.html

////我的方案1： hashMap，696 ms，143.2 MB，完全不行
//int lengthOfLongestSubstring(string s) 
//{
//	if (s.empty())
//		return 0;
//	int lenStr = s.size();
//	int maxSubLen = 0;
//	unordered_map<char, int> hashMap;
//	for (int i = 0; i < lenStr; ++i)
//	{
//		//判断map中是否包含key
//		if (hashMap.count(s[i]) == 0)
//		{
//			hashMap.insert({ s[i], i });
//			if (hashMap.size() > maxSubLen)	
//				maxSubLen = hashMap.size();
//		}
//		else
//		{
//			i = hashMap[s[i]];  //这样i回退，相当于双层循环，肯定用时长！
//			hashMap.clear();
//		}
//	}
//	return maxSubLen;
//}


//我的修改方案2：hashMap，24 ms，10.9 MB，一般
int lengthOfLongestSubstring(string s) 
{
	if (s.empty())
		return 0;
	int lenStr = s.size();
	int maxSubLen = 0;
	unordered_map<char, int> hashMap;
	int nSubLeft = 0;
	for (int i = 0; i < lenStr; ++i)
	{
		//如果map中不包含key，写map
		if (hashMap.count(s[i]) == 0)
		{
			hashMap.insert({ s[i], i });
			maxSubLen = max(maxSubLen, i - nSubLeft + 1);
		}
		else
		{
			if(nSubLeft <= hashMap[s[i]])  //nSubLeft小的时候才可以右移，必要
				nSubLeft = hashMap[s[i]] + 1; 
			 //否则比如"baab!bb"，第2个b进到这里的时候，left已经指向第2个a了，这时left反而左移到第1个b后面了
			else
				maxSubLen = max(maxSubLen, i - nSubLeft + 1); //这一句必要
             //否则比如"tmmzuxt"，到最后的t的时候如果不求最大值，那么最大长度只有4而不是5
			hashMap[s[i]] = i;
		}
	}
	return maxSubLen;
}

////网友方案1：hashMap，20~30 ms，10.8 MB，一般
//int lengthOfLongestSubstring(string s) 
//{
//	int l = 0, r = 0, len = 0;
//	unordered_map<char, int> window;
//	while (r < s.size()) 
//	{
//		if (window.find(s[r]) != window.end())
//			l = max(l, window[s[r]] + 1);  //see explain    
//		window[s[r]] = r;
//		len = max(len, r - l + 1);
//		r++;
//	}
//	return len;
//}

////网友最佳方案：10~20ms，10.6 MB
//int lengthOfLongestSubstring(string s) 
//{
//	vector<int> dict(256, -1);
//	int maxLen = 0, start = -1;
//	for (int i = 0; i != s.length(); i++) 
//	{
//		if (dict[s[i]] > start)
//			start = dict[s[i]];
//		dict[s[i]] = i;
//		maxLen = max(maxLen, i - start);
//	}
//	return maxLen;
//}

////网友最佳方案：动态规划，12 ms，9.2 MB
//class Solution {
//public:
//	int lengthOfLongestSubstring(string s) {
//		if (!s.size()) return 0;
//		int max = 0;
//		int count = 0;
//		int current = -1;
//		for (int i = 0; i < 256; ++i) {
//			tmp[i] = -1;
//		}
//		for (int i = 0; i < s.length(); ++i) {
//			int step = s[i] - '\0';  //其实没必要，'\0'就是0
//			if (tmp[step] == -1 || tmp[step] <= current)
//			{
//				tmp[step] = i;
//				++count;
//			}
//			else
//			{
//				if (count > max)
//					max = count;
//				count = i - tmp[step];
//				current = tmp[step];
//				tmp[step] = i;
//			}
//
//		}
//		if (count > max)
//			max = count;
//		return max;
//	}
//private:
//	int tmp[256];
//};



int main()
{
	
	cout << lengthOfLongestSubstring("aabaab!bb") << endl;
	cout << lengthOfLongestSubstring("tmmzuxt") << endl;
	cout << lengthOfLongestSubstring("abcdefbghijkl") << endl;
	cout << lengthOfLongestSubstring(" ") << endl;
	cout << lengthOfLongestSubstring("a") << endl;
	cout << lengthOfLongestSubstring("aa") << endl;
	cout << lengthOfLongestSubstring("ab") << endl;
	cout << lengthOfLongestSubstring("abba") << endl;
	cout << lengthOfLongestSubstring("abcbdbcbb") << endl;
	cout << lengthOfLongestSubstring("abcabcbb") << endl;
	cout << lengthOfLongestSubstring("bbbbb") << endl;
	cout << lengthOfLongestSubstring("pwwkew") << endl;
	return 0;
}