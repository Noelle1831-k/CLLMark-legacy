int N,M,t[101],i,j,r;
typedef struct e{int f,t,c;}e;
e B[101];
int cmp(const void *a,const void *b){e x=*(e*)a,y=*(e*)b;return x.c-y.c;}
void in(n){for(;n--;)t[n]=n;}
int p(n){return t[n]==n?n:p(t[n]);}
void u(a,b){t[p(a)]=p(b);}
int s(a,b){return p(a)==p(b);}
main()
{
	for(;scanf("%d%d",&N,&M)&&N;)
	{
		in(N);
		for(i=r=0;i<M;i++)
			scanf("%d%d%d",&B[i].f,&B[i].t,&B[i].c);
		qsort(B,M,sizeof(e),cmp);
		for(i=0;i<M;i++)
			if(!s(B[i].f,B[i].t))
			{
				u(B[i].f,B[i].t);
				r+=B[i].c;
			}
		printf("%d\n",r);
	}
	return 0;
}