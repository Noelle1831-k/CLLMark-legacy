#define START(a) (a>0?a:0)
int s,ans,ttt,a,b,c,t[1000][1000];
int main(void){
	while(scanf("%d",&s)!=EOF){
		ans=0;
		for(a=START(s-3000);a<=1000 && s>=a;a++){
			for(b=START(s-a-2000);b<=1000 && s>=a+b;b++){
				ans+=1001-abs(1000-(s-a-b));
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}