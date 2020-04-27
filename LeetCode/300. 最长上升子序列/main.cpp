#define _CRT_SECURE_NO_WARINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

//没做出来，看的解析 https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-by-leetcode-soluti/

//方法1：动态规划
/************************************************************************/
/*  执行用时 :128 ms, 在所有 C++ 提交中击败了6.52%的用户
    内存消耗 :7.8 MB, 在所有 C++ 提交中击败了100.00%的用户
/************************************************************************/
int lengthOfLIS1(vector<int>& nums)
{
    int len = nums.size();
    if (len == 0)
        return len;

    vector<int> dp(len, 0);
    //统计以最后一个元素为结尾的最长上升子序列的元素个数
    for (int i = 0; i < len; ++i)
    {
        dp[i] = 1;
        for (int j = 0; j < i; ++j)
        {
            if (nums[j] < nums[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    return *max_element(dp.begin(), dp.end());
}


//方法2：贪心+二分查找，记录最长上升子序列的末尾元素的最小值
/************************************************************************/
/*  执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
    内存消耗 :7.7 MB, 在所有 C++ 提交中击败了100.00%的用户
/************************************************************************/
int lengthOfLIS(vector<int>& nums)
{
	int len = nums.size();
	if (len == 0)
		return len;

	//vector<int> d = {nums[0]};
	vector<int> d(len, 0);
    int dSize = 1;
    d[0] = nums[0];

    //遍历nums，如果nums[i] > d[len]，则将nums[i]加到d[len+1]
    for (int i = 1; i < len; ++i)
    {
        //if(nums[i] > dEndMin[dEndMin.size()])
        if (nums[i] > d[dSize-1])
        {
            ++dSize;
            d[dSize-1] = nums[i];
        }
        else  // 找到 d[j-1] < nums[i] < d[j]的位置，并替换 dEndMin[j]
        {     // 由于易证d是单调递增的，因此对d用二分查找更快
            int l = 0;
            int r = dSize-1;
            int idx = 0;
            int mid; // 找到这个mid
            while (l <= r)  //等号的意义在于更新mid，因为while循环里面l或者r已经变了，但是mid还是旧的
            {
                mid = (l + r) / 2;
                if (d[mid] < nums[i])  // 比如 2 5 8要插入7，这时pos应该和l一样
                {
                    l = mid + 1;
                    idx = l;
                }
                else if (d[mid] > nums[i])
                { 
                    r = mid - 1;  // 比如 2 5 8要插入4，这时pos应该和r+1一样
                    idx = r + 1;
                }
                else
                { 
                    idx = mid;    // 比如 2 5 8要插入5，这时pos应该和mid一样
                    break;
                }
            }
            d[idx] = nums[i];
        }
    }

    return dSize;
}


void main()
{
    //vector<int> vec = { 10, 9, 2, 5, 3, 7, 101, 18 };
    vector<int> vec = { 3, 5, 6, 2, 5, 4, 19, 5, 6, 7, 12 }; // 2 4 5 6 7 12
    cout << lengthOfLIS(vec) << endl;
}