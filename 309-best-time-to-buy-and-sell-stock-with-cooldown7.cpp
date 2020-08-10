class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int len = prices.size();
        
        if (len == 0 || len == 1) {
            return 0;
        }
        
        int dp[2][3];
        
        dp[0][0] = -prices[0];
        dp[1][0] = 0;
        dp[0][1] = max(dp[0][0], dp[1][0] - prices[1]);
        dp[1][1] = max(dp[1][0], dp[0][0] + prices[1]);
        
        for (int i = 2; i < len; i++) {
            dp[0][i % 3] = max(dp[0][(i - 1) % 3], dp[1][(i - 2) % 3] - prices[i]);
            dp[1][i % 3] = max(dp[1][(i - 1) % 3], dp[0][(i - 1) % 3] + prices[i]);
        }
        
        return dp[1][(len - 1) % 3];
    }
};