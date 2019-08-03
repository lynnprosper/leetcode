'''
1. 原题
https://leetcode.com/problems/combination-sum-ii/

2. 思路
题意：此题和39题基本一样。区别是结果中的元素不能重复。

既然不能重复，如何做到呢？我们可以先对序列排序，dfs时，紧挨着的候选序列里的元素一样时，跳过。

因为，第一次已经遍历过所有解空间，第二次再遍历会出现相同的求解子序列。

算法：依然是dfs回溯

已AC
'''

class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        self.ret = []
        current = []
        candidates = sorted(candidates)
        self.dfs(candidates, target, 0, current, 0)
        return self.ret
        
    def dfs(self, candidates, target, sum, cur, index):
        if sum == target:
            self.ret.append(cur[:])
        elif sum < target:
            for i in range(index, len(candidates)):
                if (i != index and candidates[i] == candidates[i-1]):
                    continue
                cur.append(candidates[i])
                self.dfs(candidates, target, sum + candidates[i], cur, i + 1)
                cur.pop()
        return

        
