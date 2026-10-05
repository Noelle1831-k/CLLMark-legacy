int main (void){
	int n,pm,pe,pj,i;
	for(;;){
		scanf("%d",&n);
		if(n == 0) break;
		for(i=0;i<n;i++){
			scanf("%d %d %d",&pm,&pe,&pj);
			if(pm == 100 || pe == 100 || pj == 100){
				printf("A\n");
			}else if((pm + pe)/2 >= 90){
				printf("A\n");
			}else if((pm + pe + pj)/3 >= 80){
				printf("A\n");
			}else if((pm + pe + pj)/3 >= 70){
				printf("B\n");
			}else if((pm + pe + pj)/3 >= 50 && (pm >= 80 || pe >= 80)){
				printf("B\n");
			}else{
				printf("C\n");
			}
		}
	}
	return 0;
}