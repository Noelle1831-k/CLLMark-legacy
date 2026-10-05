int bm[13], bw[13], f[13];
int M, W;
int max;
void combi(int n, int e)
{
	int i, d;
	if (n == M) { if (e > max) max = e; return; }
	for (i = 0; i < W; i++) {
		if (f[i]) continue;
		f[i] = 1;
		d = bm[n] - bw[i]; if (d < 0) d = -d;
		combi(n + 1, e + d * (d - 30) * (d - 30));
		f[i] = 0;
	}
}
int main()
{
	int i, t;
	while (scanf("%d%d", &M, &W) && M) {
		if (M <= W) {
			for (i = 0; i < M; i++) scanf("%d", bm + i);
			for (i = 0; i < W; i++) scanf("%d", bw + i);
		} else {
			for (i = 0; i < M; i++) scanf("%d", bw + i);
			for (i = 0; i < W; i++) scanf("%d", bm + i);
			t = M, M = W, W = t;
		}
		printf("M %d, W %d\n", M, W);
		max = 0;
		memset(f, 0, sizeof(f));
		combi(0, 0);
		printf("%d\n", max);
	}
	return 0;
}