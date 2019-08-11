/*
1. 原题 https://leetcode.com/problems/jump-game-ii/
2. 思路 题意：求出最小步数，使其到达最远距离。
显然，这可以利用贪心算法，局部最优得出全局最优。 
在每次遍历中，基于当前位置能够到达的最远距离，判断在该范围内，下次能到达的最远距离， 更新该距离即可。
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int index = 0, step = 0;
        while(index < nums.size()-1)
        {
            int range = nums[index]; //** the range it can jump to;
            int min_id, minv = 0; //*** each iteration, current target index and range
            for (int i = 1; i <= range; i++)
            {
                if (index+i >= nums.size()-1)
                    return step+1; //*** reach the end, return
                if (nums[index+i] >= minv) //** update target
                {
                    minv = nums[index+i];
                    min_id = index+i;
                }
                minv--; //*** decrease to compare with next range
            }
            index = min_id;
            step++;
        }
        return step;
    }
};
