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
/* 执行用时 :12 ms, 在所有 C++ 提交中击败了47.25%的用户
   内存消耗 :8.8 MB, 在所有 C++ 提交中击败了100.00%的用户
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