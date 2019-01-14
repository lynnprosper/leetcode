/*
1. 原题
https://leetcode.com/problems/string-to-integer-atoi/

2. 思路
题意：字符串转为Int。中等难度，转换时累加即可。关键是如何处理边界问题。

a1)起始处的空白字符要忽略

a2)第一个有效字符可以为'+'或者'-'

a3)符号不能重复，必需紧跟数字，遇到非数字结束

a4)溢出int表示范围要输出INT_MAX或INT_MIN

前三个可以通过if-else来处理。溢出问题，我采用与INT_MAX/10来比较。

这里先说正数。比如解析到某数字p，若此时的num > INT_MAX/10, 那么肯定溢出。

若num = INT_MAX/10, 且p > 7,也溢出。（INT_MAX最后一位是7)

负数溢出同理。
*/

class Solution {
public:
    int myAtoi(string str) {
        int re = 0, flag = 0, i = 0, symb = 1;
        while (i < str.size() && str[i] == ' ') //除去空白字符
            i++;
        
        for (i; i < str.size(); i++)
        {
            if (isdigit(str[i]))
            {
                int current = str[i] - '0';
                if (re > INT_MAX/10 || (re == INT_MAX/10 && current > 7)) //判断溢出
                    return INT_MAX;
                else if (re < INT_MIN/10 || (re == INT_MIN/10 && current > 8))
                    return INT_MIN;
                
                flag = 1; //**表示处理有效数字
                re = re * 10 + current * symb;
            }
            else if (str[i] == '-' && flag == 0)
            {    symb = -1; //负数
                flag = 1;
            }
            else if (str[i] == '+' && flag == 0)
            {    
                symb = 1;
                flag =1;
            }
            else
                break;
        }
        
        return re;
    }
};
