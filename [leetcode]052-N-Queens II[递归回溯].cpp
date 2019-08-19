/*
1.原题
https://leetcode.com/problems/n-queens-ii/

2. 思路
这题和上道题51思路是一样的，只不过，搜索到结果后不需要保存，

只需要计数就可以了。
*/

class Solution {
public:
    int totalNQueens(int n) {
        dim = n;
        vector<string> mv(n, string(n, '.'));
        dfs(mv, 0);
        return num;
    }
    
    void dfs(vector<string> &mv, int row)
    {
        if (row == dim)  //right answer
        {
            num++;
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
    int num{0};
    int dim;
};
