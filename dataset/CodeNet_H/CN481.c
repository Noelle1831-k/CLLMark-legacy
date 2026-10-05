int H,W,N,F[1005][1005],C[10][2],S[10000005][3],i,j,mv[5]={1,0,-1,0,1},R;
char M[1005][1005],t;
int bfs(int sx,int sy,int gx,int gy)
{
	int i,j,p=1,x,y,c;
	memset(F,0,sizeof(F));
	S[0][0]=sx;S[0][1]=sy;S[0][2]=0;
	for(i=0;i<p;i++)
	{
		x=S[i][0];y=S[i][1];c=S[i][2];
		F[y][x]=1;
		if(x==gx&&y==gy)
			return c;
		for(j=0;j<4;j++)
		{
			if(M[y+mv[j]][x+mv[j+1]]=='.'&&F[y+mv[j]][x+mv[j+1]]==0)
			{
				S[p][0]=x+mv[j+1],S[p][1]=y+mv[j],S[p][2]=c+1;
				p++;
			}
		}
	}
	return -1;
}
int main()
{
	scanf("%d%d%d\n",&H,&W,&N);
	for(i=1;i<=H;i++)
		for(j=1;j<=W+1;j++)
		{
			t=getchar();
			if(t>10&&t!='.'&&t!='X')
			{
				if(t=='S')
					C[0][0]=i,C[0][1]=j;
				else
					C[t-'0'][0]=i,C[t-'0'][1]=j;
				M[i][j]='.';
			}
			else
				M[i][j]=t;
		}
	for(i=R=0;i<N;i++)
		R+=bfs(C[i][1],C[i][0],C[i+1][1],C[i+1][0]);
	printf("%d\n",R);
	return 0;
}