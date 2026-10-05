typedef int LONG;
LONG memo[10][1001][101];
int z;
LONG comb(int *use, int n, int s, int m)
{
	int i;
	LONG c;
	if (memo[n][s][m] != -1){
		return (memo[n][s][m]);
	}
	if (n == 1){
    	if (0 <= s && s <= 100 && s >= m && use[s] == 0){
            z++;
#if 0
			printf("[");
			for (i = 0; i <= 100; i++){
				if (use[i])printf("%d ", i);
			}
			printf("%d]", s);
#endif
			memo[n][s][m] = 1;
			return (1);
		}
		memo[n][s][m] = 0;
		return (0);
	}
	c = 0;
	for (i = m; i <= 100; i++){
		if (use[i] == 0){
			use[i] = 1;
			if (s - i >= 0){
				c += comb(use, n - 1, s - i, i + 1);
			}
			use[i] = 0;
		}
	}
	memo[n][s][m] = c;
	return (c);
}
int main(void)
{
	int n, s;
	int use[101];
	int c;
	int i;
	while (1){
		scanf("%d%d", &n, &s);
		if (n == 0 && s == 0){
			break;
		}
		memset(use, 0, sizeof(use));
		memset(memo, -1, sizeof(memo));
        z = 0;
		comb(use, n, s, 0);
		printf("%d\n", z);
	}
	return (0);
}