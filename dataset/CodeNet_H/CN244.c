int main(){
  int n,m,i,j,l,mi,mj,min,a,b,e;
  int c[2][110]={0};
  while(scanf("%d %d",&n,&m),n||m){
    int d[110][110]={0};
    while(m--){
      scanf("%d %d %d",&a,&b,&e);
      d[a][b]=d[b][a]=e;
    }
    for(i=2;i<=n;i++)c[0][i]=c[1][i]=100000000;
    c[0][1]=c[1][1]=0;
    mi=1;
    mj=0;
    int f[2][110]={0};
    for(i=0;i<n*2;i++){
      f[mj][mi]=1;
      for(j=1;j<=n;j++){
	if(f[mj][j]||d[mi][j]==0)continue;
	if(c[mj][j]>c[mj][mi]+d[mi][j])c[mj][j]=c[mj][mi]+d[mi][j];
	if(mj)continue;
	for(l=1;l<=n;l++){
	  if(d[j][l]==0||mi==l)continue;
	  if(c[1][l]>c[0][mi])c[1][l]=c[0][mi]; 
	}
      }
      min=2100000000;
      for(l=0;l<2;l++){
	for(j=1;j<=n;j++){
	  if(f[l][j])continue;
	  if(min>c[l][j])min=c[mj=l][mi=j];
	}
      }
    }
    printf("%d\n",c[1][n]);
  }
  return 0;
}