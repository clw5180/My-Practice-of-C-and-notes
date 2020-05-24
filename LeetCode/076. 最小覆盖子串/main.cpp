#define _CRT_SECURE_NO_WARINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// TODO��������ͨ��distance�����������ַ��仯��t���ַ��Ľӽ��̶ȣ������ܽ�Ϊһ�ּӷ���˼·��Ҳ����д�ɼ�����˼·��
string minWindow(string s, string t)
{
	int lenS = s.size();
	int lenT = t.size();

	if (lenS == 0 || lenT == 0 || lenS < lenT)
		return "";

	// ascii('z')=122�����123�Ϳ��ԣ�����������ÿ���2�������ݴεĿռ�
	int winFreq[128] = {0};
	int tFreq[128] = {0};
	for (char c : t)
		tFreq[c]++;
		
	//���������ڲ���������t�е��ַ�����Ӧ�ַ�Ƶ���������ظ����㣻
	int distance = 0;
	int minLen = lenS + 1;
	int begin = 0;
	int left = 0;
	int right = 0;

	// [left, right)������ҿ���������������ǳ���
	while (right < lenS)
	{
		//�ұ߽��ƶ�
		if (tFreq[s[right]] == 0)    // TODO:���Ժ����� if (tFreq[s[left]] == 0) ����ͬʱȥ������ΪwinFreq[s[right]]++ ��Ӧ���滹�� winFreq[s[left]]--;
		{ 
			right++;
			continue;
		}

		if (winFreq[s[right]] < tFreq[s[right]])
			distance++;  // ���ƻ��������ƶ�����Ҫ�ǿ�distance
		winFreq[s[right]]++;
		right++;

		while (distance == lenT)
		{
			//��߽��ƶ�֮ǰ����Ҫά��minLen
			if (right - left < minLen)   
			{
				minLen = right - left;
				begin = left;
			}

			//��߽��ƶ�
			if (tFreq[s[left]] == 0)  // TODO:���Ժ�����ͬʱȥ��
			{
				left++;
				continue;
			}

			if (winFreq[s[left]] == tFreq[s[left]]) // Ҳ���Ǵ�����߽��ƶ��󣬸պô�����Ԫ�ظպ�С��tFreq��Ԫ�ظ���
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