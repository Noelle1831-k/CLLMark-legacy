#define max(x,y) (((x)>(y))?(x):(y))
int keiro[199][100];
int length[199][100];
int n ;
main()
{
  int i,j;
  int lc=0,fc=0;
  char buf[101];
  char *p,*q;
  int ff;
  while(NULL!=fgets(buf,100,stdin))
    {
      fc=0;
      p=strtok(buf,",");
    if(!p)
	continue;
      keiro[lc][fc]=(int)strtol(p,&q,10);
      while(p=strtok(NULL,","))
	{
	  fc++;
	  keiro[lc][fc]=(int)strtol(p,&q,10);
	}
	lc++;
    }
#ifdef DEBUG  
  printf("%d\n",lc);
#endif  
  n=(lc+1)/2;
  length[0][0]=keiro[0][0];
  for(i=1;i<n;i++)
    for(j=0;j<=i;j++)
      if(j==0 )
	length[i][j]=length[i-1][j]+keiro[i][j];
      else if (j==i)
	length[i][j]=length[i-1][j-1]+keiro[i][j];
      else 
	length[i][j]=max(length[i-1][j-1],length[i-1][j])+keiro[i][j];
  for(i=n;i<n*2;i++)
    for(j=0;j<i;j++)
      length[i][j]=max(length[i-1][j],length[i-1][j+1])+keiro[i][j];
#ifdef DEBUG  
  for(i=0;i<n;i++)
    {
      for(j=0;j<=i;j++)
	printf("%2d:",keiro[i][j]);
      printf("\n");
    }
  for(i=n;i<2*n-1;i++)
    {
      for(j=0;j<2*n-i-1;j++)
	printf("%2d:",keiro[i][j]);
      printf("\n");
    }
  for(i=0;i<n;i++)
    {
      for(j=0;j<=i;j++)
	printf("%2d:",length[i][j]);
      printf("\n");
    }
  for(i=n;i<2*n-1;i++)
    {
      for(j=0;j<2*n-i-1;j++)
	printf("%2d:",length[i][j]);
      printf("\n");
    }
#endif  
  printf("%d\n",length[2*n-1][0]);
  return(0);
}