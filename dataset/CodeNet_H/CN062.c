#define N 10
int main()
{
  int i,j;
  char str[N+1];
  while (scanf("%s",str)!=EOF){
    for (i=0;i<N;i++){
      for (j=0;j<N-i-1;j++){
        str[j]=((str[j]-'0')+(str[j+1]-'0'))%10+'0';
      }
    }
    printf("%d\n",str[0]-'0');
  }
  return 0;
}