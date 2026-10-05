int N,s,i,j,mv[4][2]={{0,-1},{1,0},{0,1},{-1,0}},x,y,S,r;
char M[105][105],E[3][30]={"#","##\n#","###\n# #\n# #"};
int c(int n){return 0<=n-1&&n+1<100;}
int c2(int x,int y)
{
	int i,m[5]={1,0,-1,0,1},c=0,c2=0;
	for(i=0;i<4;i++)
	{
		if(M[y+m[i]][x+m[i+1]]=='#')c++;
		if((mv[i][1]&&M[y+(mv[i][1]*2)][x]=='#')||(mv[i][0]&&M[y][x+(mv[i][0]*2)]=='#'))c2++;
	}
	return c>1?1:c2==4?2:0;
}
int main()
{
	for(scanf("%d",&N);N--;N>0?puts("\n"):0)
	{
		memset(M,0,sizeof(M));
		scanf("%d",&S);s=S;
		if(s<4)printf("%s",E[s-1]);
		else
		{
			for(i=0,x=0,y=s-1;;i=(i+1)%4)
			{
				for(;0<=y+mv[i][1]&&y+mv[i][1]<s&&0<=x+mv[i][0]&&x+mv[i][0]<s;y+=mv[i][1],x+=mv[i][0])
					{
						if(c(x)&&c(y)&&(r=c2(x,y)))
						{
							if(r==2)M[y][x]='#';
							goto e;
						}
						M[y][x]='#';
						if((mv[i][1]&&M[y+(mv[i][1]*2)][x]=='#')||(mv[i][0]&&M[y][x+(mv[i][0]*2)]=='#'))
							break;
					}
			}
			e:for(i=0;i<S;i++,i!=S?puts(""):0)
				  for(j=0;j<S;j++)
					printf("%c",M[i][j]==0?' ':M[i][j]);
		}
	}
	return 0;
}