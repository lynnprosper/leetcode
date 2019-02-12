/*
1. 原题
https://leetcode.com/problems/implement-strstr/

2. 思路
查找字符串中是否含有子串，返回初始下标。

比较简单。由于STL里有find函数，可以直接使用。

也可以自己写匹配算法。
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;
        return haystack.find(needle);
    }
};
