'''
1. 原题
https://leetcode.com/problems/search-in-rotated-sorted-array/

2. 思路
题意：一个有序列表在某个位置前后两部分被调换，求出给定值的索引下标。

思路：题目要求时间复杂度log(n), 显然要用二分法。

我们依然考虑中间值n[mid]， 如果其小于最右值，那么右部分是有序的。

否则左部分有序。这样不断在某部分查找即可。
'''

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums)-1
        while left <= right:
            mid = (left + right)//2
            if (nums[mid] == target):
                return mid
            elif nums[mid] < nums[right]: #right part is ordered
                if target > nums[mid] and target <= nums[right]:
                    left = mid+1
                else:
                    right = mid-1
            else: #left part is ordered
                if target >= nums[left] and target < nums[mid]:
                    right = mid-1
                else:
                    left = mid+1
        return -1
            
