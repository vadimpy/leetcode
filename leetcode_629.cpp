class Solution {

public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(1001, vector<int>(1001));
        for (int i = 1; i <= n; ++i)
            for(int j = 0; j <= min(k,i*(i-1)/2); ++j)
            {
                if (j == 0)
                    dp[i][0] = 1;
                else if (j == 1)
                    dp[i][1] = i - 1;
                else
                {
                    uint64_t val = 0;
                    int index = 0;
                    for(int index = 0; (index <= i - 1) && (j - index >= 0); ++index)
                        val += dp[i - 1][j - index];
                    dp[i][j] = val % (int(1e9) + 7);

                }

            }
        return dp[n][k];
    }
};
