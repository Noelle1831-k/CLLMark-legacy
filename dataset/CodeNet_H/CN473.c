int memo[2][5001][10000];
int N;
int map[10000-1];
int tansaku(int pos,int rest,int status) {
	int result=0x3fffffff;
	int now_result;
	if(pos>=N-1)return (rest-status==0)?0:0x3fffffff;
	if(rest<0)return 0x3fffffff;
	if(memo[status][rest][pos]>0)return memo[status][rest][pos]-1;
	if(status) {
		now_result=tansaku(pos+1,rest-1,1);
		if(now_result<result)result=now_result;
		now_result=tansaku(pos+1,rest-1,0)+map[pos];
		if(now_result<result)result=now_result;
	} else {
		now_result=tansaku(pos+1,rest,0);
		if(now_result<result)result=now_result;
		now_result=tansaku(pos+1,rest,1)+map[pos];
		if(now_result<result)result=now_result;
	}
	memo[status][rest][pos]=result+1;
	return result;
}
int main(void) {
	int i;
	int result;
	scanf("%d",&N);
	for(i=0;i<N-1;i++)scanf("%d",&map[i]);
	result=tansaku(0,N/2,0);
	printf("%d\n",result);
	return 0;
}