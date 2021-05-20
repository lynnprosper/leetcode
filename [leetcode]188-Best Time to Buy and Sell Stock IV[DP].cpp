/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/submissions/
动态规划题。
对于大于len/2的交易次数，只要有利润，就可以交易，无需动态规划。

第i次j天的交易最大利润怎么确定呢？要么当天不交易，取dp[i-1][j]，要么要交易。
关键是最后一次交易的利润怎么计算。因为涉及到一买一卖，卖出是j天的价格，买入的价格不一定是j-1天的价格，要以
能获得最大利润为目的。所以要设置一个变量，记录i-1次j-1天后的最大利润减去后面的买入价格，这个值要尽可能大。
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if (len < 2 || k < 1)
            return 0;
        if (k >= len/2)
            return getall(prices);
        
        
        vector<vector<int> > dp(k+1, vector<int>(len, 0));
        
        for (int i = 1; i <= k; i++)
        {
            int tmpmax = -prices[0];
            for (int j = 1; j < len; j++)
            {
                dp[i][j] = max(dp[i][j-1], tmpmax+prices[j]);
                tmpmax = max(dp[i-1][j-1]-prices[j], tmpmax);
            }
        }
        
        return dp[k][len-1];
    }
    
    int getall(vector<int>& prices)
    {
        int res = 0;
        int last = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i-1])
            {
                res += (prices[i] -prices[i-1]);
                
            }
        }
        
        return res;
    }
};
