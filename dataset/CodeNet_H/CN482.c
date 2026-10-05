int status_no[20000];
int status_no_max;
int memo[20][20][20000][2];
char flag[20][21];
int width,height;
void enum_status(void) {
	int current_number;
	int pos;
	int i;
	status_no[0]=0;
	status_no[1]=1;
	pos=2;
	for(current_number=2;current_number<(1<<19);current_number<<=1) {
		for(i=0;status_no[i]<(current_number>>1);i++) {
			status_no[pos]=current_number | status_no[i];
			pos++;
		}
	}
	status_no_max=pos-1;
}
int get_status_num(int status) {
	int left=0;
	int right=status_no_max;
	int mid;
	while(left<=right) {
		mid=(left+right)/2;
		if(status==status_no[mid])return mid;
		else if(status<status_no[mid])right=mid-1;
		else left=mid+1;
	}
	return 0;
}
int search_flags(int w,int h,int x,int y,int stat,int maeisj);
int main(void) {
	int i;
	int all_flags;
	int bad_flags;
	int x,y;
	scanf("%d %d",&height,&width);
	for(i=0;i<height;i++)scanf("%s",flag[i]);
	enum_status();
	all_flags=1;
	for(y=0;y<height;y++) {
		for(x=0;x<width;x++) {
			if(flag[y][x]=='?') {
				all_flags=(all_flags*3)%100000;
			}
		}
	}
	bad_flags=search_flags(width,height,0,0,0,0);
	if(all_flags<bad_flags)all_flags+=100000;
	printf("%d\n",all_flags-bad_flags);
	return 0;
}
int search_flags(int w,int h,int x,int y,int stat,int maeisj) {
	int result=0;
	int stat2;
	if(y>=h)return 1;
	else if(x>=w)return search_flags(w,h,0,y+1,stat,0);
	if(memo[x][y][get_status_num(stat)][maeisj]>0) {
		return memo[x][y][get_status_num(stat)][maeisj]-1;
	}
	if(flag[y][x]!='?') {
		if(flag[y][x]=='J') {
			stat2=(stat<<1) & ((1<<(w-1))-1);
			result=search_flags(w,h,x+1,y,stat2,1);
		} else if(flag[y][x]=='O') {
			stat2=(stat<<1) & ((1<<(w-1))-1);
			if(maeisj)stat2|=1;
			result=search_flags(w,h,x+1,y,stat2,0);
		} else if(flag[y][x]=='I') {
			if(!(stat & (1<<(w-2)))) {
				stat2=(stat<<1) & ((1<<(w-1))-1);
				result=search_flags(w,h,x+1,y,stat2,0);
			}
		}
	} else {
		stat2=(stat<<1) & ((1<<(w-1))-1);
		result=search_flags(w,h,x+1,y,stat2,1);
		stat2=(stat<<1) & ((1<<(w-1))-1);
		if(maeisj)stat2|=1;
		result+=search_flags(w,h,x+1,y,stat2,0);
		if(!(stat & (1<<(w-2)))) {
			stat2=(stat<<1) & ((1<<(w-1))-1);
			result+=search_flags(w,h,x+1,y,stat2,0);
		}
	}
	result%=100000;
	memo[x][y][get_status_num(stat)][maeisj]=result+1;
	return result;
}