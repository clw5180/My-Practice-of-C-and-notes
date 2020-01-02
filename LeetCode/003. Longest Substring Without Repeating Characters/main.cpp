#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

//��Ŀ������https://www.cnblogs.com/ariel-dreamland/p/8668286.html

////�ҵķ���1�� hashMap��696 ms��143.2 MB����ȫ����
//int lengthOfLongestSubstring(string s) 
//{
//	if (s.empty())
//		return 0;
//	int lenStr = s.size();
//	int maxSubLen = 0;
//	unordered_map<char, int> hashMap;
//	for (int i = 0; i < lenStr; ++i)
//	{
//		//�ж�map���Ƿ����key
//		if (hashMap.count(s[i]) == 0)
//		{
//			hashMap.insert({ s[i], i });
//			if (hashMap.size() > maxSubLen)	
//				maxSubLen = hashMap.size();
//		}
//		else
//		{
//			i = hashMap[s[i]];  //����i���ˣ��൱��˫��ѭ�����϶���ʱ����
//			hashMap.clear();
//		}
//	}
//	return maxSubLen;
//}


//�ҵ��޸ķ���2��hashMap��24 ms��10.9 MB��һ��
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
		//���map�в�����key��дmap
		if (hashMap.count(s[i]) == 0)
		{
			hashMap.insert({ s[i], i });
			maxSubLen = max(maxSubLen, i - nSubLeft + 1);
		}
		else
		{
			if(nSubLeft <= hashMap[s[i]])  //nSubLeftС��ʱ��ſ������ƣ���Ҫ
				nSubLeft = hashMap[s[i]] + 1; 
			 //�������"baab!bb"����2��b���������ʱ��left�Ѿ�ָ���2��a�ˣ���ʱleft�������Ƶ���1��b������
			else
				maxSubLen = max(maxSubLen, i - nSubLeft + 1); //��һ���Ҫ
             //�������"tmmzuxt"��������t��ʱ������������ֵ����ô��󳤶�ֻ��4������5
			hashMap[s[i]] = i;
		}
	}
	return maxSubLen;
}

////���ѷ���1��hashMap��20~30 ms��10.8 MB��һ��
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

////������ѷ�����10~20ms��10.6 MB
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

////������ѷ�������̬�滮��12 ms��9.2 MB
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
//			int step = s[i] - '\0';  //��ʵû��Ҫ��'\0'����0
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