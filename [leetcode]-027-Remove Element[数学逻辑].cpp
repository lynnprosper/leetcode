/*
1. 原题
https://leetcode.com/problems/remove-element/

2. 思路
题意：给定一个数组和一个目标值，删除和目标值重复的元素。
比较简单。遍历时，把不等的元素前移就好了。
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int pos = 0;
        for (int x : nums)
        {
            if (x != val)
                nums[pos++] = x;
        }
        return pos;
    }
};
