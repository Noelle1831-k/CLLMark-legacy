int main(void){
	int x,y,a,s,d,f;
	scanf("%d %d %d %d",&a,&s,&d,&f);
	printf("%d %d\n",x=(d+s+d+f)/60,y=(a+s+d+f)%60);
	return 0;
}