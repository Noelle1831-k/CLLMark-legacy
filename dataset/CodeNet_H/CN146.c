int i,j,n,nxt,max,num[20],dist[20],wei[20],next[36000][20],time[36000][20];
double search(int code,int weg,int now){
	if(code>=max-1)return 0;
	int div=2,sel,i,wgg,nxt;
	double ttt=999999999,tim,addt;
	if(time[code][now]>0)return time[code][now];
	for(i=0;i<n;i++,div*=2){
		if(code%div<div/2){
			if(now==-1)addt=0;
			else addt=abs(dist[now]-dist[i])*(weg+70)/2000.0;
			tim=addt+search(code+div/2,weg+wei[i],i);
			if(ttt>tim){ttt=tim;sel=i;}
		}
	}
	next[code][now>=0 ? now : 0]=sel;
	time[code][now>=0 ? now : 0]=ttt;
	return ttt;
}
int main(){
	scanf("%d",&n);
	max=(int)pow(2.0,n);
	for(i=0;i<n;i++){
		scanf("%d %d %d",&num[i],&dist[i],&wei[i]);
		wei[i]*=20;
	}
	search(0,0,-1);
	for(i=0,j=0;i<max-1;){
		nxt=next[i][j];
		printf("%s%d",i>0?" ":"",num[nxt]);
		i+=(int)pow(2.0,nxt);
		j=nxt;
	}
	printf("\n");
	return 0;
}