/*
题意： 给定n个w，m个b，要求对于任意一个前缀cnt(w)-cnt(b) <= k。问有多少种放置w和b的方案数。 1 < = n , m < = 1 e 6 1<=n,m<=1e6 1<=n,m<=1e6

题解： 卡特兰数的应用。把y = cnt(w), x = cnt(b)。那么原式子变为y <= x + k。画出图像如下，现在要走到(m, n)，方案数位C(m+n,m)。

不能走的线是y = k + x + 1。所有经过这条线的路径都可以进行投影到绿色的线，最后会走到A点(n-k-1,m+k+1)。

这里有个推导坐标的小技巧，所有的投影对称都是利用y=k+x+1进行的，因此会经过C点，Cy = n。然后根据y=k+x+1，可以推导出Cx = n - k - 1。那么Ax = Cx = n - k - 1。
————————————————
版权声明：本文为CSDN博主「第25小时」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/m0_49959202/article/details/117912488

利用递推公式：C(n,k) = (n-k+1)/k*C(n,k-1)，递推求组合数
so ans = c(n+m,n) - c(n+m, m-k-1)
*/

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int maxn = 1e3;
typedef long long ll;
int n,k;
ll C[maxn];
 
int main()
{
    n = 6;
    memset(C,0,sizeof(C));
    C[0] = 1;
    for(int i = 1; i <= n; i++)
    {
      C[i] = C[i-1]*(n-i+1)/i;
    }
    //输出C(6,4)
    printf("%lld\n",C[4]);
    return 0;
}
