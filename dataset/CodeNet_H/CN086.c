int main(){
	int a,b,i,cnt,tmp;
	int flag[100];
	while(scanf("%d %d",&a,&b) != EOF){
		memset(flag,0,sizeof(flag));
		flag[a-1]++;
		flag[b-1]++;
		while(1){
			scanf("%d %d",&a,&b);
			if(a == 0 && b == 0){
				break;
			}
			flag[a-1]++;
			flag[b-1]++;
		}
		cnt = 0;
		tmp = 1;
		for(i = 0;i < 100;i++){
			if(flag[i] % 2 == 1){
				cnt++;
				if(cnt == 3){
					tmp = 0;
					break;
				}
			}
		}
		if(tmp){
			printf("OK\n");
		}else{
			printf("NG\n");
		}
	}
	return 0;
}