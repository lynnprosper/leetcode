/*
https://leetcode.com/problems/get-equal-substrings-within-budget/
滑动窗口思想
*/

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int cost = 0;
        int left = 0;
        int right = 0;
        int res = 0;
        for(int i = 0; i < s.size(); i) {
            if (abs(s[i] - t[i]) + cost <= maxCost) {
                cost += abs(s[i] - t[i]);
                res = max(res, i+1 - left);
                i++;
            } else {
                while (left <= i && (abs(s[i] - t[i]) + cost > maxCost)) { // 超出阈值，移动左指针
                    cost -= abs(s[left] - t[left]);
                    left++;
                }
                if (left > i) {
                    i = left;
                    cost = 0;
                }
                //cost = max(0, cost);
            }
        }
        
        return res;
    }
};
