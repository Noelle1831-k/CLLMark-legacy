int main(void){
	int a;
	int s=1;
	scanf("%d",&a);
	while(1){
		if((s*2) > a){
			printf("%d\n",s);
			break;
		}
		s*=2;
	}
    return 0;
}
