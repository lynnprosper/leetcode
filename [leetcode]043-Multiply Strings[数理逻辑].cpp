/*
1. 原题：
https://leetcode.com/problems/multiply-strings/

2. 思路
题意，给出两个数（字符串形式），求出相乘后的结果。

其实就是大整数的乘法。逐位相乘就好。
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        
        reverse(num1.begin(), num1.end()); // 为了方便从0开始计算，先逆转
        reverse(num2.begin(), num2.end());
        string res("");
        for(int i = 0; i < num2.size(); i++)
        {
            string tmp = multiply_one(num1, num2[i]-'0');
            add(res, tmp, i);
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    string multiply_one(string& st, int x) //** 乘数是个位
    {
        string res;
    
            int carry = 0; // 进位信息
            int num = 0;
            for (auto em: st)
            {
                num =  ((em-'0')*x + carry) % 10;
                carry = ((em-'0')*x + carry) / 10;
                res.push_back('0'+num);
            }
            if (carry > 0)
            {
                res.push_back('0'+carry);
            }
        
        return res;    
    }
    
    void add(string &s1, string &s2, int x) // 加法
    {
        if (s2.size()< 1)
            return ;
        if (s1.size() < 1)
        {    
            s1 = s2;
            return;
        }
        while (s1.size() < x)
        {
            s1.push_back('0');
        }
        int carry = 0;
        for (int i = 0; i < s2.size(); i++)
        {
            if (x+i < s1.size())
            {
                int num = (s1[x+i] - '0' + s2[i] - '0' + carry) % 10;
                carry = (s1[x+i] - '0' + s2[i] - '0' + carry) / 10;
                s1[x+i] = '0'+num;
            }
            else
            {
                int num = (s2[i] - '0' + carry) % 10;
                carry = (s2[i] - '0' + carry) / 10;
                s1.push_back('0'+num);
            }
        }
                    if (carry > 0)
                s1.push_back('0'+carry);
    }
};
