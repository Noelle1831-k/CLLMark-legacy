int n_max,m_max,cnt_max;
int ADJ1[10*150+2][10*150+2];
int ADJ2[10*150+2][10*150+2];
int xstart[150+2];
int xend[150+2];
int MinCost[76][10*150+2];
typedef struct tag_POINT {
	int n;
	int x;
	int d;
}POINT;
POINT Stone[10*150+2];
int search();
int main(){
	int x,n,d,k;
	int cnt;
	int i,j;
	int ans;
	while(1){
		scanf("%d %d\n",&n_max,&m_max);
		if(!n_max&&!m_max)break;
		cnt=0,n=0,x=0,d=0;
		Stone[cnt].n=n;Stone[cnt].x=x;Stone[cnt].d=d;
		xstart[n]=cnt;xend[n]=cnt;
		cnt++;
		for(n=1;n<=n_max;n++){
			scanf("%d",&k);
			if(k==0){xstart[n]=-1;xend[n]=-2;}
			for(i=0;i<k;i++){
				if(i==0)xstart[n]=cnt;
				if(i==k-1)xend[n]=cnt;
				scanf("%d%d",&x,&d);
				Stone[cnt].n=n;Stone[cnt].x=x;Stone[cnt].d=d;
				cnt++;
			}
		}
		Stone[cnt].n=n;Stone[cnt].x=0;Stone[cnt].d=0;
		xstart[n]=cnt;xend[n]=cnt;
		cnt_max=cnt;
		for(i=0;i<=n_max+1;i++){
			for(j=0;j<=n_max+1;j++){
				ADJ1[i][j]=ADJ2[i][j]=-1;
			}
		}
		for(i=xstart[1];i<=xend[1];i++)ADJ1[0][i]=0;
		for(i=xstart[2];i<=xend[2];i++)ADJ2[0][i]=0;
		for(cnt=1;Stone[cnt].n<n_max-1;cnt++){
			for(i=xstart[Stone[cnt].n+1];i<=xend[Stone[cnt].n+1];i++){
				ADJ1[cnt][i]=(Stone[cnt].d+Stone[i].d)*(Stone[cnt].x>Stone[i].x?Stone[cnt].x-Stone[i].x:Stone[i].x-Stone[cnt].x);
			}
			for(i=xstart[Stone[cnt].n+2];i<=xend[Stone[cnt].n+2];i++){
				ADJ2[cnt][i]=(Stone[cnt].d+Stone[i].d)*(Stone[cnt].x>Stone[i].x?Stone[cnt].x-Stone[i].x:Stone[i].x-Stone[cnt].x);
			}
		}
		for(cnt=xstart[n_max-1];cnt<=xend[n_max-1];cnt++){
			for(i=xstart[Stone[cnt].n+1];i<=xend[Stone[cnt].n+1];i++){
				ADJ1[cnt][i]=(Stone[cnt].d+Stone[i].d)*(Stone[cnt].x>Stone[i].x?Stone[cnt].x-Stone[i].x:Stone[i].x-Stone[cnt].x);
			}
			for(i=xstart[Stone[cnt].n+2];i<=xend[Stone[cnt].n+2];i++){
				ADJ2[cnt][i]=0;
			}
		}
		for(cnt=xstart[n_max];cnt<=xend[n_max];cnt++){
			for(i=xstart[Stone[cnt].n+1];i<=xend[Stone[cnt].n+1];i++){
				ADJ1[cnt][i]=0;
			}
		}
		ans=0;cnt=0;
		ans=search();
		printf ("%d\n",ans);
	}
	return 0;
}
int search(){
	int cnt;
	int m;
	for(cnt=0;cnt<=cnt_max;cnt++){
		for(m=0;m<=m_max;m++){
			MinCost[m][cnt]=1000*150+1;
		}
	}
	int i,j,min_temp;
	for(cnt=0;cnt<=cnt_max;cnt++){
		if(cnt==0){
			MinCost[0][0]=0;
		}
		if(Stone[cnt].n==1){
			MinCost[0][cnt]=0;
		}
		if(Stone[cnt].n>=2){
			min_temp=1000*150+1;
			for(i=xstart[Stone[cnt].n-1];i<=xend[Stone[cnt].n-1];i++){
				if(min_temp>=ADJ1[i][cnt]+MinCost[0][i])min_temp=ADJ1[i][cnt]+MinCost[0][i];
			}
			MinCost[0][cnt]=min_temp;
			for(m=1;m<=m_max;m++){
				min_temp=1000*150+1;
				for(i=xstart[Stone[cnt].n-1];i<=xend[Stone[cnt].n-1];i++){
					if(min_temp>=ADJ1[i][cnt]+MinCost[m][i])min_temp=ADJ1[i][cnt]+MinCost[m][i];
				}
				for(i=xstart[Stone[cnt].n-2];i<=xend[Stone[cnt].n-2];i++){
					if(min_temp>=ADJ2[i][cnt]+MinCost[m-1][i])min_temp=ADJ2[i][cnt]+MinCost[m-1][i];
				}
				MinCost[m][cnt]=min_temp;
			}
		}
	}
	min_temp=1000*150+1;
	for(m=0;m<=m_max;m++){
		if(min_temp>=MinCost[m][cnt_max])min_temp=MinCost[m][cnt_max];
	}
	return min_temp;
}