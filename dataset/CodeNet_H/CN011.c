int main(void){
	int w,n,dataw[31],i,one,two,j;
	for(i=1;i<31;i++)
		dataw[i]=i;
	scanf("%d",&w);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d,%d",&one,&two);
		j=dataw[one];
		dataw[one]=dataw[two];
		dataw[two]=j;
	}
	for(i=0;i<w;i++)
		printf("%d\n",dataw[i+1]);
	return 0;
}