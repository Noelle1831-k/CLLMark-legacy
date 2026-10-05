int pic1[103][103],pic2[52][52],pic3[52][52];
int main(){
	int i,j,p,q,k,n,m,x,y,z;
	while(1){
		scanf("%d%d",&n,&m);
		if(n==0 && m==0)break;
		for(i=0;i<n;i++)for(j=0;j<n;j++)scanf("%d",&pic1[i][j]);
		for(i=0;i<m;i++)for(j=0;j<m;j++)scanf("%d",&pic2[i][j]);
		x=y=1000;
		for(k=0;k<4;k++){
			for(i=0;i<=n-m;i++)for(j=0;j<=n-m;j++){
				for(p=0;p<m;p++)for(q=0;q<m;q++){
					if(pic2[p][q]!=-1 && pic1[i+p][j+q]!=pic2[p][q])goto nex;
				}
				nex:
				if(p==m && q==m){
					z=0;
					while(pic2[0][z]==-1)z++;
					j+=z;
					if(i<y)y=i,x=j;
					else if(i==y && j<x)x=j;
					goto nex2;
				}
			}
			nex2:
			for(i=0;i<m;i++)for(j=0;j<m;j++)pic3[j][m-1-i]=pic2[i][j];
			memcpy(pic2,pic3,sizeof(pic3));
		}
		if(x==1000 && y==1000)printf("NA\n");
		else printf("%d %d\n",x+1,y+1);
	}
	return 0;
}