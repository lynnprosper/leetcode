/*
DFS遍历，加记忆化存储，防止爆栈；
*/

class Solution {
public:
    int dfs(int x, int y, int pre, vector<vector<int>>& matrix, vector<vector<int>>& res) {
        if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size() || matrix[x][y] <= pre) {
            return 0;
        }
        if (res[x][y] != 0) { //已经有了，直接返回
            return res[x][y];
        }
        
        res[x][y] = max(res[x][y], dfs(x+1, y, matrix[x][y], matrix, res) + 1);
        res[x][y] = max(res[x][y], dfs(x-1, y, matrix[x][y], matrix, res) + 1);
        res[x][y] = max(res[x][y], dfs(x, y+1, matrix[x][y], matrix, res) + 1);
        res[x][y] = max(res[x][y], dfs(x, y-1, matrix[x][y], matrix, res) + 1); // 存储处理好的数据
        return res[x][y];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> res(matrix.size(), vector<int>(matrix[0].size(), 0)); // 记忆化存储
        int path = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                path = max(path, dfs(i, j, -1, matrix, res));
            }
        }
        return path;
    }
};
