/*
https://leetcode.com/problems/fruit-into-baskets/
滑动窗口解决
*/

class Solution {
public:
    int totalFruit(vector<int> &fruits)
    {
        unordered_map<int, int> cat;
        int res = 0;
        int left = 0;
        int right = 0;
        for (int i = 0; i < fruits.size(); i++) {
            if (cat.count(fruits[i]) < 1 && cat.size() == 2) {
                while (--cat[fruits[left]] > 0) {
                    left++;
                }
                cat.erase(fruits[left]);
                ++left;
            }
            ++cat[fruits[i]];
            right++;
            res = max(res, right - left);
        }

        return res;
    }
};
