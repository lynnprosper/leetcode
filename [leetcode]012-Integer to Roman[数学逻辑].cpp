/*
1. 原题：
https://leetcode.com/problems/integer-to-roman/

2. 思路
题意：给出一个数字，输出罗马表示的字符串。
我直接用的暴力，简单的方法是先定义好要输出的字符串。
*/
class Solution {
public:
    string intToRoman(int num) {
        int x = 0;
        string re;
        while (num > 0)
        {
            if (num >= 1000)
            {
                x = num / 1000;
                num %= 1000;
                for (int i = 0; i < x; i++)
                    re.push_back('M');
            }
            else if (num >= 900)
            {
                num -= 900;
                re.append("CM");
            }
            else if (num >= 500)
            {
                num -= 500;
                re.push_back('D');
            }
            else if (num >= 400)
            {
                num -= 400;
                re.append("CD");
            }
            else if (num >= 100)
            {
                x = num / 100;
                num %= 100;
                for (int i = 0; i < x; i++)
                    re.push_back('C');
            }
            else if (num >= 90)
            {
                num -= 90;
                re.append("XC");
            }
            else if (num >= 50)
            {
                num -= 50;
                re.push_back('L');
            }
            else if (num >= 40)
            {
                num -= 40;
                re.append("XL");
            }
            else if (num >= 10)
            {
                x = num / 10;
                num %= 10;
                for (int i = 0; i < x; i++)
                    re.push_back('X');
            }
            else if (num >= 9)
            {
                re.append("IX");
                break;
            }
            else if (num >= 5)
            {
                num -= 5;
                re.push_back('V');
            }
            else if (num >= 4)
            {
                re.append("IV");
                break;
            }
            else
            {
                for (int i = 0; i < num; i++)
                    re.push_back('I');
                num = 0;
            }
        }
        
        return re;
    }
};
