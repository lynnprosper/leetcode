/*
1. 原题
https://leetcode.com/problems/longest-common-prefix/

2. 思路
题意：找出一组字符串的最长公共前缀。比较简单。
直接垂直扫描，比较每个字符是否相等。也可以用二分法，分而治之法等。
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        
        int len = INT_MAX;
        int p = 0;
        for (auto x : strs)
            len = min(len, (int)(x.size()));
        for (p; p < len; p++)
        {
            for (auto x : strs)
            {
                if (strs[0][p] != x[p]) //*这里就判断出结果了。
                    goto end;
            }
        }
        
        end:
        return strs[0].substr(0, p);
    }
};
