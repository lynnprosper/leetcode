/*
1. 原题
https://leetcode.com/problems/spiral-matrix/

2. 思路
题意： 数学逻辑题，中等，环形输出矩阵。
算法： 按层循环输出即可。
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int left = 0, right = matrix[0].size()-1, top = 0, bottom = matrix.size()-1;
        i
        while(1)
        {
            // from left to right;
            for (int k = left; k <= right; k++)
            {
                res.push_back(matrix[top][k]);
            }
            top++;
            if (top > bottom)
                break;
            // from top to bottom;
            for (int k = top; k <= bottom; k++)
            {
                res.push_back(matrix[k][right]);
            }
            right--;
            if (left > right)
                break;

            // from right to left;
            for (int k = right; k >= left; k--)
            {
                res.push_back(matrix[bottom][k]);
            }
            bottom--;
            if (top > bottom)
                break;

            // from bottom to top;
            for (int k = bottom; k >= top; k--)
            {
                res.push_back(matrix[k][left]);
            }
            left++;
            if (left > right)
                break;
        }
        
        return res;
    }
};
