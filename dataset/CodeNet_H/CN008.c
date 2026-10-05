int i,j,k,l,n,ans=0;
int main(){
	while(scanf("%d",&n)!=EOF){
		if(n>36)ans=0;
		else{
			for(i=0;i<10;i++){
				for(j=0;j<10;j++){
					for(k=0;k<10;k++){
						for(l=0;l<10;l++){
							if(i+j+k+l==n)ans++;
						}
					}
				}
			}
		}
		printf("%d\n",ans);
		ans=0;
	}
	return 0;
}