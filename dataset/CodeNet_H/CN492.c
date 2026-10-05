enum {
	STAT_UL=0,
	STAT_L,
	STAT_DL,
	STAT_DR,
	STAT_R,
	STAT_UR
};
#define ishani(a) ((a)>=0 && (a)<102)
int getstat(int* kabe,int x,int y,int map[102][102]);
void gettuuro(int result[102][102],int x,int y,int map[102][102]);
int main(int argc,char* argv[]) {
	int map[102][102]={0};
	int map2[102][102]={0};
	int stat[6];
	int W,H;
	int i,j,k;
	int result;
	scanf("%d %d",&W,&H);
	for(i=0;i<H;i++) {
		for(j=0;j<W;j++) {
			scanf("%d",&map[i+1][j+1]);
		}
	}
	for(i=0;i<102;i++) {
		for(j=0;j<102;j++)map2[i][j]=1;
	}
	gettuuro(map2,0,0,map);
	result=0;
	for(i=1;i<101;i++) {
		for(j=1;j<101;j++) {
			if(getstat(stat,i,j,map2)) {
				for(k=0;k<6;k++) {
					if(!stat[k])result++;
				}
			}
		}
	}
	printf("%d\n",result);
	return 0;
}
int getstat(int* kabe,int x,int y,int map[102][102]) {
	if(y%2==1) {
		kabe[STAT_UL]=(ishani(y-1) && ishani(x))?map[y-1][x]:1;
		kabe[STAT_L]=(ishani(y) && ishani(x-1))?map[y][x-1]:1;
		kabe[STAT_DL]=(ishani(y+1) && ishani(x))?map[y+1][x]:1;
		kabe[STAT_DR]=(ishani(y+1) && ishani(x+1))?map[y+1][x+1]:1;
		kabe[STAT_R]=(ishani(y) && ishani(x+1))?map[y][x+1]:1;
		kabe[STAT_UR]=(ishani(y-1) && ishani(x+1))?map[y-1][x+1]:1;
	} else {
		kabe[STAT_UL]=(ishani(y-1) && ishani(x-1))?map[y-1][x-1]:1;
		kabe[STAT_L]=(ishani(y) && ishani(x-1))?map[y][x-1]:1;
		kabe[STAT_DL]=(ishani(y+1) && ishani(x-1))?map[y+1][x-1]:1;
		kabe[STAT_DR]=(ishani(y+1) && ishani(x))?map[y+1][x]:1;
		kabe[STAT_R]=(ishani(y) && ishani(x+1))?map[y][x+1]:1;
		kabe[STAT_UR]=(ishani(y-1) && ishani(x))?map[y-1][x]:1;
	}
	return (ishani(y) && ishani(x))?map[y][x]:1;
}
void gettuuro(int result[102][102],int x,int y,int map[102][102]) {
	int stat[6];
	if(!ishani(x) || !ishani(y))return;
	if(!result[y][x] || map[y][x])return;
	if(!getstat(stat,x,y,map)) {
		result[y][x]=0;
		if(y%2==1) {
			gettuuro(result,x,y-1,map);
			gettuuro(result,x-1,y,map);
			gettuuro(result,x,y+1,map);
			gettuuro(result,x+1,y+1,map);
			gettuuro(result,x+1,y,map);
			gettuuro(result,x+1,y-1,map);
		} else {
			gettuuro(result,x-1,y-1,map);
			gettuuro(result,x-1,y,map);
			gettuuro(result,x-1,y+1,map);
			gettuuro(result,x,y+1,map);
			gettuuro(result,x+1,y,map);
			gettuuro(result,x,y-1,map);
		}
	}
}