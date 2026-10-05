a[2][4];
main(i){
	float e[2];
	for(;~scanf("%f%f",e,e+1);){
		for(i=0;i<2;i++){
			if     (e[i]<0.2)	a[i][3]++;
			else if(e[i]<0.6)	a[i][2]++;
			else if(e[i]<1.1)	a[i][1]++;
			else				a[i][0]++;
		}
	}
	for(i=0;i<4;i++)	printf("%d %d\n",a[0][i],a[1][i]);
	exit(0);
}