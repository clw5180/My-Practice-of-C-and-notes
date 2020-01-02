#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

//�ο����ѷ�����ʹ��unordered_map
//����˵��������Using map, unordered_map and then array in C++ (time use��48ms, 24ms and 8ms)
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

//���ѷ�����
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
	cout << isIsomorphic("abba", "aabb") << endl; //��һ�α���string����Ҫ�ж�ÿ��char��hashMap�е�ֵ��ͬ
	cout << isIsomorphic("aba", "baa") << endl; //�ڶ��α���hashMap����Ҫ�ж�ÿ��Ԫ����hashMap�е�ֵ��ͬ
	return 0;
}