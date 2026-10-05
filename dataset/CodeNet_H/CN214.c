M;
X[100][4],Y[100][4],P[100];
long long cross(o,i,a,j,b,k){
	return (X[a][j]-X[o][i])*(Y[b][k]-Y[o][i])-(Y[a][j]-Y[o][i])*(X[b][k]-X[o][i]);
}
is_intersected_ls(a,i,b,j){
	int i2=(i+1)%4,j2=(j+1)%4;
	int p1x=X[a][i],p2x=X[a][i2],p3x=X[b][j],p4x=X[b][j2];
	int p1y=Y[a][i],p2y=Y[a][i2],p3y=Y[b][j],p4y=Y[b][j2];
	if(p1x>=p2x){
		if(p1x<p3x&&p1x<p4x||p2x>p3x&&p2x>p4x)
			return 0;
	}else{
		if(p2x<p3x&&p2x<p4x||p1x>p3x&&p1x>p4x)
			return 0;
	}
	if(p1y>=p2y){
		if(p1y<p3y&&p1y<p4y||p2y>p3y&&p2y>p4y)
			return 0;
	}else{
		if(p2y<p3y&&p2y<p4y||p1y>p3y&&p1y>p4y)
			return 0;
	}
	return cross(a,i,a,i2,b,j)*cross(a,i,a,i2,b,j2)<=0&&
		   cross(b,j,b,j2,a,i)*cross(b,j,b,j2,a,i2)<=0;
}
is_internal_ill(a,b,i){
	int j,r=1;
	for(j=0;j<4;j++)
		if(cross(a,j,a,(j+1)%4,b,i)>0)
			r=0;
	return r;
}
is_intersected_ill(a,b){
	int i,j;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(is_intersected_ls(a,i,b,j))
				return 1;
	for(i=0;i<4;i++)
		if(is_internal_ill(a,b,i)||
		   is_internal_ill(b,a,i))
			return 1;
	return 0;
}
Power(m){
	int Q[100],q,i;
	q=m;
	Q[q]=-1;
	for(;m>=0;){
		P[m]=0;
		for(i=m;++i<M;){
			if(P[i]&&is_intersected_ill(m,i)){
				q=Q[q]=i;
				Q[q]=-1;
			}
		}
		m=Q[m];
	}
}
main(){
	int N,i,j,c;
	for(;scanf("%d",&N),N;){
		for(;N--;){
			scanf("%d",&M);
			for(i=0;i<M;i++){
				for(j=0;j<4;j++)
					scanf("%d%d",&X[i][j],&Y[i][j]);
				P[i]=1;
			}
			c=0;
			for(i=0;i<M;i++){
				if(P[i]){
					Power(i);
					c++;
				}
			}
			printf("%d\n",c);
		}
	}
	exit(0);
}