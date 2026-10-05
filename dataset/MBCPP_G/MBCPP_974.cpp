int n = a.size();
vector<int> dp = a[n-1];
for(int i = n-2; i >= 0; --i) {
    for(int j = 0; j < a[i].size(); ++j) {
        dp[j] = a[i][j] + min(dp[j], dp[j+1]);
    }
}
return dp[0];
}