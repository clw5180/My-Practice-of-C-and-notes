#include <iostream>
#include <string>
#include <vector>

using namespace std;

//�ҵķ���1��ʱ�临�Ӷ�O(n^2)
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

//�ҵķ���2��ʱ�临�Ӷ�O(n)����ò����ʱ�������ࡣ���������ַ����Ƚ϶̰�
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
		//printf("�滻��str�����ڴ�߽磬��ֹ�滻��\n");
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