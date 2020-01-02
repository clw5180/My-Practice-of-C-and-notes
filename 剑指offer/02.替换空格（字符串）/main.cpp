#include <iostream>
#include <string>
#include <vector>

using namespace std;

//我的方案1：时间复杂度O(n^2)
//void replaceSpace(char *str, int length) 
//{
//  if (str == NULL || length < 0)
//	return;
//	int index = -1;
//	for (int i = 0; i < length; ++i)
//	{
//		if (str[i] == '\0')
//		{
//			index = i;
//			break;
//		}	
//	}
//
//	for (int i = index; i >= 0; --i)
//	{
//		if (str[i] == ' ')
//		{
//			if (index + 2 > length)
//				return;
//			for (int j = index; j >= i + 1; --j)
//			{
//				str[j + 2] = str[j];
//			}
//			str[i + 2] = '0';
//			str[i + 1] = '2';
//			str[i] = '%';
//			index += 2;
//		}
//	}
//}

//我的方案2：时间复杂度O(n)，但貌似用时和上面差不多。。。可能字符串比较短吧
void replaceSpace(char *str, int length)
{
	if (str == NULL || length < 0)
		return;

	int index = -1;
	int count = 0;
	for (int i = 0; i < length; ++i)
	{
		if (str[i] == ' ')
			count++;
		if (str[i] == '\0')
		{
			index = i;
			break;
		}
	}

	int move = count * 2;
	if (index + move > length)
	{
		//printf("替换后str超出内存边界，禁止替换！\n");
		return;
	}

	for (int i = index; i >= 0; --i)
	{
		if (str[i] == ' ')
		{
			str[i + move] = '0';
			str[i + move - 1] = '2';
			str[i + move - 2] = '%';
			move -= 2;
		}
		else
			str[i + move] = str[i];
	}
}

int main()
{
	char buf[32] = "We Are Happy";
	cout << buf << endl;
	replaceSpace(buf, 32);
	cout << buf << endl;
	return 0;
}