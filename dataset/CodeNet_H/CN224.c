typedef struct edge{
	int from,to,cost;
}edge;
edge data[550];
int f[110][9],cal[9];
int n,m,d,k;
int func(char *s){
	int len=strlen(s),a,i;
	if(s[0]=='H')return 0;
	if(s[0]=='D')return 1;
	a=0;
	for(i=1;i<len;i++){
		a*=10;
		a+=s[i]-'0';
	}
	a++;
	if(s[0]=='L')a+=m;
	return a;
}
int v[110];
int main(){
	int i,j,x,y,z,c;
	char s[9],t[9];
	while(1){
		scanf("%d%d%d%d",&m,&n,&k,&d);
		if(n==0)break;
		for(i=0;i<m;i++)scanf("%d",&cal[i]);
		for(i=0;i<d;i++){
			scanf("%s%s%d",s,t,&c);
			data[i+d].to=data[i].from=func(s);
			data[i+d].from=data[i].to=func(t);
			data[i+d].cost=data[i].cost=c*k;
		}
		memset(f,0,sizeof(f));
		for(i=0;i<=n+m+1;i++)v[i]=10000000;
		v[0]=0;
		c=0;
		while(c<m+n+2){
			x=-1;
			for(i=0;i<d*2;i++){
				if(v[data[i].from]!=10000000){
					y=v[data[i].from]+data[i].cost;
					z=0;
					if(1<data[i].to && data[i].to<=m+1 && 
					   f[data[i].from][data[i].to-2]==0){
						y-=cal[data[i].to-2];
						z=1;
					}
					if(v[data[i].to]>y){
						v[data[i].to]=y;
						memcpy(f[data[i].to],f[data[i].from],sizeof(int)*m);
						if(z==1){
							f[data[i].to][data[i].to-2]=1;
						}
						x=0;
					}
				}
			}
			if(x==-1)break;
			c++;
		}
		printf("%d\n",v[1]);
	}
	return 0;
}