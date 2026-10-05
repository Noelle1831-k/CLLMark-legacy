int main(){
  int n,m,max,s,i;
  int d[100001];
  while(1){
    scanf("%d %d",&n,&m);
    if(!(n||m))break;
    s=0;
    for(i=0;i<n;i++){
      scanf("%d",&d[i]);
      if(i<m)s+=d[i];
    }
    max=s;
    for(i=m;i<n;i++){
      s-=d[i-m];
      s+=d[i];
      if(max<s)max=s;
    }
    printf("%d\n",max);
  }
  return 0;
}