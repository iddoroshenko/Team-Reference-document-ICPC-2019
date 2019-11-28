for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (v[j] < v[i])
                dp[i] = max(dp[i], 1 + dp[j]);
    }
 
    int max = 0;
    for (int i = 0; i < n; i++)
        if (dp[i] > max) max = dp[i];