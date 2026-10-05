int main(void)
{
	int max;
	int n;
	int d[251];
	int i,j;
	while(1){
		scanf("%d",&max);
		if(max==0){
			break;
		}
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&d[i]);
		}
		i=0;
		while(i<n){
			while(d[i]>=0){
				i++;
				if(i>n){
					break;
				}
			}
			if(i>n){
				break;
			}
			for(j=0;j<max;j++){
				if(d[i+j]>-j-1){
					break;
				}
			}
			if(j==max){
				i=n;
				break;
			}
			i++;
		}
		if(i>n){
			printf("OK\n");
		}else{
			printf("NG\n");
		}
	}
	return 0;
}