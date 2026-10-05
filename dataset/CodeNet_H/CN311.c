int main(void){
	int a,b,c,d,h1,h2,k1,k2,h,k;
	scanf("%d %d %d %d %d %d %d %d",&h1,&h2,&k1,&k2,&a,&b,&c,&d);
	h=h1*a+h2*b+(h1/10)*c+(h2/20)*d;
	k=k1*a+k2*b+(k1/10)*c+(k2/20)*d;
	if(h>k){
		printf("hiroshi\n");
	}
	else if(h==k){
		printf("even\n");
	}
	else{
		printf("kenjiro\n");
	}
	return 0;
}
