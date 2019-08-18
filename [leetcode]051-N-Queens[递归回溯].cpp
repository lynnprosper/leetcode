/*
1. 原题
https://leetcode.com/problems/n-queens/

2. 思路
题意，经典的n皇后问题。规则是，同一行，列和两条斜对角线不能有两个皇后。

算法：递归回溯。从第一行开始，选择一个位置，验证是否符合条件，然后继续递归下一行。

注意，判断条件时，因为我们是按行从上往下递归的，所以同一行不可能有两个皇后。
*/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        dim = n;
        vector<string> mv(n, string(n, '.'));
        dfs(mv, 0);
        return res;
    }
    
    void dfs(vector<string> &mv, int row)
    {
        if (row == dim)  //right answer
        {
            res.push_back(mv);
            return;
        }
        
        for (int i = 0; i < dim; i++)
        {
            if (isValid(mv, row, i)) //current position is valid
            {
                mv[row][i] = 'Q';
                dfs(mv, row+1);     //process next row by recursion
                mv[row][i] = '.';
            }
        }
        return;
    }
    
    bool isValid(vector<string> &mv, int x, int y)
    {
        for (int i = 0; i < x; i++ ) // validate column data, here no need for row
        {                            // because we process row up to down
            if (mv[i][y] != '.')
                return false;
        }
        for (int i=x-1, j = y-1; i > -1 && j > -1; i--,j--) // master diagonal
        {
            if (mv[i][j] != '.')
                return false;
        }
        for (int i = x-1, j = y+1; i>-1 && j<dim; i--,j++) // subdiagnonal
        {
            if (mv[i][j] != '.')
                return false;
        }
        return true;
    }
private:
    vector<vector<string>> res;
    int dim;
};
