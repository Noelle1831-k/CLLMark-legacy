#define MAX 200005
#define N 16
int m;
int w[MAX], t[MAX];;
int sw[MAX], st[MAX];
int c[N], b[N];
int dp[N][32770];		
int bsch(int *a, int l, int r, int x)
{
	int m;
    while (l < r) {
        m = (l + r) >> 1;
		if (a[m] == x) return m;
        if (a[m] < x) l = m + 1; else r = m;
    }
	return l-1;
}
int main()
{
	int n, i, j, k, x, y, lim, ans;
	scanf("%d%d", &m, &n); m++;
	for (sw[0] = st[0] = 0, i = 1; i < m; i++) {
		scanf("%d%d", w+i, t+i);
		sw[i] = sw[i-1] + w[i], st[i] = st[i-1] + t[i];
	}
	for (i = 0; i < n; i++) scanf("%d%d", c+i, b+i);
	for (i = 0; i < n; i++)	{
		x = bsch(sw, 1, m, c[i]);
		y = bsch(st, 1, m, b[i]);
		if (x > y) x = y;
		if (x == m-1) { ans = m-1; goto Done; }
		dp[0][1<<i] = x;
	}
	lim = 1 << n;
	for (k = 1; k < lim; k++) {
		for (i = 0; i < n; i++)	{			
			for (j = 0; j < n; j++) {		
				if (dp[j][k] && !(k & (1<<i))) {
					int ii = k | (1 << i);
					int t = dp[j][k];
					x = bsch(sw, t, m, sw[t] + c[i]);
					y = bsch(st, t, m, st[t] + b[i]);
					if (x > y) x = y;
					if (x == m-1) { ans = m-1; goto Done; }
					if (x > dp[i][ii]) dp[i][ii] = x;
				}
			}
		}
	}
	for (ans = 0, i = 0; i < n; i++) if (dp[i][lim-1] > ans) ans = dp[i][lim-1];
Done:
	printf("%d\n", ans);
	return 0;
}