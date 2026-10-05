int n,m,total;
struct doll
{
  int h;
  int r;
} dolls[200];
int compare_doll(const void *a, const void *b)
{
  if (((struct doll *)b)->h > ((struct doll *)a)->h)
    return(-1);
  if (((struct doll *)b)->h < ((struct doll *)a)->h)
    return(1);
  if (((struct doll *)b)->r > ((struct doll *)a)->r)
    return(-1);
  if (((struct doll *)b)->r < ((struct doll *)a)->r)
    return(1);
  return(0);
}
int solve(int hh,int rr,int index)
{
  if(index==total)
    return(0);
  if(dolls[index].h > hh && dolls[index].r > rr)
    return(1+solve(dolls[index].h, dolls[index].r ,index+1));
  else
    return(solve(hh,rr,index+1));
}
void dump()
{
  int i;
  for(i=0;i<total;i++)
    printf("%d %d\n",dolls[i].h,dolls[i].r);
}
main()
{
  int i;
  while(scanf("%d",&n) && n)
    {
      for(i=0;i<n;i++)
	scanf("%d %d",&dolls[i].r,&dolls[i].h);
      scanf("%d",&m);
      for(i=0;i<m;i++)
	scanf("%d %d",&dolls[i+n].r,&dolls[i+n].h);
      total=n+m;
      qsort(dolls,total,sizeof(struct doll),compare_doll);
      int ret=solve(0,0,0);
      printf("%d\n",ret);
    }
  return(0);
}