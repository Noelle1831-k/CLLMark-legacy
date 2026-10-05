#define R 10000
int dp[500][11][500][3][2];
int func(int v[],int vn,int m){
	int i,j,k,l,w,x,y,z,ans;
	memset(dp,0,sizeof(dp));
	ans=0;
	if(vn==1){
		for(i=1;i<=v[0];i++)if(i%m==0)ans++;
		return ans;
	}
	for(i=0;i<=v[0];i++){
		if(i==v[0])z=1;
		else z=0;
		if(i==0){
			dp[0][10][0][2][0]=1;
		}
		else{
			dp[0][i][i%m][0][z]++;
			dp[0][i][i%m][1][z]++;
		}
	}
	for(i=1;i<vn;i++){
		for(l=0;l<m;l++){
			for(j=0;j<10;j++){
				if(j==0){
					dp[i][10][0][2][0]=dp[(i-1)][10][0][2][0];
				}
				if(j!=v[i-1]){
					if(v[i-1]<j)x=1,y=0;
					else if(v[i-1]>j)x=0,y=1;
					if(j==v[i]){
						dp[i][j][(l*10+j)%m][x][1]+=dp[(i-1)][v[i-1]][l][y][1];
						dp[i][j][(l*10+j)%m][x][1]%=R;
					}
					else if(j<v[i]){
						dp[i][j][(l*10+j)%m][x][0]+=dp[(i-1)][v[i-1]][l][y][1];
						dp[i][j][(l*10+j)%m][x][0]%=R;
					}
				}
				for(k=0;k<10;k++){
					if(j==k)continue;
					else if(k<j)x=1,y=0;
					else x=0,y=1;
					if(k==0){
						dp[i][j][(l*10+j)%m][2][0]+=dp[(i-1)][10][l][2][0];
						dp[i][j][(l*10+j)%m][2][0]%=R;
					}
					dp[i][j][(l*10+j)%m][x][0]+=dp[(i-1)][k][l][y][0]+dp[(i-1)][k][l][2][0];
					dp[i][j][(l*10+j)%m][x][0]%=R;
				}
			}
		}
	}
	for(i=0;i<10;i++){
		for(j=0;j<2;j++){
			ans+=dp[(vn-1)][i][0][2][j]+
			     dp[(vn-1)][i][0][1][j]+
			     dp[(vn-1)][i][0][0][j];
			ans%=R;
		}
	}
	return ans;
}
int main(){
	int i,j,k,l,m,x[510],y[510],z,xn,yn,ans,c;
	char a[510],b[510];
	scanf("%s%s",a,b);
	scanf("%d",&m);
	xn=strlen(a);
	yn=strlen(b);
	for(i=0;i<xn;i++)x[i]=a[i]-'0';
	for(i=0;i<yn;i++)y[i]=b[i]-'0';
	c=1;
	for(i=xn-1;i>=0;i--){
		x[i]=x[i]-c;
		c=0;
		if(x[i]<0){
			c=1;
			x[i]+=10;
		}
	}
	ans=(10000+func(y,yn,m)-func(x,xn,m))%R;
	printf("%d\n",ans);
	return 0;
}