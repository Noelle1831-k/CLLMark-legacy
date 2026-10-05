	int dp[n+1];
	for(int i = 0; i < n+1; i++){
		dp[i] = n+1;
	}
	dp[0] = 0;
	for(int i = 1; i < n+1; i++){
		for(int j = 0; j < m; j++){
			if(s[j] <= i){
				dp[i] = min(dp[i], dp[i-s[j]]+1);
			}
		}
	}
	if(dp[n] > n){
		return -1;
	}
	else{
		return dp[n];
	}
}
<|endoftext|>