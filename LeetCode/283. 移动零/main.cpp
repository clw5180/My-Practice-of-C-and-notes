#define _CRT_SECURE_NO_WARINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

//void swap(int& a, int& b)
//{
//    int tmp = a;
//    a = b;
//    b = tmp;
//    return;
//}

/************************************************************************/
/* ִ����ʱ :12 ms, ������ C++ �ύ�л�����47.25%���û�
   �ڴ����� :8.8 MB, ������ C++ �ύ�л�����100.00%���û�
/************************************************************************/
void moveZeroes(vector<int>& nums)
{
    int len = nums.size();
    if (len == 0)
        return;

    int idx = 0;
    for (int i = 0; i < len; ++i)
    {
        if (nums[i] != 0)
        {
            swap(nums[idx], nums[i]);
            idx++;
        }
    }
    return;
}

void main()
{
    vector<int> nums = { 0,1,0,3,12 };
    moveZeroes(nums);
}