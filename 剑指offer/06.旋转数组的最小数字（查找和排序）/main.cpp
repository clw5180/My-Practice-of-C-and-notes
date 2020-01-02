#include <iostream>
#include <string>
#include <vector>

using namespace std;

//我的方案1：从头开始依次找到变小的那个值
//如果不考虑00010和01000这种带重复数字的情况，可能采用下面网友的二分法更快一些
//网友：这样的时间复杂度O(n)，如果想达到O(log(n))的复杂度呢？比如大家采用的二分查找的思路。
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

//网友方案2：二分，Java实现
/*
链接：https://www.nowcoder.com/questionTerminal/9f3231a991af4f55b95579b44b7a01ba
来源：牛客网
采用二分法解答这个问题，
mid = low + (high - low) / 2
需要考虑三种情况：
(1)array[mid] > array[high]:
出现这种情况的array类似[3, 4, 5, 6, 0, 1, 2]，此时最小数字一定在mid的右边。
low = mid + 1
(2)array[mid] == array[high] :
	出现这种情况的array类似[1, 0, 1, 1, 1] 或者[1, 1, 1, 0, 1]，此时最小数字不好判断在mid左边
	还是右边, 这时只好一个一个试 ，
	high = high - 1
	(3)array[mid] < array[high] :
	出现这种情况的array类似[2, 2, 3, 4, 5, 6, 6], 此时最小数字一定就是array[mid]或者在mid的左
	边。因为右边必然都是递增的。
	high = mid
	注意这里有个坑：如果待查询的范围最后只剩两个数，那么mid 一定会指向下标靠前的数字
	比如 array = [4, 6]
	array[low] = 4; array[mid] = 4; array[high] = 6;
如果high = mid - 1，就会产生错误， 因此high = mid
但情形(1)中low = mid + 1就不会错误

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


//网友方案3：二分
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
		// rotateArray[left] >= rotateArray[right] 确保旋转
		while (rotateArray[left] >= rotateArray[right]) {
			// 分界点
			if (right - left == 1) 
			{
				mid = right;
				break;
			}//if
			mid = left + (right - left) / 2;
			// rotateArray[left] rotateArray[right] rotateArray[mid]三者相等
			// 无法确定中间元素是属于前面还是后面的递增子数组
			// 只能顺序查找
			if (rotateArray[left] == rotateArray[right] && rotateArray[left] == rotateArray[mid]) 
			{
				return MinOrder(rotateArray, left, right);
			}//if
			// 中间元素位于前面的递增子数组
			// 此时最小元素位于中间元素的后面
			if (rotateArray[mid] >= rotateArray[left]) 
			{
				left = mid;
			}//if
			// 中间元素位于后面的递增子数组
			// 此时最小元素位于中间元素的前面
			else
			{
				right = mid;
			}//else
		}//while
		return rotateArray[mid];
	}
private:
	// 顺序寻找最小值
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