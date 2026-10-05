#define MAX(x,y) ((x>y)?x:y)
typedef struct g{
	int d,s,e;
}G;
G a[12];
typedef struct p{
	int x,y,z,f;
}P;
P q[50000],sq[50000],cp;
int qn,sqn;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
char map[25][25];
int func(int d,P p){
	p.x+=dx[d];p.y+=dy[d];
	int m=map[p.y][p.x]-'0';
	if(0<=m && m<=9 && !(p.f&(1<<m)))return m;
	else return -1;
}
void func2(int f){
	int i;
	for(i=0;i<10;i++){
		if((f>>i)&1)printf("1");
		else printf("0");
	}
	printf("\n");
}
int main(){
	int i,j,k,w,h,n,m,mt,t,ans;
	char s;
	while(1){
		scanf("%d %d\n",&w,&h);
		if(w+h==0)break;
		for(i=0;i<=h+1;i++)map[i][0]=map[i][w+1]='#';
		for(i=1;i<=w  ;i++)map[0][i]=map[h+1][i]='#';
		for(i=1;i<=h;i++){
			for(j=1;j<=w;j++){
				scanf("%c ",&map[i][j]);
				if(map[i][j]=='P'){
					q[0]=(P){j,i,0,0};
					map[i][j]='.';
				}
			}
		}
		mt=0;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&m);
			scanf("%d%d%d",&a[m].d,&a[m].s,&a[m].e);
			mt=MAX(mt,a[m].e);
		}
		qn=1;
		t=0;
		for(i=0;i<4;i++){
			m=func(i,q[0]);
			if(m!=-1 && a[m].s<=0 && 0<a[m].e){
				q[0].z+=a[m].d;
				q[0].f=q[0].f|(1<<m);
			}
		}
		while(t<=mt){
			sqn=0;
			for(i=0;i<qn;i++){
				printf("%2d %2d %3d ",q[i].x,q[i].y,q[i].z);
				func2(q[i].f);
				for(j=0;j<4;j++){
					cp=q[i];
					cp.x+=dx[j];
					cp.y+=dy[j];
					if(map[cp.y][cp.x]=='.'){
						for(k=0;k<4;k++){
							m=func(k,cp);
							if(m!=-1 && a[m].s<=t && t<a[m].e){
								cp.z+=a[m].d;
								cp.f=cp.f|(1<<m);
							}
						}
						for(k=0;k<sqn;k++){
							if(sq[k].x==cp.x && sq[k].y==cp.y){
								if(cp.f>sq[k].f && !((~cp.f)&sq[k].f)){
									sq[k]=cp;
									break;
								}
								if(sq[k].z>cp.z || sq[k].f==cp.f)break;
							}
						}
						if(k==sqn)sq[sqn++]=cp;
					}
				}
			}
			memcpy(q,sq,sizeof(P)*sqn);
			qn=sqn;
			t++;
			printf("\n");
		}
		ans=0;
		printf("%d\n",sqn);
		for(i=0;i<qn;i++)ans=MAX(ans,q[i].z);
		printf("%d\n",ans);
	}
	return 0;
}