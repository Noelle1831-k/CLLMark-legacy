#define MAX 10000005
p[MAX],four[1000],j,f;
main(i)
{
  for(i=2;i<MAX;i++)
    if(!p[i])
      for(j=i*2;j<MAX;j+=i)
	p[j]=1;
  for(i=3;i<MAX-7;i+=2)
    if(!p[i]&&!p[i+2]&&!p[i+6]&&!p[i+8])
      four[f++]=i+8;
  for(four[f]=MAX;scanf("%d",&j),j;printf("%d\n",four[i-1]))
      for(i=0 ;four[i]<=j; i++);
}