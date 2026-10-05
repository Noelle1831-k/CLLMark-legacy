char *gets(char *);
char buf[100], *p;
int getInt(void)
{
	int n = 0;
	while (isspace(*p) || *p == ',') p++;
	while (isdigit(*p)) n = 10 * n + (*p++ - '0');
	return n;
}
int a[32][10], N, D;
int s[32][10];
int main()
{
	int i, j, k, n, m;
	while (1) {
		gets(buf); N = atoi(buf); if (!N) break;
		gets(buf); m = atoi(buf) - 1;
		gets(buf); n = atoi(buf) - 1;
		gets(buf); D = atoi(buf);
		for (i = 0; i < D; i++) {
			gets(p = buf); while (isspace(*p)) p++;
			for (j = 0; j < N-1; j++) a[i][j] = (*p++ == '1');
		}
		for (j = 0; j < N; j++) s[D][j] = j;
		for (i = D - 1; i >= 0; i--) {
			for (j = 0; j < N; j++) s[i][j] = s[i + 1][j];
			for (j = 0; j < N - 1; j++) {
				if (a[i][j]) k = s[i][j], s[i][j] = s[i][j + 1], s[i][j + 1] = k;
			}
		}
		if ((k = s[0][m]) == n) puts("0");
		else {
			for (i = 0; i < D; i++) {
				for (j = 0; j < N; j++) {
					if (((s[i][j] == k && s[i][j + 1] == n) || (s[i][j] == n && s[i][j + 1] == k))
						&& (j > 0 && a[i][j-1] == 0) && a[i][j] == 0 &&
						(j < N-1 && a[i][j + 1] == 0)) {
					printf("%d %d\n", i + 1, j + 1); goto Done; }
				}
			}
			puts("1");
		}
	Done:;
	}
	return 0;
}