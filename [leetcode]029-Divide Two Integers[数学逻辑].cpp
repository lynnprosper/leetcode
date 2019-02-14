/*
1. 原题
https://leetcode.com/problems/divide-two-integers/

2. 思路
题意：要求不能使用乘除和取余，求出商值。

中等难度。可以回想出计算机是如何乘除的--利用移位。

这里，我们同样也可以利用移位得出。为了便于处理边界，

先将int转成长整型的绝对值，防止溢出。
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        
        long long div = abs((long long)dividend);
        long long dis = abs((long long)divisor);
        long long res = 0;
        while (div >= dis)
        {
            long long qt = 1, dd = dis;
            while (div >= dd) //移位累加商
            {
                res += qt;
                div -= dd;
                dd <<= 1; //左移一位表示2倍
                qt <<= 1;
            }
        }
        
        if ((dividend^divisor) < 0) //异号
            return -res;
        else return res;
    }
};
