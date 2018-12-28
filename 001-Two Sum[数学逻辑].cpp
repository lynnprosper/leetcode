/*
https://leetcode.com/problems/two-sum/
基本逻辑题。给出一组数据，输出两个数和等于给定值的下标。
比较简单，直接利用multimap即可（数据可重复，用multimap）。
判断另一个值是否在map里。已AC.
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        multimap<int, int> mp;
        vector<int> rev(2, 0);
        
        for (int i = 0; i < nums.size(); i++)
        {
            mp.insert(make_pair(nums[i], i));
        }
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            auto its = mp.find(target-(it->first));
            if (its != mp.end())
            {
                rev[0] = it->second;
                rev[1] = (its->second == rev[0] ? ((++its)->second) : its->second);
                break;
            }
        }

        return rev;
        
    }
};
