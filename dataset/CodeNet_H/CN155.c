double d[1000][1000];
int f[1000][1000];
int main(){
  int n,i,j,k,s,t,b[1000],x[1000],y[1000];
  int M=100000000;
  while(scanf("%d",&n),n){
    for(i=0;i<n;i++){
      scanf("%d %d %d",&b[i],&x[i],&y[i]);
      for(j=i;j>-1;j--){
        d[b[i]][b[j]]=d[b[j]][b[i]]=hypot(x[j]-x[i],y[j]-y[i]);
	f[b[i]][b[j]]=b[i];
	f[b[j]][b[i]]=b[j];
	if(d[b[i]][b[j]]>50)d[b[i]][b[j]]=d[b[j]][b[i]]=M;
      }
    }
    for(k=0;k<n;k++){
      for(i=0;i<n;i++){
	for(j=0;j<n;j++){
	  if(d[b[i]][b[j]]>d[b[i]][b[k]]+d[b[k]][b[j]]){
	     d[b[i]][b[j]]=d[b[i]][b[k]]+d[b[k]][b[j]];
	     f[b[i]][b[j]]=f[b[k]][b[j]];
	  }
	}
      }
    }
    scanf("%d",&n);
    while(n--){
      scanf("%d %d",&s,&t);
      if(d[t][s]>M-1)printf("NA\n");
      else{
	for(;s-t;s=f[t][s])printf("%d ",s);
	printf("%d\n",t);
      }
    }
  }
  return 0;
}