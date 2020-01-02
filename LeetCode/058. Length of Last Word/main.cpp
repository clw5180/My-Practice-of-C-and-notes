#include <iostream>
#include <string>
#include <vector>

using namespace std;

//�ҵĽ�𡣡���
int lengthOfLastWord(string s) 
{
	int lenS = s.size();
	if (lenS == 0)
		return 0;
	int end;
	bool flagIsSpace = true;
	if (s[lenS - 1] == ' ')
	{
		for (int i = lenS - 2; i >= 0; --i)
		{
			if (s[i] != ' ' && flagIsSpace == true)
			{
				end = i;
				flagIsSpace = false;
			}
			if (!flagIsSpace)  //ǰ���в��ǿո��Ԫ��
			{
				if (s[i] == ' ')  //��Ԫ���ǿո�
					return end - i;
			}
		}
		if (flagIsSpace != true)
			return end + 1;
		else
			return 0;
	}

	for (int i = lenS - 1; i >= 0; --i)
	{
		if (s[i] == ' ')
			return lenS - 1 - i;
	}
	return lenS;
}

//���Ѹ��õĴ𰸣�
//int lengthOfLastWord(string s) 
//{
//		int len = 0, tail = s.length() - 1;
//		while (tail >= 0 && s[tail] == ' ') 
//			tail--;
//		while (tail >= 0 && s[tail] != ' ') 
//		{
//			len++;
//			tail--;
//		}
//		return len;
//}


int main()
{
	cout << lengthOfLastWord("") << endl;
	cout << lengthOfLastWord("       ") << endl;
	cout << lengthOfLastWord("a") << endl;
	cout << lengthOfLastWord("a ") << endl;
	cout << lengthOfLastWord(" a ") << endl;
	cout << lengthOfLastWord("aa  ") << endl;
	cout << lengthOfLastWord(" aa ") << endl;
	cout << lengthOfLastWord("aaa    ") << endl;
	cout << lengthOfLastWord("Hello World") << endl;
	return 0;
}
