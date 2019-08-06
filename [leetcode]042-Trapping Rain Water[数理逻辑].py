'''
1. 原题
https://leetcode.com/problems/trapping-rain-water/

2. 思路
题意，求出柱体间能够容纳的水面积。

考查逻辑能力。我们找到一个居中的最大值，

然后从两边向中间遍历累加值即可。
'''

# find the max value of center, then collect water from side to center
class Solution:
    def trap(self, height: List[int]) -> int:
        if len(height) < 2:
            return 0
        mv, mv_id = -1, -1 #max value and its index
        for i, val in enumerate(height):
            if val >mv:
                mv = val
                mv_id = i
                
        last , area= height[0], 0
        for i in range(1, mv_id):
            if height[i] > last: # here we cannot collect water
                last = height[i]
            else:
                area += last-height[i]
        last= height[len(height)-1]
        for i in range(len(height)-1, mv_id, -1):
            if height[i] > last:
                last = height[i]
            else:
                area += last-height[i]
        return area
