void check(int s,int n,int c,int m,int t,int *ans);
int main(void){
	int n,s,ans;
	while(scanf("%d %d",&n,&s)){
		if(n==0 && s==0)break;
		ans=0;
		check(s,n,0,0,0,&ans);
		printf("%d\n",ans);
	}
	return 0;
}
void check(int s,int n,int c,int m,int t,int *ans){
	int i;
	if(n==c){
		if(t==s)*ans+=1;
		return;
	}
	for(i=m;i<10;i++)check(s,n,c+1,i+1,t+i,ans);
	return;
}
