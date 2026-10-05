int main(void)
{
	int N,k,m,j,i;
	scanf("%d",&N);
	while(N!=0){
		m=0;
		j=0;
		for(i=0;i<N;i++){
			scanf("%d",&k);
			if(k<2){
				m=m+1;
				if(k==0){
					j=j+1;
				}
			}
		}		
		if(m==N){
			printf("NA\n");
		}
		else{
			printf("%d",N-j+1);
		}
		scanf("%d",&N);
	}
	return 0;
}