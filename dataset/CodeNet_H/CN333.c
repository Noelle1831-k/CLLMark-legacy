int main(void){
	int W,H,C,w,h,c;
	scanf("%d %d %d",&W,&H,&C);
	w=W;
	h=H;
	while(c!=0){
		c=w%h;
		w=h;
		h=c;
	}
	printf("%d\n",(W/w)*(H/w)*C);
	return 0;
}