int max(int,int);
int main(void)
{
	int i,j,N,T,S,A[3000],B[3000],dp[2][3001];
    scanf("%d%d%d",&N,&T,&S);
	for(i=0;i<=N-1;i++) scanf("%d%d",&A[i],&B[i]);
	for(i=0;i<=N;i++)
	{
	    for(j=0;j<=T;j++)
		{
			dp[0][j]=0;
		}
	}
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=T;j++)
		{
				if(j<=S)
				{
			        if(B[i-1]<=j) dp[1][j]=max(dp[0][j],dp[0][j-B[i-1]]+A[i-1]);
			        else dp[1][j]=dp[0][j];
				}
				else
				{
					if(B[i-1]<=j && j-B[i-1]>=S)  dp[1][j]=max(dp[0][j],dp[0][j-B[i-1]]+A[i-1]);
					else dp[1][j]=max(dp[0][j],dp[1][j-1]);
				}
		}
		for(j=0;j<=T;j++) dp[0][j]=dp[1][j];
	}
	printf("%d\n",dp[1][T]);
	return 0;
}
int max(int a, int b)
{
	if(a>b) return a;
	else return b;
}