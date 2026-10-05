#define REP(i,n,m) for(i=n;i<m;i++)
#define rep(i,n) REP(i,0,n)
int count[9];
int solve(int used){
	int pos;
	int res;
	rep(pos,9) if(count[pos] != 0) break;
	if(pos == 9) return 1;
	if(count[pos] >= 3){
		count[pos] -= 3;
		res = solve(used);
		count[pos] += 3;
		if(res) return 1;
	}
	if(count[pos] >= 2 && !used){
		count[pos] -= 2;
		res = solve(1);
		count[pos] += 2;
		if(res) return 1;
	}
	if(pos <= 6 && count[pos] >= 1 && count[pos+1] >= 1 && count[pos+2] >= 1){
		count[pos]--; count[pos+1]--; count[pos+2]--;
		res = solve(used);
		count[pos]++; count[pos+1]++; count[pos+2]++;
		if(res) return 1;
	}
	return 0;
}
int main(void){
	int i,j,ansFlg,res;
	int ans[9],size;
	char s[14];
	while(scanf("%s",s) != EOF){
		rep(i,9) count[i] = 0;
		rep(i,13) count[s[i]-'1']++;
		ansFlg = 1;
		rep(i,9) if(count[i] >= 5) ansFlg = 0;
		if(!ansFlg){
			printf("0\n");
			continue;
		}
		size = 0;
		rep(i,9){
			if(count[i] == 4) continue;
			count[i]++;
			if(solve(0)) ans[size++] = i + 1;
			count[i]--;
		}
		if(size == 0) printf("0");
		rep(i,size){
			if(i != 0) printf(" ");
			printf("%d",ans[i]);
		}
		printf("\n");
	}
	return 0;
}