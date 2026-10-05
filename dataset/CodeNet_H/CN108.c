#define NUM 13
#define SIZE 100
int main()
{
  int mat[NUM],count[SIZE];
  int ans,judge;
  int i,n;
  while(1)
    {
      scanf("%d",&n);
      if(n==0) break;
      for(i=0;i<n;i++)
	{
	  scanf("%d",&mat[i]);
	  count[mat[i]]++;
	}
      judge=n;
      for(ans=0;judge>0;ans++)
	{
	  judge=n;
	  for(i=0;i<n;i++)
	    {
	      if(mat[i]==count[mat[i]]) judge--;
	      mat[i]=count[mat[i]];
	    }
	  for(i=0;i<SIZE;i++) count[i]=0;
	  for(i=0;i<n;i++) count[mat[i]]++;
	}
      printf("%d\n",ans-1);
      for(i=0;i<n-1;i++) printf("%d ",mat[i]);
      printf("%d\n",mat[n-1]);
    }
  return 0;
}