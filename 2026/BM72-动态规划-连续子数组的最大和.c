/*
https://www.nowcoder.com/practice/459bd355da1549fa8a49e350bf3df484?tpId=295&tqId=23259&sourceUrl=%2Fexam%2Foj%3FquestionJobId%3D10%26subTabName%3Donline_coding_page
BM72 连续子数组的最大和
描述
输入一个长度为n的整型数组array，数组中的一个或连续多个整数组成一个子数组，子数组最小长度为1。求所有子数组的和的最大值。

输入：
[1,-2,3,10,-4,7,2,-5]
返回值：
18
说明：经分析可知，输入数组的子数组[3,10,-4,7,2]可以求得最大和为18 
*/

/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * 
 * @param array int整型一维数组 
 * @param arrayLen int array数组长度
 * @return int整型
 */
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#include <stdlib.h>
int FindGreatestSumOfSubArray(int* array, int arrayLen ) {
    // write code here
    int *dp = (int *)malloc(sizeof(int) * arrayLen);
    dp[0] = array[0];
    int maxSum = dp[0];
    for (int i = 1; i < arrayLen; i++) {
        // 转移方程，dp[i]表示以i元素结尾的最大子序列和
        dp[i] = MAX(dp[i-1] + array[i], array[i]);
        maxSum = MAX(maxSum, dp[i]);
    }
    return maxSum;
}
