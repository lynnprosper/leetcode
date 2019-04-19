/*
1. 原题
https://leetcode.com/problems/next-permutation/

2. 思路
题意：求出给定序列的下一个序列。

思路：首先要理解什么是元素的全排列。一组数的全排列有多个方法获得。

题目要求的是字典序的排列组合。对于字典序的排列，两个相邻的排列要求前缀尽可能多。

所以下一个排列如何求呢？ 其实全排列过程是从后向前逆序的过程。

于是，我们从后向前找下标i-1元素小于后一个元素，然后再从i以后的元素找出比其大的最小元素。

交换后，对i以后的元素升序即是所求序列。

当然，边界情况：序列已经逆序，那么下一个就是升序序列。
*/

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        x,y = -1, -1
        for i in range(len(nums)-1, 0, -1):
            if nums[i-1] < nums[i] :  #从后找到第一个小的
                x = i-1
                break
        if x == -1 : #列表逆序，下一个排列是升序
            nums.sort()
        else:
            for i in range(x+1, len(nums)): #找到比x大且最小的
                if (nums[i] > nums[x]):
                    y = i
                else:
                    break;
            nums[x], nums[y] = nums[y], nums[x]
            nums[x+1:] = reversed(nums[x+1:])
