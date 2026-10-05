int n;
int c[100][2];
int chain(int e,int l,int done[]){ 
  int i;
  int prol,nowl;
  prol = nowl = l;
  for(i=0;i<n;i++){
    if(c[i][0]==e && done[c[i][1]-1]==0){
      prol = chain(c[i][1],nowl+1,done);
      done[c[i][1]-1] = 1;
    }
    if(c[i][1]==e && done[c[i][0]-1]==0){
      prol = chain(c[i][0],nowl+1,done);
      done[c[i][0]-1] = 1;
    }
    if(prol>l){
      l = prol;
    }
  }
  return l;
}
main(){
  int i;
  int done[100];
  int ans,preans;
  while(scanf("%d",&n)!=0){
    for(i=0;i<n;i++){
      scanf("%d %d",&c[i][0],&c[i][1]);
    }
    for(i=0;i<100;i++){
      done[i]=0;
    }
    ans = 0;
    for(i=1;i<=100;i++){
      preans = chain(i,0,done);
      if(preans>ans){
        ans = preans;
      }
    }
    printf("%d\n",ans);
  }
}