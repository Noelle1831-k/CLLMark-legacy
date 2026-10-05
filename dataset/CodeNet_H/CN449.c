long ship[100][100],dp[100][100];
int n;
long wfs(int a,int b){
  long graph[100],min;
  int f[100],i,s,c,next;
  memset(f,0,sizeof(f));
  graph[a]=0;
  s=0;
  c=a;
  while(s<n){
  	next=-1;
  	f[c]=2;
  	min=100000001;
  	if(c==b){
  		return graph[c];
  	}
  	for(i=0;i<n;i++){
  		if(ship[c][i]>0){
  			if(f[i]<2){
  				if(f[i]==0) graph[i]=ship[c][i];
  				else if(graph[i]>graph[c]+ship[c][i]){
  					graph[i]=graph[c]+ship[c][i];
  				}
  				if(min>graph[i]){
  				next=i;
  				min=graph[i];
  				}
  				f[i]=1;
  			}
  		}
  	}
  	s++;
  	if(next==-1) return -1;
  	c=next;
  }
  return -1;
}
int main(){
  int k,r,i,a,b;
  long p;
  while(1){
    scanf("%d %d",&n,&k);
    if(n==0) break;
    memset(ship,0,sizeof(ship));
    for(i=0;i<k;i++){
      scanf("%d",&r);
      if(r==0){
        scanf("%d %d",&a,&b);
        printf("%ld\n",wfs(a-1,b-1));
      }else{
        scanf("%d %d %ld",&a,&b,&p);
        if(ship[a-1][b-1]>p || ship[a-1][b-1]==0){
          ship[a-1][b-1]=p;
          ship[b-1][a-1]=p;
        }
      }
    }
  }
  return 0;
}