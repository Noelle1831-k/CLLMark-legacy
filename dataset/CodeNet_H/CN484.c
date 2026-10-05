int dp[11][2001];
int main(void)
{
	int i,j,k,l,n,m,hon[11][2001],c,g,sum,temp,max,flg,jan;
	scanf("%d %d",&n,&m);
	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++){
			hon[i][j]=0;
			dp[i][j]=-1;
		}
	}
	jan=0;
	for(i=1;i<=n;i++){
		scanf("%d %d",&c,&g);
		hon[g][i]=c;
		if(jan<g) jan=g;
	}
	for(i=0;i<=jan;i++){
		for(j=0;j<=m;j++) printf("%d ",hon[i][j]);
		printf("\n");
	}
	for(i=1;i<=jan;i++){
		for(j=1;j<n;j++){
			for(k=j+1;k<=n;k++){
				if(hon[i][j]<hon[i][k]){
					temp=hon[i][j];
					hon[i][j]=hon[i][k];
					hon[i][k]=temp;
				}
			}
		}
	}
	dp[0][0]=0;
	for(i=0;i<jan;i++){
		for(j=0;j<=m;j++){
			if(dp[i][j]!=-1){
				for(k=0;k<=m;k++){
					if(j+k<=m){
						sum=0;
						flg=1;
						if(k<2){
							for(l=1;l<=k;l++){
								if(hon[i+1][l]==0){
									flg=0;
									break;
								}
								sum+=hon[i+1][l];
							}
							if(dp[i+1][j+k]<dp[i][j]+sum&&flg!=0){
								if(dp[i+1][j+k]==-1)dp[i+1][j+k]=0;
								dp[i+1][j+k]=dp[i][j]+sum;
							}
						}
						else {
							for(l=1;l<=k;l++){
								if(hon[i+1][l]==0){ 
									flg=0;
									break;
								}
								sum+=hon[i+1][l]+(k-1);
							}
							if(dp[i+1][j+k]<dp[i][j]+sum&&flg!=0){
								if(dp[i+1][j+k]==-1)dp[i+1][j+k]=0;
								dp[i+1][j+k]=dp[i][j]+sum;
							}
						}
					}
				}
			}
		}
	}
	for(i=0;i<=jan;i++){
		for(j=0;j<=m;j++) printf("%d ",dp[i][j]);
		printf("\n");
	}
	max=-1;
	for(i=0;i<=m;i++){
		if(max<dp[m-1][i]) max=dp[m-1][i];
	}
	printf("%d\n",max);
	return 0;
}