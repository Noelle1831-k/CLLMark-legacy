#define xam(x,y) (x>y?x:y)
int turaras[100000],times[100000],n,l;
int solve(int i){
	if(times[i]!=-1)return times[i];
	int time=0;
	if(turaras[i]<turaras[i-1]&&i>0){
		time=solve(i-1);		
	}
	if(turaras[i]<turaras[i+1]&&i<n-1){
		time=xam(time,solve(i+1));		
	}	
	return times[i]=time+l-turaras[i];
}
int main(){
	int i;
	scanf("%d%d",&n,&l);
	memset(times,-1,sizeof(times));
	for(i=0;i<n;i++){
		scanf("%d",turaras+i);	
	}
	int max=0;
	for(i=0;i<n;i++){
		max=xam(max,solve(i));	
	}
	printf("%d",max);
}