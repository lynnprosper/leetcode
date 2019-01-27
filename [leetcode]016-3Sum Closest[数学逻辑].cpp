/*
1. 原题
https://leetcode.com/problems/3sum-closest/

2. 思路
题意：给出一组整数和一个目标数，求三个数的和，使其尽可能逼近或等于目标值。

中等难度。此题是求两个数和的扩展。对于两个数，一般是采用快慢指针的算法，复杂度O(N).

显然，对于三个数，锚定一个数，另两个数采用快慢指针的算法。总复杂度O(n^2).

求解前，对数组升序排序，遍历每个数的过程中，若三数和更接近目标值，更新结果变量。
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int res = nums[0]+nums[1]+nums[2];
        
        for (int i = 0; i < len; i++)
        {
            int lt = i+1, rt = len-1, dd = target - nums[i];
            int tp; //临时变量
            while (lt < rt) //快慢指针思想
            {
                tp = nums[lt] + nums[rt];
                if (tp == dd)
                    return target; //相等，直接输出结果
                else
                {
                    if (abs(dd-tp) < abs(target - res)) //更新最佳结果
                        res = tp + nums[i];
                    if (tp < dd) //左端递增
                        lt++;
                    else //右端递减
                        rt--;
                }
            }
        }
        return res;
    }
};
