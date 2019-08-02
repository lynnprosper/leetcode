/*
1. 原题
https://leetcode.com/problems/combination-sum/

2. 思路
题意：给定一个序列和数值。从序列中选出一部分元素，使其和等于给定的目标值。

这题本质上是背包问题。由于题目要输出所有的情况，这里直接采用dfs回溯算法求解。

已AC。
*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        dfs(current, 0, 0, target, candidates);
        
        return res;
    }
    
    void dfs(vector<int>& cur, int index, int sum, int target, vector<int>& candidates)
    {
        if (sum == target)
        {
            res.push_back(cur); //our result
        }
        else if (sum < target)  //continue dfs
        {   
            for (int i = index; i < candidates.size(); i++) // start from index because of repeatable numble
            {
                cur.push_back(candidates[i]);
                dfs(cur, i, sum+candidates[i], target, candidates);
                cur.pop_back();
            }
        }
    
        return;
    }
    
private:
    vector<vector<int>> res;
};
