int main(){
	int su,i,building,level,jump;
	int a[2][100];
	while(1){
		building=0;
		level=0;
		jump=0;
		scanf("%d",&su);
		if(su==0) break;
		for(i=0;i<su;i++) scanf("%d",&a[0][i]);
		for(i=0;i<su;i++) scanf("%d",&a[1][i]);
		if(a[1][0]==1) building=1;
		for(i=0;i<150;i++){
			if(a[building][level+1]==1) level++;
			else if(a[building][level]==2) level--;
			else{
				building=(building+1)%2;
				level+=2;
				jump++;
			}
			if(su<=level) break;
		}
		if(su<=level) printf("%d\n",jump);
		else printf("NA\n");
	}
	return 0;
}