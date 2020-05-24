/*
一个直观的解决方案是使用计数排序的两趟扫描算法。
首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
你能想出一个仅使用常数空间的一趟扫描算法吗？

链接：https://leetcode-cn.com/problems/sort-colors
*/

// 我的解法1
    void sortColors(vector<int>& nums) {
        map<int, int> hashMap;
        int len = nums.size();
        for(int i=0;i<len;++i)
        {
            hashMap[nums[i]] += 1;
        }

        int count = 0;
        map<int, int>::iterator iter;
        for(iter = hashMap.begin(); iter!=hashMap.end(); ++iter)
        {
            for(int i=0; i<iter->second; ++i)
            {
                nums[count] = iter->first;
                ++count;
            }
        }
    }


// 我的解法2（最优， )
   void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    void sortColors(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        int i=0;
        
        while(i <= end)
        {
            if(nums[i] == 1)
                i++;
            else if(nums[i]==0)
            {
                swap(nums[start], nums[i]); 
                start++;
                i++; //因i左边的值已经扫描过了，所以i要++继续扫描下一位，
            }
            else if(nums[i]==2)
            {
                swap(nums[i], nums[end]);  //而与end交换的值，i未扫描，要停下来扫描一下，所以curr不用++。
                end--;
            }
        }    
    }
