'''
1. 原题
https://leetcode.com/problems/permutations/

2. 思路
题意：输出一个序列的全排列。

显然，最简单的就是递归求法。

比如[1, 2, 3, 4]，那就求：

1 + [2, 3, 4]的全排列

2 + [1, 3, 4]的全排列

3 + [1, 2, 4]的全排列

4 + [1, 2, 3]的全排列
'''

class Solution:
    
    def permute(self, nums: List[int]) -> List[List[int]]:
        self.res = []
        self.dfs(nums, 0, len(nums))
        return self.res
        
    def dfs(self, nums, left, right):
        if left==right:
            self.res.append(nums[0:right])
        for i in range(left, right):
            nums[left], nums[i] = nums[i], nums[left]
            self.dfs(nums, left+1, right)
            nums[left], nums[i] = nums[i], nums[left] //** swap it again to recover the order
