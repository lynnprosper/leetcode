/*
1. 原题
https://leetcode.com/problems/reverse-integer/

2. 思路
题意：将一个整数逆转，若溢出需输出0.

比较简单，可以模拟字符串逆转的方法。我是利用字符串的逆转，

字符串<-->数字的转换来判定溢出问题。
*/

class Solution {
public:
    int reverse(int x) {
        if(x == 0) return 0;
        bool flag = 0;
        if (x < 0)
        {
            x = -x;
            flag = 1; //**表示负数
        }
        char ca[20]{0};
        sprintf(ca, "%d", x); //转换成字符串
        string sa(ca);
        
        while(sa[sa.size()-1] == '0') //**去掉0
            sa.pop_back();
        std::reverse(sa.begin(), sa.end()); //逆转
        int y;
        sscanf(sa.c_str(), "%d", &y); //逆转后的字符串转为数字
        sprintf(ca, "%d", y); //数字转为字符串
        string sb(ca);
        if (sa != sb) //不等表示溢出
            return 0;
        else
            return (flag == 1 ? -y : y);
    }
};
