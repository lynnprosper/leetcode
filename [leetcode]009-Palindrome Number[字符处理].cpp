/*
1. 原题
https://leetcode.com/problems/palindrome-number/

2. 思路
题意：判断一个整数是否回文。比较简单，转成字符串或者反向计算各数位即可。
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        char ch[15]{0};
        sprintf(ch, "%d", x);
        string sa(ch), sb(ch);
        reverse(sb.begin(), sb.end()); //逆转
        if (sa == sb)
            return true;
        else
            return false;
    }
};
