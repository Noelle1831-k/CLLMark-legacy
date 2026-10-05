int main(void){
	int n,m,a,b,x,i,j,path[10000][3],pot[110];
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++)pot[i]=1;
		scanf("%d",&m);
		for(i=0;i<m;i++){
			scanf("%d,%d,%d",&a,&b,&x);
			for(j=i;j>0;j--){
				if(path[j-1][2]>x){
					path[j][2]=path[j-1][2];
					path[j][1]=path[j-1][1];
					path[j][0]=path[j-1][0];
				}else break;
			}
			path[j][2]=x;
			path[j][1]=b;
			path[j][0]=a;
		}
		x=0;
		for(i=0;i<m && n>0;i++){
			a=path[i][0];
			b=path[i][1];
			if(pot[a]==1 || pot[b]==1){
				n-=pot[a]+pot[b];
				pot[a]=0;pot[b]=0;
				x+=path[i][2]/100-1;
			}
		}
		printf("%d\n",x);
	}
	return 0;
}