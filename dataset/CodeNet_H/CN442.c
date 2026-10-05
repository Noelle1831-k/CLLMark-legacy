int N,M,i,j,G[5000][5000],R[5000],f[5000],p,a,b,r2=0;
void dfs(int d)
{
	int i;
	for(i=0;i<N;i++)
	{
		if(f[i])continue;
		if(G[d][i])
		{
			dfs(i);
			if(!f[i])
			{
				R[p++]=i;
				f[i]=1;
			}
		}
	}
	return;
}
int main()
{
	scanf("%d%d",&N,&M);
	for(i=0;i<M;i++)
	{
		scanf("%d%d",&a,&b);
		G[a-1][b-1]=1;
	}
	for(j=0;j<N;j++)
	{
		for(i=0;i<N;i++)
			if(G[i][j]==1)break;
		if(i==N)
		{
			dfs(j);
			R[p++]=j;
		}
	}
	for(i=N-1;i>0;i--)
		if(G[R[i]][R[i-1]]==0)
			r2=1;
	for(int i=N-1;i>=0;i--)
		printf("%d\n",R[i]+1);
	printf("%d\n",r2);
	return 0;
}