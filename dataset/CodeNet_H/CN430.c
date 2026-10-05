int s(int a[],int x,int y,int f){
	int i,j,k;
	for(i=y;i>0;i--){
		a[f]=i;k=a[f];
		if(k==x){
			for(j=0;j<=f;j++)printf("%s%d",(j==0)?"":" ",a[j]);
			printf("\n");
		}else if(k<x){
			s(a,x-k,i,f+1);
		}
	}
}
int main(){
	int n,d[35];
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		memset(d,0,sizeof(d));
		s(d,n,n,0);
	}
	return 0;
}