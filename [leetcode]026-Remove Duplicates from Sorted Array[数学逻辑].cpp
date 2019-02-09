/*
1. 原题
https://leetcode.com/problems/remove-duplicates-from-sorted-array/

2. 思路
题意：给定一个数组，去重并输出长度。

比较简单。由于是有序数组，设置一个下标指示变量pos就行了。
遍历比较相邻的整数，不等则nums[++pos] = nums[i].
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) 
            return 0;
        int pos(0);
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[pos])
            {
                nums[++pos] = nums[i];
            }
        }
        return ++pos;
    }
};
