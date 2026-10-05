typedef struct { int c, w; } T;
T tbl[1002];
int s[1002];
char f[1002][1002];
char buf[22], *p;
int getint()
{
	int n = 0;
	while (*p >= '0') n = (n<<3) + (n<<1) + (*p++ & 0xf);
	return n;
}
int main()
{
	int n, i, j, k;
	fgets(p=buf, 10, stdin), n = getint();
	for (i = 1; i <= n; i++) {
		fgets(p=buf, 20, stdin), tbl[i].c = getint(), p++, tbl[i].w = getint();
	}
	memset(f, 0, sizeof(f)); for (i = 1; i <= n; i++) f[i][i] = 1;
	for (s[0] = 0, i = 1; i <= n; i++) s[i] = s[i-1] + tbl[i].w;
	for (k = 1; k <= n; k++) {
		for (i = 1; i <= n-k+1; i++) {
			j = i+k-1;
			if (!f[i][j]) continue;
			if (j+1 <= n) {
				if (s[j]-s[i-1] <= tbl[j+1].c) {
					f[i][j+1] = 1;
				}
			}
			if (i-1 >= 1) {
				if (s[j]-s[i-1] <= tbl[i-1].c) {
					f[i-1][j] = 1;
				}
			}
		}
	}
	memset(s, -1, sizeof(s)); s[0] = 0;
	for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) {
		if (f[i][j] && (s[j] < 0 || s[i-1]+1 < s[j])) s[j] = s[i-1]+1;
	}
	printf("%d\n", s[n]);
	return 0;
}