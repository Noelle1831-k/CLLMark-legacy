char *gets(char *);
char buf[100];
int f[65];
int main()
{
	unsigned i, n, m, k;
	unsigned ans, a;
	while (1) {
		gets(buf);
		if (!(n = atoi(buf))) break;
		memset(f, 0, sizeof(f));
		for (i = 0; i < n; i++) {
			gets(buf);
			f[atoi(buf)]++;
		}
		if (n == 1) { puts("0"); continue; }
		for (i = 1, ans = 0, m = n; m > 0 && i <= 60; i++) {
			if ((k = f[i])) {
				a = m*k - ((k*(k + 1)) >> 1);
				ans += a * i;
				m -= k;
			}
		}
		printf("%u\n", ans);
	}
	return 0;
}