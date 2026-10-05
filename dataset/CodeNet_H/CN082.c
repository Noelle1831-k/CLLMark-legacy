#define min(x,y) (((x)<(y))?(x):(y))
int kyaku[8];
int merry[8]={1,4,1,4,1,2,1,2};
int order[8]={5,1,6,2,8,4,7,3};
char buf[40];
main()
{
  int sum;
  int maxi,maxsum;
  int i,j;
  while(NULL!=fgets(buf,sizeof(buf),stdin))
    {
      for(i=0;i<8;i++)
	sscanf(buf+2*i,"%d ",&kyaku[i]);
      maxsum=-1;
      maxi  =-1;
      for(i=0;i<8;i++)
	{
	  sum = 0;
	  for(j=0;j<8;j++)
	    {
	      sum += min(kyaku[j],merry[(i+j)%8]);
	    }
	  if(sum > maxsum ||( sum==maxsum && order[i]>order[maxi]))
	    {
	      maxi=i;
	      maxsum=sum;
	    }
	}
      for(i=0;i<8;i++)
	printf("%d ",merry[(i+maxi) % 8]);
      printf("\n");
    }
return(0);
}