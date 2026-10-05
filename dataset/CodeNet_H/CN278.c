#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
int N,Q;
int s[1000000],ssort[1000000],diff[1000000];
char leader[1000000];
int highest_leader;
int n_of_leaders;
int compare(const void *a, const void *b)
{
  if( *(int *)a > *(int *)b)
    return(-1);
  if( *(int *)a < *(int *)b)
    return(1);
  if( *(int *)a == *(int *)b)
    return(0);
}
int compare_r(const void *a, const void *b)
{
  if( *(int *)a > *(int *)b)
    return(1);
  if( *(int *)a < *(int *)b)
    return(-1);
  if( *(int *)a == *(int *)b)
    return(0);
}
search(int ssort[],int score)
{
  int h,l,av,ret;
  h=N-1,l=0;
  while(1)
    {
      av=(h+l)/2;
      if(ssort[av]==score)
	{
	  ret=av;
	  break;
	}
      else if(ssort[av]>score)
	l = av;
      else
	h = av;
    }
 NEXT:
  while(ret>0 && ssort[ret-1]==score)
    ret--;
  return(ret);
}
dump(int ssort[],char leader[])
{
  int i;
  for(i=0;i<N;i++)
    printf("%d %c|",ssort[i],leader[i]?'*':'-');
  printf("[high reader score=%d] \n",ssort[highest_leader]);
}
dump_diff(int diff[],int cnt)
{
  int i;
  for(i=0;i<cnt;i++)
    printf("%d |",diff[i]);
  printf("\n");
}
add_leader(int arg)
{
  int score,pos;
  score = s[arg];
  pos=search(ssort,score);
  n_of_leaders++;
  leader[pos]=1;
  if(pos < highest_leader)
    highest_leader=pos;
}
next_highest_leader(int from)
{
  int i;
  for(i=from+1;i<N;i++)
    if(leader[i])
      return(i);
  return(N);
}
remove_leader(int arg)
{
  int score,pos;
  score = s[arg];
  pos=search(ssort,score);
  while(ssort[pos+1]==score && leader[pos+1]==1)
    pos++;
  n_of_leaders--;
  leader[pos]=0;
  if(highest_leader==pos)
    highest_leader=next_highest_leader(highest_leader);
}
int check_not_join(int r)
{
  int higher,cnt,i,l_sc;
  if(r==N)
    return(0);
  if(n_of_leaders==0)
      return(-1);
  higher=highest_leader;
  if(higher > r)
    return(-1);
  for(i=highest_leader,l_sc=ssort[highest_leader],cnt=0;i<N;i++)
    {
      if(!leader[i])
	diff[cnt++]=l_sc - ssort[i];
      else
	l_sc=ssort[i];
    }
#ifdef DEBUG
  dump_diff(diff,cnt);
#endif
  qsort(diff,cnt,sizeof(int),compare_r);
  return(diff[cnt-(r-higher)-1]);
}
void execute_query(char q[],int arg)
{
  int ret;
  if(0==strcmp("ADD",q))
    {
      add_leader(arg-1);
#ifdef DEBUG
      dump(ssort,leader);
#endif
    }
  if(0==strcmp("REMOVE",q))
    {
      remove_leader(arg-1);
#ifdef DEBUG
      dump(ssort,leader);
#endif
    }	    
  if(0==strcmp("CHECK",q))
    {
      ret=check_not_join(arg);
      if(ret==-1)
	printf("NA\n");
      else
	printf("%d\n",ret);
    }
}
main()
{
  int i,ret,num;
  char query[7];
  scanf("%d %d",&N,&Q);
  for(i=0;i<N;i++)
      scanf("%d ",&(s[i]));
  memcpy(ssort,s,sizeof(s));
  qsort (ssort,N,sizeof(int),compare);
  highest_leader=N;
  n_of_leaders=0;
  for(i=0;i<Q;i++)
    {
      scanf("%s %d",&query[0],&num);
      execute_query(query,num);
    }
  return(0);
}