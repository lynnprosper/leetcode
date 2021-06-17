/*  
用dfs需要剪枝加记忆化搜索，否则超时。
用bfs也可。

https://www.nowcoder.com/questionTerminal/a4b7f297ad0e46a0a1fbac4d2da83a63
*/

#include<stdio.h>
#include<iostream>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<unordered_set>
#include<unordered_map>
using namespace std;
 
int n, sx,sy, ex, ey;
int md = 0x3fffffff;
int direc[5] = {-1,0,1,0,-1};
bool isfind = false;
 
void dfs(vector<vector<int>> &G, vector<vector<int>> &vis, int r, int c, int dis)
{
        if (dis >= md || (vis[r][c] != 0 && dis >= vis[r][c]))
        return;
    vis[r][c] = dis;
    if(r == ex && c == ey)
    {
        isfind = true;
        md = min(md, dis);
        return;
    }
     
    int nx, ny;
    for(int i = 0; i < 4; i++)
    {
        nx = r+direc[i];
        ny = c+direc[i+1];
        if(nx > -1 && nx < n && ny > -1 && ny < n && G[nx][ny] == 1)
        {
            
            dfs(G,vis, nx, ny, dis+1);
        }
    }
    return;
}
 
int main()
{
    cin >> n;
    cin >> sy >> sx >> ey >> ex;
    vector<vector<int>> G(n, (vector<int>(n,0)));
    vector<vector<int>> vis(n, (vector<int>(n,0)));
    for(int i = 0; i < n; i++)
    {
        char ch;
        for(int j = 0; j< n; j++)
        {
            cin >> ch;
            if(ch != '#' && ch != '@')
                G[i][j] = 1;
        }
    }
    dfs(G, vis, sx, sy, 0);
    if(isfind)
    cout << md;
    else
        cout << -1;
     
    return 0;
}
