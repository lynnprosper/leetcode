"""
1. 原题
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

2. 思路
题意：给出一个有序序列和一个目标值，返回目标值下标的最小和最大值。

时间复杂度要求O(logn)，显然要用二分查找。

存在多个重复值，利用二分法分别得到最小和最大索引即可。
"""

class Solution:
    #binary search, return value index
    def getIndex(self, nums: List[int], x: int, left: int, right: int):
        if left > right:
            return -1
        mid = (left + right) // 2
        if nums[mid] < x:
            return self.getIndex(nums, x, mid+1, right)
        elif nums[mid] > x:
            return self.getIndex(nums, x, left, mid-1)
        else:
            return mid
    
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        re = []
        mid = self.getIndex(nums, target, 0, len(nums)-1)
        if mid < 0:
            return [-1, -1]
        else:
            left, right = mid, mid
            while (left > -1): #find the lowest index
                tmp = self.getIndex(nums, target, 0, left-1)
                if tmp > -1:
                    left = tmp
                else:
                    break;
            while (right > -1): #finde the highest index
                tmp = self.getIndex(nums, target, right+1, len(nums)-1)
                if tmp > -1:
                    right = tmp
                else:
                    break;
            re.append(left)   
            re.append(right)
            return re
        
