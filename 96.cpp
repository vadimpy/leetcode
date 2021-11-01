class Solution {
public:
    int numTrees(int n) {
        int dp[20]{};
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            int s = 0;
            for (int j = 0; j <= i; ++j)
                s += dp[j] * dp[i-j];
            dp[i+1] = s;
        }
        return dp[n];
    }
};
