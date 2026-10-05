int stack[100];
int used[100];
int sp;
int main()
{
  int l,i,c,er;
  scanf("%d",&l);
  sp=0;er=0;
  for(i=1;i<=l;i++)
  { scanf("%d",&c);
    if(er==0)
    { if(c>0)
      {  if(used[c]>0)
	  er=i;
        else
        { stack[sp]=c;
	  used[c]=1;
	  sp++;
        }
      }
      if (c<0)
      { if(stack[sp-1]==-c)
        { sp--;
	  used[-c]=0;
        }
        else
	  er=i;
      }
   }
  }   
  if(er>0)
    printf("%d\n",er);
  else
    printf("OK\n");
  return 0;
}
