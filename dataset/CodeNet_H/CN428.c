int main()
{
    int n,m,i,count,j;
    int k[1000][100];
    int sum[100];
    while(scanf("%d%d",&n,&m),n+m){
 count=0;
      for(i=0;i<n;i++){
        for(j=0;j<m;j++){
          scanf("%d",&k[i][j]);
        }
      }
      for(i=0;i<100;i++) sum[i]=0;
      for(j=0;j<m;j++){
        for(i=0;i<n;i++){
          sum[j]+=k[i][j];
        }
      }
      for(j=n;j>=0;j--){
      for(i=0;i<m;i++){
          if(sum[i]==j){
printf("%d",i+1);
count++;
if(count<m)printf(" ");}}
      }
      printf("\n");
    }   
    return 0;
}