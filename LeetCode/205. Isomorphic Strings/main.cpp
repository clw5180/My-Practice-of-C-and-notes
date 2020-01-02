#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

//参考网友方案，使用unordered_map
//网友说明：可以Using map, unordered_map and then array in C++ (time use：48ms, 24ms and 8ms)
bool isIsomorphic(string s, string t) 
{
	if (s.size() != t.size())
		return false;

	unordered_map<char, int> hashMapS;
	unordered_map<char, int> hashMapT;

	int len = s.size();
	for (int i = 0; i < len; ++i)
	{
		if(hashMapS[s[i]] != hashMapT[t[i]])
			return false;
		else
		{
			hashMapS[s[i]] = i + 1;
			hashMapT[t[i]] = i + 1;
		}
	}

	return true;
}

//网友方案：
//bool isIsomorphic(string s, string t) 
//{
//	char map_s[128] = { 0 };
//	char map_t[128] = { 0 };
//	int len = s.size();
//	for (int i = 0; i < len; ++i)
//	{
//		if (map_s[s[i]] != map_t[t[i]]) return false;
//		map_s[s[i]] = i + 1;
//		map_t[t[i]] = i + 1;
//	}
//	return true;
//}

int main()
{
	cout << isIsomorphic("abb", "dcc") << endl;
	cout << isIsomorphic("ab", "ca") << endl;
	cout << isIsomorphic("aab", "dcc") << endl;
	cout << isIsomorphic("abba", "abab") << endl;
	cout << isIsomorphic("abba", "aabb") << endl; //第一次遍历string，需要判断每个char在hashMap中的值相同
	cout << isIsomorphic("aba", "baa") << endl; //第二次遍历hashMap，需要判断每个元素再hashMap中的值相同
	return 0;
}