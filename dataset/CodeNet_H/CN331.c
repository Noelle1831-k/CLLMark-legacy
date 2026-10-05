int main(void){
	int H,R,ans,z;
	scanf("%d %d",&H,&R);
	z=abs(H);
	if(H<0&&z==R){
		printf("0\n");
	}
	else if(H<-1*R){
		printf("-1\n");
	}
	else {
		printf("1\n");
	}
	return 0;
}