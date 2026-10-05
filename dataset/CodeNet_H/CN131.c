int n;
int ph[10][10];     
int ph_org[10][10];
int r[10][10];
void inv(int i,int j)
{
	    ph[i][j] ^=1;
	    if(i>0)
	      ph[i-1][j] ^=1;
	    if(i<9)
	      ph[i+1][j] ^=1;
	    if(j>0)
	      ph[i][j-1] ^=1;
	    if(j<9)
	      ph[i][j+1] ^=1;
}
void find1(int *y,int *x)
{
  int i,j;
  for(i=0;i<10;i++)
    for(j=0;j<10;j++)
      if(ph[i][j])
	{
	  *y=i;*x=j;
	  return;
	    }
  *y=*x=-1;
}
void output()
{
  int i,j;
  for(i=0;i<10;i++)
    {
      for(j=0;j<9;j++)
	printf("%d ",r[i][j]);
      printf("%d",r[i][10]);
      printf("\n");
    }
}
void display()
{
  int i,j;
  for(i=0;i<10;i++)
    {
      for(j=0;j<10;j++)
	printf("%d ",ph[i][j]);
      printf("\n");
    }
}
int is_all_off()
{
  int i,j;
  for(i=0;i<10;i++)
    for(j=0;j<10;j++)
      if(ph[i][j])
	return(0);
  return(-1);
}
void solve()
{
  int y,x,i,pos,bit;
  for(i=0;i<1024;i++)
    {
      memset(r,0,sizeof(int)*10*10);
      memcpy(ph,ph_org,sizeof(int)*10*10);
      for(pos=0;pos<10;pos++)
	{
	  bit = 1<<pos;
	  if(bit & i)
	    {
	      r[0][pos] ^= 1;
	      inv(0,pos);
	    }
	}
      while(find1(&y,&x),y!=-1 && y < 9)
	{
	  r[y+1][x] ^= 1;
	  inv(y+1,x);
	  if(is_all_off())
	    return;
	}
    }
}
main()
{
  int i,j,k;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      for(j=0;j<10;j++)
	for(k=0;k<10;k++)
	  scanf("%d",&ph_org[j][k]);
      solve();
      output();
    }
  return(0);
}