if(n == 0) return 0; 
vector<long long> dp(n, 0);
long long max_prod = 0;
for(int i = 0; i < n; i++) {
    dp[i] = arr[i];
    for(int j = 0; j < i; j++) {
        if(arr[j] < arr[i]) {
            dp[i] = max(dp[i], dp[j] * arr[i]);
        }
    }
    max_prod = max(max_prod, dp[i]);
}
return max_prod;
}