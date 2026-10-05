int main(void)
{
    int i,j,a,b,c[10000];
	while(1){
		scanf("%d",&a);
		if(a==0) break;
		for(i=0;i<10;i++){
		c[i]=0;
		}
		for(i=0;i<a;i++){
			scanf("%d",&b);
			c[b-1]+=1;
		}
		for(i=-1;i<9;i++){
			if(c[i]>0){
				for(j=0;j<c[i];j++){
					printf("*");
				}
			printf("\n");
			}
			else{
				printf("-\n");
			}
		}
	}
	return 0;
}