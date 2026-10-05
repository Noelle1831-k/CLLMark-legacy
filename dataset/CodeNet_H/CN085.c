int main(void){
  int i;
  int m,n;
  int p[1000];
  int count,num;
  int last;
  int flag;
  while(1){
    scanf("%d %d",&n,&m);
    if(!n && !m)break;
    for(i=0;i<n;i++)p[i] = 1;
    count = 0;
    num = 0;
    while(1){
      if(p[num])count++;
      if(count == m){
	count = 0;
	p[num] = 0;
	last = num;
      }
      num++;
      if(num==n){
	num=0;
	flag=1;
	for(i=0;i<n;i++)if(p[i])flag=0;
	if(flag)break;
      }
    }
    printf("%d\n",last+1);
  }
  return 0;
}