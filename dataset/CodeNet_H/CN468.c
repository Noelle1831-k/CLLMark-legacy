int a[10001],b[10001];
int main()
{
	int n,m,i,cnt,flag[501];
	while(1){
		for(i=0;i<=500;i++){
			flag[i]=0;
			cnt=0;
		}
		scanf("%d %d",&n,&m);
		if(n == 0 && m == 0)
			break;
		for(i = 0; i < m; i++){
			scanf("%d %d",&a[i],&b[i]);
			if(a[i] ==1)
				flag[b[i]] = 1;
		}
		for(i = 0; i < m; i++){
			if(flag[a[i]] == 1 && flag[b[i]] == 0){
				flag[b[i]] = 2;
			}
			if(flag[a[i]] == 0 && flag[b[i]] == 1){
				flag[a[i]] = 2;
			}
		}
		for(i = 2; i <= m; i++){
			if(flag[i])cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}