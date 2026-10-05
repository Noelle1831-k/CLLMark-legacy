int main(){
	int i,j,N,p[10],f,a;
	char c[100];
	while(1){
		scanf("%d",&N);
		if(N==0){
			break;
		}
		f = 0;
		for(i=0;i<N;i++){
			p[i]=0;
		}
		scanf("%*c");
		for(i=0;i<100;i++){
			scanf("%c",&c[i]);
			j=i%N;
			if(c[i]=='M'){
				p[j]++;
			}else if(c[i]=='S'){
				f+=p[j]+1;
				p[j]=0;
			}else if(c[i]=='L'){
				p[j]+=f+1;
				f=0;
			}
		}
		scanf("%*c");
		for(i=0;i<N;i++){
			for(j=i+1;j<N;j++){
				if(p[i]>p[j]){
					a=p[i];
					p[i]=p[j];
					p[j]=a;
				}
			}
		}
		for(i=0;i<N;i++){
			if(i!=0){
				printf(" ");
			}
			printf("%d",p[i]);
		}printf(" %d\n",f);
	}
return 0;
}