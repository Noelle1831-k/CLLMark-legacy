int main(void)
{
	int e[12],i,j,box;
	for(i=0;i<12;i++){
	scanf("%d",&e[i]);
	}
	for(i=0;i<11;i++){
		for(j=i+1;j<12;j++){
			if(e[i]>e[j]){
				box=e[i];
				e[i]=e[j];
				e[j]=box;
			}
		}
	}
		if(e[0]==e[1]&&e[1]==e[2]&&e[2]==e[3]&&e[4]==e[5]&&e[5]==e[6]&&e[6]==e[7]&&e[8]==e[9]&&e[9]==e[10]&&e[10]==e[11]){
		printf("yes\n");
		}
		else{
			printf("no\n");
		}
	return 0;
}
