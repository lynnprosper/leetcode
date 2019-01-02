/*
1. 原题
https://leetcode.com/problems/median-of-two-sorted-arrays/

2. 思路
题意：给出两个有序序列，求出合并后的有序序列的中位数。复杂度要求O(log (m+n)).

思路：复杂度限定，方法只能用二分法了。不少朋友可能做过元素个数相等的两个序列求中位的题目。

这里个数不定，如何二分查找呢？

首先，初始查找第k = ( (m+n)/2)大的数， 各自查找居中位置k/2处的元素a和b。

若a<b, 那么所求元素肯定不在a之前的元素里（设共p个), 那么下次递归时就查找第k-p大的数，而A序列丢弃a前面的，

从a后面的元素开始。

以上是宏观思路。下面要找出递归结束条件。

1. 某个序列A元素个数为0， 那么第k大就是B序列的B[k-1], 递归结束。

2. 若k=1, 那么所求值即A[0]和B[0]的较小值。（0是一般意义上的，即序列第一个位置）

此外，k/2可能超出了序列的范围，这时，就把最后一个元素作为居中数。
*/

class Solution {
    private:
    int findK(vector<int>& nums1, int lt1, int rt1, 
              vector<int>& nums2, int lt2, int rt2, int k)
    {//**lt1, rt1是序列的起始和结束索引， k是查找第k个
        if (lt1 > rt1) //**递归结束
            return nums2[lt2+k-1];
        if (lt2 > rt2)
            return nums1[lt1+k-1];
        if (k == 1)
            return min(nums1[lt1], nums2[lt2]);
        
        int mp1 = min(lt1 + k/2-1, rt1);
        int mp2 = min(lt2+ k/2 - 1, rt2);
        if (nums1[mp1] < nums2[mp2])
        {
            return findK(nums1, mp1+1, rt1, 
                         nums2, lt2, rt2, k-mp1+lt1-1); //**mp1-lt1+1 是舍弃的个数
        }
        else
            return findK(nums1, lt1, rt1, 
                         nums2, mp2+1, rt2, k-mp2+lt2-1);
 
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        return (findK(nums1, 0, m-1, nums2, 0, n-1, (m+n+1)/2)
                + findK(nums1, 0, m-1, nums2, 0, n-1, (m+n+2)/2))/2.0;
    }
};
