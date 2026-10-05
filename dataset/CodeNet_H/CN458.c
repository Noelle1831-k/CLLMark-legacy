int m,n;
int max;
void search(int data[][n+2],int count,int j,int i){
	data[j][i]=0;
	int flag=0;
	if(data[j][i-1]==1&&i-1>0){
		search(data,count+1,j,i-1);
		flag=1;
	}
	if(data[j-1][i]==1&&j-1>0){
		search(data,count+1,j-1,i);
		flag=1;
	}
	if(data[j][i+1]==1&&i+1<=n){
		search(data,count+1,j,i+1);
		flag=1;
	}
	if(data[j+1][i]==1&&j+1<=m){
		search(data,count+1,j+1,i);
		flag=1;
	}
	if(flag==0){
		if(max<count){
			max=count;
		}
	}
	data[j][i]=1;
	return ;
}
int main(){
	int i,j;
	roop:
	scanf("%d",&m);
	scanf("%d",&n);
	if(m==0&&n==0){
		return 0;
	}
	max=0;
	int data[m+2][n+2];
	for(i=0;i<n+2;i++){
		data[i][0]=0;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d",&data[j][i]);
		}
		data[0][i]=0;
		data[n+1][i]=0;
	}
	for(i=0;i<n+2;i++){
		data[i][n+1]=0;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(data[j][i]==1){
				search(data,1,j,i);
			}
		}
	}
	printf("%d\n",max);
	goto roop;
}