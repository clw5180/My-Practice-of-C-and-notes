#include <iostream>
#include <string>
#include <vector>

using namespace std;

//�ҵķ���1����ͷ��ʼ�����ҵ���С���Ǹ�ֵ
//���������00010��01000���ִ��ظ����ֵ���������ܲ����������ѵĶ��ַ�����һЩ
//���ѣ�������ʱ�临�Ӷ�O(n)�������ﵽO(log(n))�ĸ��Ӷ��أ������Ҳ��õĶ��ֲ��ҵ�˼·��
//int minNumberInRotateArray(vector<int> rotateArray) 
//{
//	if (rotateArray.empty())
//		return 0;
//	int len = rotateArray.size();
//	int tmp = rotateArray[0];
//	for (int i = 1; i < len; ++i)
//	{
//		if (rotateArray[i] < tmp)
//			return rotateArray[i];
//		tmp = rotateArray[i];
//	}
//	return tmp;
//}

//���ѷ���2�����֣�Javaʵ��
/*
���ӣ�https://www.nowcoder.com/questionTerminal/9f3231a991af4f55b95579b44b7a01ba
��Դ��ţ����
���ö��ַ����������⣬
mid = low + (high - low) / 2
��Ҫ�������������
(1)array[mid] > array[high]:
�������������array����[3, 4, 5, 6, 0, 1, 2]����ʱ��С����һ����mid���ұߡ�
low = mid + 1
(2)array[mid] == array[high] :
	�������������array����[1, 0, 1, 1, 1] ����[1, 1, 1, 0, 1]����ʱ��С���ֲ����ж���mid���
	�����ұ�, ��ʱֻ��һ��һ���� ��
	high = high - 1
	(3)array[mid] < array[high] :
	�������������array����[2, 2, 3, 4, 5, 6, 6], ��ʱ��С����һ������array[mid]������mid����
	�ߡ���Ϊ�ұ߱�Ȼ���ǵ����ġ�
	high = mid
	ע�������и��ӣ��������ѯ�ķ�Χ���ֻʣ����������ômid һ����ָ���±꿿ǰ������
	���� array = [4, 6]
	array[low] = 4; array[mid] = 4; array[high] = 6;
���high = mid - 1���ͻ�������� ���high = mid
������(1)��low = mid + 1�Ͳ������

public class Solution 
{
	public int minNumberInRotateArray(int[] array) 
	{
		int low = 0; int high = array.length - 1;
		while (low < high) 
		{
			int mid = low + (high - low) / 2;
			if (array[mid] > array[high]) 
			{
				low = mid + 1;
			}
			else if (array[mid] == array[high]) 
			{
				high = high - 1;
			}
			else 
			{
				high = mid;
			}
		}
		return array[low];
	}
}
*/


//���ѷ���3������
class Solution 
{
public:
	int minNumberInRotateArray(vector<int> rotateArray) 
	{
		int size = rotateArray.size();
		if (size == 0) 
		{
			return 0;
		}//if
		int left = 0, right = size - 1;
		int mid = 0;
		// rotateArray[left] >= rotateArray[right] ȷ����ת
		while (rotateArray[left] >= rotateArray[right]) {
			// �ֽ��
			if (right - left == 1) 
			{
				mid = right;
				break;
			}//if
			mid = left + (right - left) / 2;
			// rotateArray[left] rotateArray[right] rotateArray[mid]�������
			// �޷�ȷ���м�Ԫ��������ǰ�滹�Ǻ���ĵ���������
			// ֻ��˳�����
			if (rotateArray[left] == rotateArray[right] && rotateArray[left] == rotateArray[mid]) 
			{
				return MinOrder(rotateArray, left, right);
			}//if
			// �м�Ԫ��λ��ǰ��ĵ���������
			// ��ʱ��СԪ��λ���м�Ԫ�صĺ���
			if (rotateArray[mid] >= rotateArray[left]) 
			{
				left = mid;
			}//if
			// �м�Ԫ��λ�ں���ĵ���������
			// ��ʱ��СԪ��λ���м�Ԫ�ص�ǰ��
			else
			{
				right = mid;
			}//else
		}//while
		return rotateArray[mid];
	}
private:
	// ˳��Ѱ����Сֵ
	int MinOrder(vector<int> &num, int left, int right) 
	{
		int result = num[left];
		for (int i = left + 1; i < right; ++i) 
		{
			if (num[i] < result) 
			{
				result = num[i];
			}//if
		}//for
		return result;
	}
};

int main()
{
	
	return 0;
}