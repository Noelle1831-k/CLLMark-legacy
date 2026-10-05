int t[5005][5];
int u[5005][5];
void init(){
  int i,j;
  for(i=0;i<5005;i++){
    for(j=0;j<5;j++){
      if(i==0)t[i][j]=1;
      else t[i][j]=0;
    }
  }
}
void Delete(){
  int i,j;
  for(i=0;i<5005;i++)
    for(j=0;j<5;j++)
      u[i][j]=t[i][j];
  init();
  int H=1,cnt;
  for(i=0;i<5005;i++){
    cnt=0;
    for(j=0;j<5;j++)cnt+=u[i][j];
    if(cnt==5)continue;
    for(j=0;j<5;j++)t[H][j]=u[i][j];
    H++;
  }
}
int check(int y,int x,int h,int w){
  int i,j,flg=0;
  for(i=y;i<y+h;i++)
    for(j=x;j<x+w;j++)
      if(t[i][j]==1)flg=1;
  if(flg==0)return 0;
  y++;
  for(i=y;i<y+h;i++)
    for(j=x;j<x+w;j++)
      t[i][j]=1;
  return 1;
}
void Put(int pos,int h,int w){
  int i;
  for(i=5000;i>=0;i--)
    if(check(i,pos,h,w)==1)break;
}
int main(){
  int i,j;
  int n,d,p,q,ans;
  while(1){
    scanf("%d",&n);
    if(n==0)break;
    init();
    for(i=0;i<n;i++){
      scanf("%d %d %d",&d,&p,&q);
      q--;
      if(d==1)Put(q,1,p);
      else Put(q,p,1);
      Delete();
    }
    ans=0;
    for(i=1;i<5005;i++)
      for(j=0;j<5;j++)
        ans+=t[i][j];
    printf("%d\n",ans);
  }
  return 0;
}