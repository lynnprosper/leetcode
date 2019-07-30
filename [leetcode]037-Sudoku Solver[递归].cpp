/*
1. 原题
https://leetcode.com/problems/sudoku-solver/

2. 思路
题意：解决一个数独问题，输出结果。

题目保证答案唯一。

数独问题一般都是用暴力破解思想，递归求解。

对每一个空格，依次填入1~9， 判断是否符合数独定义，递归求解下一个空格。

直到填完最后一个空格。

已AC.
*/

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
    bool solve(vector<vector<char>>& board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    for (int num = 1; num <10; num++)
                    {
                        if (isValid(board, i, j, '0'+num))
                        {
                            board[i][j] = '0'+num;
                            if (solve(board)) //dfs next one
                                return true;
                            else
                                board[i][j] = '.'; // number is invalid, recover it
                        }
                        
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValid(vector<vector<char>>& board, int row, int column, char ch)
    {
        for (int k = 0; k < 9; k++)
        {
            if (board[row][k] == ch) //row
                return false;
            if (board[k][column] == ch) //column
                return false;
            if (board[row/3*3+k/3][column/3*3+k%3] == ch) // sub-box
                return false;
        }
        
        return true;
    }
};
