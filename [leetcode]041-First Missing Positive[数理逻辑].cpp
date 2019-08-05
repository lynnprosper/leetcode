/*
1. 原题
https://leetcode.com/problems/first-missing-positive/

2. 思路
题意：给出一个数组，输出数组中未包含的最小正数。

如果题目未限定空间复杂度O(1), 那么我们很容易做出来。直接开个含N+1元素的数组判断即可。

现在，只有多想一想。利用原数组的操作，也可以求出来。

毕竟，输出结果最大为n+1. 那么，我们可以把每一个（1~n-1）正数k放在下标k-1处。

最后，遍历一遍数组，若num[k-1] != k, 则k即是我们要求的结果。
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; i++)
        {
            //*** in loop, the order condition is not arbitrary
            while (nums[i] <= len && nums[i] > 0 && nums[i] != nums[nums[i]-1])
            {
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for (int i = 0; i < len; i++)
        {
            if(nums[i] != i+1)
            {
                return i+1; //** get the result
            }
        }
        
        return len+1;
    }
};
