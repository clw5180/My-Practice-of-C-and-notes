#define _CRT_SECURE_NO_WARINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool isAnagram(string s, string t)
{
	int lenS = s.size();
	int lenT = t.size();
	
	if (lenS == 0 && lenT == 0)  // 这句官方解答没写，不需要
		return true;
	if (lenS != lenT)
		return false;

	//因为 S 和 T 都只包含 A-Z 的字母，所以一个简单的 26 位计数器表就足够了
	int sFreq[26] = { 0 };
	int tFreq[26] = { 0 };

	for (char c : s)
		sFreq[c - 'a']++;
	for (char c : t)
		tFreq[c - 'a']++;

	for (int i = 0; i < 26; ++i)
	{
		if (sFreq[i] != tFreq[i])
			return false;
	}
	return true;
}

/*
方法一：排序
时间复杂度：O(nlog n)
空间复杂度：O(1)，空间取决于排序实现


方法二：哈希表的 26 位计数器表就足够了。
我们需要两个计数器数表进行比较吗？实际上不是，因为我们可以用一个计数器表计算 s 字母的频率，
用 t 减少计数器表中的每个字母的计数器，然后检查计数器是否回到零。

Java
public boolean isAnagram(String s, String t) {
	if (s.length() != t.length()) {
		return false;
	}
	int[] counter = new int[26];
	for (int i = 0; i < s.length(); i++) {
		counter[s.charAt(i) - 'a']++;
		counter[t.charAt(i) - 'a']--;
	}
	for (int count : counter) {
		if (count != 0) {
			return false;
		}
	}
	return true;
}
或者我们可以先用计数器表计算 s，然后用 t 减少计数器表中的每个字母的计数器。
如果在任何时候计数器低于零，我们知道 tt 包含一个不在 ss 中的额外字母，并立即返回 FALSE。
时间复杂度：O(n)。
空间复杂度：O(1)

进阶：
如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？

解答：
使用哈希表而不是固定大小的计数器。想象一下，分配一个大的数组来适应整个 Unicode 字符范围，这个范围可能超过 100万。哈希表是一种更通用的解决方案，可以适应任何字符范围。

作者：LeetCode
链接：https://leetcode-cn.com/problems/valid-anagram/solution/you-xiao-de-zi-mu-yi-wei-ci-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

int main()
{
	string s = "anagram";
	string t = "nagaram";
	cout << isAnagram(s, t);
	return 0;
}