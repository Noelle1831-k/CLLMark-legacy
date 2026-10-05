int main(){
    int a[20],b[100][2],h,i,j,k,m,n,p,q,t,ch;
	scanf("%d",&m);
	while((ch=getchar())!='\n');
	for(i=1;i<=m;i++) a[i]=i;
	scanf("%d",&n);
	while((ch=getchar())!='\n');
	for(i=1;i<=n;i++){
		scanf("%d %d",&p,&q);
		b[i][0]=p;
		b[i][1]=q;
	}
	for(h=1;h<=n;h++){
		for(i=1;i<=n;i++){
			p=b[i][0];
			q=b[i][1];
			for(j=1;j<=m;j++){
				if(a[j]==p){
					for(k=1;k<=m;k++){
						if(a[k]==q){
							if(j>k){
								t=a[k];
								a[k]=a[j];
								a[j]=t;
							}
						break;
						}
					}
				break;
				}
			}
		}
	}
	for(i=1;i<=m;i++){
		printf("%d\n",a[i]);
	}
	return 0;
}