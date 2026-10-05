int main(void)
{
	int  N,x,y,b,p,wa[366],i;
	scanf("%d",&N);
	for(i=1;i<N+1;i++){
		scanf("%d %d %d %d",&x,&y,&b,&p);
		wa[i]=x*b+y*p;
		if(b>=5 && p>=2){
			wa[i]=wa[i]*(1-0.2);
		}
		else if(b>=5 && p<2){
			wa[i]=wa[i]*(1-0.2)+(2-p)*y*(1-0.2);
		}
		printf("%d\n",wa[i]);
	}
	return 0;
}