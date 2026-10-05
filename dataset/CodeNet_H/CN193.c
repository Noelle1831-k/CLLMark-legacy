int i,j,k,set,map[150][150],sss[150][150],q[20000][2],blk,ans;
int m,n,s,t,x,y;
void mark(int x,int y){
	if(x<0 || y<0 || x>=m || y>=n)return;
	if(sss[x][y]!=set){
		map[x][y]=map[q[i][0]][q[i][1]]+1;
		sss[x][y]=set;
		q[j][0]=x;q[j][1]=y;
		j++;
	}
}
void search(int x,int y){
	mark(x-1+y%2,y-1);
	mark(x+y%2,y-1);
	mark(x-1,y);
	mark(x+1,y);
	mark(x-1+y%2,y+1);
	mark(x+y%2,y+1);
}
int check(int x,int y,int k){
	if(x<0 || y<0 || x>=m || y>=n)return 0;
	if(sss[x][y]==set || map[x][y]<=k)return 0;
	sss[x][y]=set;
	return 1+check(x-1+y%2,y-1,k+1)+check(x+y%2,y-1,k+1)+check(x-1,y,k+1)+check(x+1,y,k+1)+check(x-1+y%2,y+1,k+1)+check(x+y%2,y+1,k+1);
}
int main(){
	while(scanf("%d",&m)*m){
		set++;
		scanf("%d %d",&n,&s);
		for(i=0;i<s;i++){
			scanf("%d %d",&x,&y);
			y--;x--;
			map[x][y]=0;
			sss[x][y]=set;
			q[i][0]=x;
			q[i][1]=y;
		}
		i=0;j=s;
		while(i<j){
			search(q[i][0],q[i][1]);
			i++;
		}
		for(i=0;i<n;i++){
			if(i%2)fprintf(stderr," ");
			for(j=0;j<m;j++){
				fprintf(stderr,"%d ",map[j][i]);
			}
			fprintf(stderr,"\n");
		}
		scanf("%d",&t);
		ans=0;
		for(i=0;i<t;i++){
			scanf("%d %d",&x,&y);
			x--;y--;set++;
			blk=check(x,y,0);
			if(ans<blk)ans=blk;
		}
		printf("%d\n",ans);
	}
	return 0;
}