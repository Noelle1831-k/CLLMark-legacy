char is_sosuu[1000001];
char ok[1000001];
void make_sosuulist(void) {
	int i,j;
	for(i=0;i<=1000000;i++) {
		is_sosuu[i]=1;
	}
	is_sosuu[0]=is_sosuu[1]=0;
	for(i=2;i<=1000000;i++) {
		if(is_sosuu[i]) {
			for(j=i+i;j<=1000000;j+=i)is_sosuu[j]=0;
		}
	}
}
int main(void) {
	int yosan;
	int dish_num;
	int dishes[30];
	int i,j;
	make_sosuulist();
	while(1) {
		scanf("%d%d",&dish_num,&yosan);
		if(dish_num==0 && yosan==0)break;
		for(i=0;i<dish_num;i++)scanf("%d",&dishes[i]);
		memset(ok,0,sizeof(ok));
		ok[0]=1;
		for(i=0;i<=yosan;i++) {
			if(ok[i]) {
				for(j=0;j<dish_num;j++) {
					if(i+dishes[j]<=yosan)ok[i+dishes[j]]=1;
				}
			}
		}
		for(i=yosan;i>0;i--) {
			if(ok[i] && is_sosuu[i])break;
		}
		if(i<=0)puts("NA");
		else printf("%d\n",i);
	}
	return 0;
}