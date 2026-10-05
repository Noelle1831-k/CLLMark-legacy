int d[3000][3000]={0};
int l[3000];
int main(){
  int n,m,k,min,mi,a,b,c,max,i,j;
  double D;
  scanf("%d %d %d",&n,&m,&k);
  for(i=0;i<n;i++)l[i]=2100000000;
  while(m--){
    scanf("%d %d %d",&a,&b,&c);
    a--;
    b--;
    d[a][b]=d[b][a]=c;
  }
  while(k--){
    char f[3000]={0};
    scanf("%d",&a);
    a--;
    l[mi=a]=0;
    for(i=0;i<n;i++){
      f[mi]=2;
      for(j=0;j<n;j++){
	if(d[mi][j]==0||f[j])continue;
	if(l[j]>l[mi]+d[mi][j]){
	  l[j]=l[mi]+d[mi][j];
	  f[j]=1;
	}
      }
      min=2100000000;
      for(j=0;j<n;j++){
	if(f[j]!=1)continue;
	if(min>l[j])min=l[mi=j];
      }
      if(min==2100000000)break;
    }
  }
  for(i=max=0;i<n;i++){
    for(j=0;j<n;j++){
      if(i==j)continue;
      D=(d[i][j]+l[i]+l[j])/2.0+0.5;
      if(max<D)max=D;
    }
  }
  printf("%d\n",max);
  return 0;
}
