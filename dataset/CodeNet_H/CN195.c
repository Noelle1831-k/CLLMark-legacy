int main(){
	int n,m,i,maxN,max;
	for(i=0;scanf("%d %d",&n,&m)&&(n||m);i++){
		if(!(i%5))max=-1;
		if(n+m>max){
			max=n+m;maxN=i%5;}
		if(i%5==4)printf("%c %d\n",'A'+maxN,max);
	}return 0;}