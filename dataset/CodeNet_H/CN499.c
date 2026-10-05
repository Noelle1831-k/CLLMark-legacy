int main(){
	int a,b,c,d,l,ans,ko=0,sa=0;
	scanf("%d %d %d %d %d",&l,&a,&b,&c,&d);
	while(a>0){
		a=a-c;
		ko++;
	}
	while(b>0){
		b=b-d;
		sa++;
	}
	if(ko>sa){
		ans=l-ko;
	}else{
		ans=l-sa;
	}
	printf("%d\n",ans);
	return 0;
}