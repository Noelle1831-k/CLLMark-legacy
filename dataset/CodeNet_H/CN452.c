int comp(const void *a,const void *b);
int searchSup4(int P[],int imax,int trgt,int times);
int main(){
	int N,M,N0;	
	int P0[1001];
	int P[1001];
	int i,j;
	int bak;
	int score_all;
	while(1){
		scanf("%d %d\n",&N0,&M);
		if(!N0&&!M)break;
		for(i=0;i<N0;i++)scanf("%d\n",&P0[i]);
		P0[N0]=0;
		qsort(P0,N0+1,sizeof(int),comp);
		P[0]=0;
		bak=0;
		N=N0;
		j=1;
		for(i=1;i<=N0;i++){
			if(P0[i]==bak){
				N--;
			}else{
				bak=P0[i];
				P[j]=P0[i];
				j++;
			}
		}
		score_all=searchSup4(P,N,M,4);
		printf("%d\n",score_all);
	}
	return 0;
}
int comp(const void *a,const void *b){
	int x= *(int *)a;
	int y= *(int *)b;
	return x>y?1:(x<y?-1:0);
}
int searchSup4(int P[],int imax,int trgt,int times){
	int score;
	int score_max;
	int i;
	int i0;
	i0=imax;
	while(i0>=0){
		if(P[i0]<=trgt)break;
		i0--;
	}
	if(times==1){
		return P[i0];
	}
	score_max=0;
	for(i=i0;i>=0;i--){
		if(score_max >P[i]*times )break;
		score=P[i]+searchSup4(P,i,trgt-P[i],times-1);
		if(score>=score_max)score_max=score;
	}
	return score_max;
}