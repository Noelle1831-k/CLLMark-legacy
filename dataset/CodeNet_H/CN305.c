#define MAX 302
int map[MAX][MAX];
int sr[MAX][MAX], sc[MAX][MAX];
char buf[2000], *p;
int getint()
{
	int n = 0;
	if (*p == '-') {
		p++; while (*p >= '0') n = (n<<3) + (n<<1) + (*p++ & 0xf);
		return -n;
	}
	while (*p >= '0') n = (n<<3) + (n<<1) + (*p++ & 0xf);
	return n;
}
int main()
{
	int n, r, c, s, i, ans;
	fgets(p=buf, 10, stdin), n = getint();
	for (r = 0; r < n; r++) {
		fgets(p=buf, 2000, stdin);
		for (c = 0; c < n; c++) map[r][c] = getint(), p++;
	}
	for (r = 0; r < n; r++) {
		sr[r][0] = 0, sc[r][0] = 0;
		for (c = 1; c <= n; c++) {
			sr[r][c] = sr[r][c-1] + map[r][c-1];
			sc[r][c] = sc[r][c-1] + map[c-1][r];
		}
	}
	ans = 0;
	for (r = 0; r < n; r++) for (c = r; c < n; c++) {
		if (sr[r][c+1] - sr[r][r] > ans) ans = sr[r][c+1]-sr[r][r];
		if (c == r) continue;
		s = sc[0][c+1] - sc[0][r];
		for (i = 1; i < n; i++) {
			int u, v;
			u = v = sc[i][c+1] - sc[i][r];
			if (s > 0) u += s;
			if (u > ans) ans = u;
			if (s + map[r][i] + map[c][i] < v) s = v;
			else s += map[r][i] + map[c][i];
		}
	}
	printf("%d\n", ans);
	return 0;
}