/*
1. 原题
https://leetcode.com/problems/container-with-most-water/

2. 思路
题意：给出一组数，表示坐标轴上对应的高度，求出两者所围成的最大蓄水量。中等难度。

显然，暴力算法，时间复杂度O(n^2).

不妨先假设最外围的两个围成的面积最大。因为面积由最小的高度决定，于是下一步我们替换掉当前较小的，才有可能求出更大的，

然后再判断最新两者围成的面积。遍历一遍即可。时间复杂度O(N)。
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() -1;
        int re = min(height[0], height[right]) * right;
        while (left < right)
        {
            if (min(height[left], height[right]) * (right-left) > re)
                re = min(height[left], height[right]) * (right-left);
            if (height[left] < height[right]) //替换较小的
                left++;
            else
                right--;
        }
        
        return re;
    }
};
