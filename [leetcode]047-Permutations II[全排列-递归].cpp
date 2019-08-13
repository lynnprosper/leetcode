/*
1. 原题
https://leetcode.com/problems/permutations-ii/

2. 思路
和上题类似，求全排列，不过给出的元素存在重复值。

算法：递归。关键是如何去重。

1. 首先进行排序，遇到前后相等的，只递归第一次就行。

2. 递归时的数组参数按值传入，不应按引用。以免子递归搞乱顺序。
*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end()); //ensure equal numbers adjoin
        dfs(nums, 0, nums.size());
        return res;
    }
    
    //**nums must be introduced by value, not referrence
    //** in case subsequent dfs disorders current list
    void dfs(vector<int> nums, int left, int right) 
    {
        if (left == right)
        {
            res.push_back(nums);
            return;
        }
        
        for (int i = left; i < right; i++)
		{
			if (i > left && nums[i] == nums[i - 1]) // omit equal number
				continue;
            
			if (i == left || nums[i] != nums[left]) // omit equal number
			{
				swap(nums[i], nums[left]);
				dfs(nums, left + 1, right);
				//swap(nums[i], nums[left]); // here no need to swap
			}
		}
    }
private:
    vector<vector<int>> res;
};
