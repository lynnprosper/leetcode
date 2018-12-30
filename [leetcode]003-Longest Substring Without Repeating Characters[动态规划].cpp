/*
1. 原题
https://leetcode.com/problems/longest-substring-without-repeating-characters/

2. 思路
题意：给出一个字符串， 求出最长的子串（连续的），要求所含的字符均不重复。

难度中等，这里采用动态规划的思想。

变量cp记录当前最长子串的起始位置，若与当前字符S[i]重复，则进行转移。

新的最长子串起始位置是重复的后一个位置，更新cp和当前长度；

若不重复，长度加1.

利用散列思想，记录字符的位置。

复杂度O(n).
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int h[128] = {0};
        fill(h, h+128, -1); //**初始为-1
        int len = 0, clen = 0, cp = 0; //**clen是当前识别出的长度，cp记录非重复子串起始位置
        for (int i = 0; i < s.size(); i++)
        {
            if (h[s[i]] >= cp) //**重复字符
            {
                cp = h[s[i]] + 1; //**更新起始位置
                clen = i - cp +1;
            }
            else
            {
                clen++;
                len = max(len, clen);
            }
            h[s[i]] = i; //**更新字符的索引
        }
        
        return len;
    }
};
