/*
1. 原题
https://leetcode.com/problems/zigzag-conversion/

2. 思路
题意：按照给出的z字形顺序输出字符串。模拟题，中等难度。

根据z字形顺序，把字符依次存储到row个字符串里，然后拼接起来输出。

时间复杂度O(N), 空间复杂度O(n).
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        vector<string> sv;
        sv.resize(numRows);
        
        int len = s.size();
        for (int i = 0; i < len; ) //**一个循环
        {
            for (int j = 0; j < numRows && i < len; j++) //**正向存储
            {
                sv[j].push_back(s[i++]);
            }
            for (int j = numRows-2; j > 0 && i < len; j--) //**反向存储到字符串里
                sv[j].push_back(s[i++]);
        }
        
        string res;
        for(auto x: sv)
            res += x;
        return res;
    }
};
