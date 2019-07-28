/*
1. 原题
https://leetcode.com/problems/search-insert-position/

2. 思路
题意：比较简单，返回给定值在有序序列的索引。

直接用二分查找即可。
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return 0;
        
        int left = 0, right = nums.size()-1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] < target)
            {
                left = mid+1;
            }
            else if (nums[mid] > target)
            {
                right = mid-1;
            }
            else
                return mid;
        }
        
        return left;
    }
};
