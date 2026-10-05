	if(n<0)
		return 0;
	if(n==0)
		return 0;
	if(n==1)
		return k;
	int dp[n+1];
	dp[0]=0;
	dp[1]=k;
	for(int i=2;i<=n;i++)
	{
		int count=0;
		for(int j=1;j<=k;j++)
		{
			count=count+(dp[i-1])%1000000007;
		}
		dp[i]=count;
	}
	return dp[n];
}
<|endoftext|>