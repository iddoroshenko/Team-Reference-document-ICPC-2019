for (int i = 1; i <= n; i++) { 
        for (int w = 1; w <= s; w++) {
            dp[i][w] = dp[i-1][w];
            if (w >= a[i]) {
                dp[i][w] = max(dp[i][w], dp[i - 1][w - a[i]] + a[i]);
            }
        }
    }