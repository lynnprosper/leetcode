/*
1. 原题：
https://leetcode.com/problems/roman-to-integer/

2. 思路：
题意：罗马数字表示的整数转化成阿拉伯数字。比较简单。
遍历每个字符累加即可，若遇到前置的，再减去多加的。
*/

class Solution {
public:
    int romanToInt(string s) {
        int h[128] = {0};
        h['I'] = 1;
        h['V'] = 5;
        h['X'] = 10;
        h['L'] = 50;
        h['C'] = 100;
        h['D'] = 500;
        h['M'] = 1000;
        int last = INT_MAX;
        int re = 0;
        
        for (auto x : s)
        {
            if (h[x] <= last)
                re += h[x];
            else
                re = re + h[x] - 2*last;
            last = h[x];
        }
        
        return re;
    }
};
