#define _CRT_SECURE_NO_WARINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

//û�����������Ľ��� https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-by-leetcode-soluti/

//����1����̬�滮
/************************************************************************/
/*  ִ����ʱ :128 ms, ������ C++ �ύ�л�����6.52%���û�
    �ڴ����� :7.8 MB, ������ C++ �ύ�л�����100.00%���û�
/************************************************************************/
int lengthOfLIS1(vector<int>& nums)
{
    int len = nums.size();
    if (len == 0)
        return len;

    vector<int> dp(len, 0);
    //ͳ�������һ��Ԫ��Ϊ��β������������е�Ԫ�ظ���
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


//����2��̰��+���ֲ��ң���¼����������е�ĩβԪ�ص���Сֵ
/************************************************************************/
/*  ִ����ʱ :0 ms, ������ C++ �ύ�л�����100.00%���û�
    �ڴ����� :7.7 MB, ������ C++ �ύ�л�����100.00%���û�
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

    //����nums�����nums[i] > d[len]����nums[i]�ӵ�d[len+1]
    for (int i = 1; i < len; ++i)
    {
        //if(nums[i] > dEndMin[dEndMin.size()])
        if (nums[i] > d[dSize-1])
        {
            ++dSize;
            d[dSize-1] = nums[i];
        }
        else  // �ҵ� d[j-1] < nums[i] < d[j]��λ�ã����滻 dEndMin[j]
        {     // ������֤d�ǵ��������ģ���˶�d�ö��ֲ��Ҹ���
            int l = 0;
            int r = dSize-1;
            int idx = 0;
            int mid; // �ҵ����mid
            while (l <= r)  //�Ⱥŵ��������ڸ���mid����Ϊwhileѭ������l����r�Ѿ����ˣ�����mid���Ǿɵ�
            {
                mid = (l + r) / 2;
                if (d[mid] < nums[i])  // ���� 2 5 8Ҫ����7����ʱposӦ�ú�lһ��
                {
                    l = mid + 1;
                    idx = l;
                }
                else if (d[mid] > nums[i])
                { 
                    r = mid - 1;  // ���� 2 5 8Ҫ����4����ʱposӦ�ú�r+1һ��
                    idx = r + 1;
                }
                else
                { 
                    idx = mid;    // ���� 2 5 8Ҫ����5����ʱposӦ�ú�midһ��
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