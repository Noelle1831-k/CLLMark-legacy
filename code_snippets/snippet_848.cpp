	int row=a.size();
	int col=a[0].size();
	vector<vector<int>> dp(row,vector<int>(col));
	for(int i=0;i<col;i++) dp[0][i]=a[0][i];
	for(int i=1;i<row;i++){
		for(int j=0;j<col;j++){
			if(j==0) dp[i][j]=dp[i-1][j]+a[i][j];
			else if(j==col-1) dp[i][j]=dp[i-1][j-1]+a[i][j];
			else dp[i][j]=min(dp[i-1][j]+a[i][j],dp[i-1][j-1]+a[i][j]);
		}
	}
	return *min_element(dp[row-1].begin(),dp[row-1].end());
}
<|endoftext|>