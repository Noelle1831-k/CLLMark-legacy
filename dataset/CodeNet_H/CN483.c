#define MAX 100
int main(void)
{  
  int i, j, k, l, m, n;
  int aa, bb, cc, dd;
  int jj, ii, oo;
  int p, q;
  char t;
  char temp[MAX];
  char a[MAX][MAX];
  int J[MAX][MAX];
  scanf("%d %d",&i,&j);
  scanf("%d",&k);
  for(l=0;l<i;l++)
    {
      scanf("%s",temp);
      for(m=0;m<j;m++)
	{
	  a[l][m] = temp[m];
	}
    }
  for(q=0;q<k;q++)
    {
      scanf("%d %d %d %d",&aa,&bb,&cc,&dd);
      aa = aa-1;
      bb = bb-1;
      cc = cc-1;
      dd = dd-1;
      for(p=0;p<3;p++)
	{
	  if(p==0)
	    {
	      n = 1;
	      for(l=0;l<j;l++)
		{
		  if(a[0][l]=='J')
		    {
		      J[0][l] = n;
		      n++;
		    }
		  else
		    {
		      if(l-1<0)
			{
			  J[0][l] = 0;
			}
		      else
			{
			  J[0][l] = J[0][l-1];
			}
		    }
		}
	      for(l=1;l<i;l++)
		{
		  for(m=0;m<j;m++)
		    {
		      if(m==0)
			{
			  J[l][0] = J[l-1][0];
			  if(a[l][0]=='J')
			    {
			      J[l][0] = J[l][0] + 1;
			    }
			}
		      else
			{
			  J[l][m] = J[l-1][m] + J[l][m-1] - J[l-1][m-1];
			  if(a[l][m]=='J')
			    {
			      J[l][m] = J[l][m] + 1;
			    }
			}
		    }
		}
	      if(aa==0)
		{
		  if(bb==0)
		    {
		      jj= J[cc][dd];
		    }
		  else
		    {
		      jj = J[cc][dd] - J[cc][bb-1];
		    }
		}
	      else{
		jj = J[cc][dd] - J[aa-1][dd] - J[cc][bb-1] + J[aa-1][bb-1];
	      }
	    }
	  else if(p==1)
	    {
	      n = 1;
	      for(l=0;l<j;l++)
		{
		  if(a[0][l]=='O')
		    {
		      J[0][l] = n;
		      n++;
		    }
		  else
		    {
		      if(l-1<0)
			{
			  J[0][l] = 0;
			}
		      else
			{
			  J[0][l] = J[0][l-1];
			}
		    }
		}
	      for(l=1;l<i;l++)
		{
		  for(m=0;m<j;m++)
		    {
		      if(m==0)
			{
			  J[l][0] = J[l-1][0];
			  if(a[l][0]=='O')
			    {
			      J[l][0] = J[l][0] + 1;
			    }
			}
		      else
			{
			  J[l][m] = J[l-1][m] + J[l][m-1] - J[l-1][m-1];
			  if(a[l][m]=='O')
			    {
			      J[l][m] = J[l][m] + 1;
			    }
			}
		    }
		}
	      if(aa==0)
		{
		  if(bb==0)
		    {
		      oo= J[cc][dd];
		    }
		  else
		    {
		      oo = J[cc][dd] - J[cc][bb-1];
		    }
		}
	      else{
		oo = J[cc][dd] - J[aa-1][dd] - J[cc][bb-1] + J[aa-1][bb-1];
	      }
	    }
	  else if(p==2)
	    {
	      n = 1;
	      for(l=0;l<j;l++)
		{
		  if(a[0][l]=='I')
		    {
		      J[0][l] = n;
		      n++;
		    }
		  else
		    {
		      if(l-1<0)
			{
			  J[0][l] = 0;
			}
		      else
			{
			  J[0][l] = J[0][l-1];
			}
		    }
		}
	      for(l=1;l<i;l++)
		{
		  for(m=0;m<j;m++)
		    {
		      if(m==0)
			{
			  J[l][0] = J[l-1][0];
			  if(a[l][0]=='I')
			    {
			      J[l][0] = J[l][0] + 1;
			    }
			}
		      else
			{
			  J[l][m] = J[l-1][m] + J[l][m-1] - J[l-1][m-1];
			  if(a[l][m]=='I')
			    {
			      J[l][m] = J[l][m] + 1;
			    }
			}
		    }
		}
	      if(aa==0)
		{
		  if(bb==0)
		    {
		      ii = J[cc][dd];
		    }
		  else
		    {
		      ii = J[cc][dd] - J[cc][bb-1];
		    }
		}
	      else{
		ii = J[cc][dd] - J[aa-1][dd] - J[cc][bb-1] + J[aa-1][bb-1];
	      }
	    }
	}
      printf("%d %d %d\n",jj,oo,ii);
    }
  return 0;
}