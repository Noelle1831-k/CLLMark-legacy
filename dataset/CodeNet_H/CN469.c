int k;
int n;
int co;
char a[11][3];
int cost[11]={0};
char at[101]="\0";
int anst[100000001];
void solve(int p){
  int i;
  char temp[11];
  if(k<=p){
    if(anst[atoi(at)]!=1){
      anst[atoi(at)]=1;
      co++;
    }
    return;
  }
  for(i=0;i<n;i++){
    if(cost[i]!=1){
      strcpy(temp,at);
      strcat(at,a[i]);
      cost[i]=1;
      solve(p+1);
      cost[i]=0;
      strcpy(at,temp);
    }
  }
  return;
}
main(){
  int i,j;
  while(1){
    scanf("%d",&n);
    scanf("%d",&k);
    if(n==0 && k==0) break;
    memset(anst,0,sizeof(anst));
    co=0;
    for(i=0;i<n;i++)
      scanf("%s",a[i]);
    solve(0);
    printf("%d\n",co);
  }
  return 0;
}