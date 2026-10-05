#define MAX(x,y) (((x)>(y))?(x):(y))
int i,j;
int n,k,a[100005],b[100005],x,ans,ans2,flag;
int comp(const void *p,const void *q){
	return *(int *)p-*(int *)q;
}
int main(){
	scanf("%d %d",&n,&k);
	while(n!=0 && k!=0){
		for(i=0;i<k;i++)b[i]=0;
		for(i=0;i<k;i++){scanf("%d",&a[i]);b[a[i]]=1;}
		qsort(a,k,sizeof(int),comp);
		ans=0;ans2=0;flag=2;
		if(a[0]==0){
			for(i=2;i<n;i++)b[i]=(b[i]+b[i-1])*b[i];
			for(i=1;i<n;i++)if(b[i]>ans)ans=b[i];
			ans++;
		}else{
			for(i=1;i<n;i++)b[i]=(b[i]+b[i-1])*b[i];
			for(i=0;i<n;i++)if(b[i]>ans)ans=b[i];
		}
		printf("%d\n",ans);
		scanf("%d %d",&n,&k);
	}
	return 0;
}