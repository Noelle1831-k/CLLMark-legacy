typedef struct _node{
	long long int p;
	long long int q;
	int r;
	int b;
	long long int left;	
	long long int right;	
} Node;
long long int calc_mass(int trgt);
long long int calc_gcd( long long int a,long long int b);
Node MOB[101];
int main(){
	int n;
	int chk[101];
	int i;
	long long int p;
	long long int q;
	int r;
	int b;
	int Top;
	long long int Total;
	long long int gcd;
	while(1){
		scanf("%d\n",&n);
		if(n==0)break;
		for(i=1;i<=n;i++){
			scanf("%lld %lld %d %d\n",&p,&q,&r,&b);
			gcd=calc_gcd(p,q);
			MOB[i].p=p/gcd;
			MOB[i].q=q/gcd;
			MOB[i].r=r;
			MOB[i].b=b;
			MOB[i].left=0;
			MOB[i].right=0;
		}
		for(i=1;i<=n;i++)chk[i]=0;
		for(i=1;i<=n;i++){
			if(MOB[i].r!=0)chk[MOB[i].r]=1;
			if(MOB[i].b!=0)chk[MOB[i].b]=1;
		}
		for(i=1;i<=n;i++){
			if(chk[i]==0){
				Top=i;
				break;
			}
		}
		Total=calc_mass(Top);
		printf("%lld\n",Total);
	}
	return 0;
}
long long int calc_gcd( long long int a, long long int b){
	long long int c=1;
	long long int gcd;
        gcd=1;
	while(a%b!=0){
		c=b;
		b=a%b;
		a=c;
	}
	gcd=b;
	return gcd;
}
long long int calc_mass(int trgt){
	long long int gcd;
	long long int left,right;
	if(MOB[trgt].r==0 && MOB[trgt].b==0){
		gcd=calc_gcd(MOB[trgt].p,MOB[trgt].q);
		MOB[trgt].left=MOB[trgt].q/gcd;
		MOB[trgt].right=MOB[trgt].p/gcd;
		return MOB[trgt].left+MOB[trgt].right;
	}
	if(MOB[trgt].left==0){
		if(MOB[trgt].r==0)left=1;
		if(MOB[trgt].r!=0)left=calc_mass(MOB[trgt].r);
	}
	if(MOB[trgt].right==0){
		if(MOB[trgt].b==0)right=1;
		if(MOB[trgt].b!=0)right=calc_mass(MOB[trgt].b);
	}
	gcd=calc_gcd(left*MOB[trgt].q,right*MOB[trgt].p);
	MOB[trgt].left=left*right*MOB[trgt].p/gcd;
	MOB[trgt].right=right*left*MOB[trgt].q/gcd;
	return MOB[trgt].left+MOB[trgt].right;
}