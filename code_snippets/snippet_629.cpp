	vector<vector<float>> dp(n, vector<float>(n, 0));
	vector<vector<float>> dp2(n, vector<float>(n, 0));
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i==0 && j==0){
				dp[i][j] = cost[i][j];
			}
			else if(i==0){
				dp[i][j] = dp[i][j-1] + cost[i][j];
			}
			else if(j==0){
				dp[i][j] = dp[i-1][j] + cost[i][j];
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + cost[i][j];
			}
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i==0 && j==0){
				dp2[i][j] = cost[i][j];
			}
			else if(i==0){
				dp2[i][j] = max(dp2[i][j-1], dp[i][j]) + cost[i][j];
			}
			else if(j==0){
				dp2[i][j] = max(dp2[i-1][j], dp[i][j]) + cost[i][j];
			}
			else{
				dp2[i][j] = max(max(dp2[i-1][j], dp2[i][j-1]), dp[i][j]) + cost[i][j];
			}
		}
	}
	return dp2[n-1][n-1];
}
<|endoftext|>