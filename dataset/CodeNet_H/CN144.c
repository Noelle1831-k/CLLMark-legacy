int Q[101],head,tail,n,t[101][101],d[101],k[100];
void enqueue(int x){
  Q[tail++]=x;
}
int dequeue(){
  return Q[head++];
}
void bfs(int s){
  int u,v,w;
  for(v=0;v<=n;v++) d[v]=10000;
  d[s]=0;
  enqueue(s);
  while(head!=tail){
    u=dequeue();
    for(v=0;v<=n;v++){
	if(t[u][v]==1&&d[v]==10000){
	  d[v]=d[u]+1;
	  enqueue(v);
      }
    }
  }
}
main(){
  int p,i,j,s,dd,TTL,r[100],m,tt[101][101];
  scanf("%d",&n);
  head=0;
  tail=0;
  for(i=0;i<n;i++){
    scanf("%d%d",&r[i],&k[i]);
    for(j=0;j<k[i];j++){
      tt[r[i]][j]=10000;
      scanf("%d",&tt[r[i]][j]);
    }
  }
  for(i=0;i<=n;i++){
    for(j=0;j<=n;j++){
      t[i][j]=0;
    }
  }
  for(i=0;i<=n;i++){
    for(j=0;j<k[i];j++){
      for(m=0;m<=n;m++){
	if(tt[r[i]][j]==m) t[r[i]][m]=1;
      }
    }
  }
  scanf("%d",&p);
  for(i=0;i<p;i++){
    scanf("%d%d%d",&s,&dd,&TTL);
    bfs(s);
    if(d[dd]<TTL) printf("%d\n",d[dd]+1);
    else printf("NA\n");
  }
  return 0;
}