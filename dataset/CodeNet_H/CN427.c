#define N 6
char ans[10015];
int d[10015];
void calc(int b, int n)
{
	int i, a = 1;
	for (i = 0; i <= n; i++) {
		if (a >= b) d[i] += a / b, a %= b;
		if (!a) break;
		a *= 10;
	}
}
int main()
{
	int n, k, m, r, i;
	while (scanf("%d%d%d%d", &n, &k, &m, &r) && n > 0) {
		r += N;
		memset(d, 0, sizeof(d));
		calc(n, r);
		if (m == 1) for (k = n, i = 1; i < n; i++, k+=n) calc(k, r);
		for (k = 0, i = r; i >= 0; i--) {
			k += d[i];
			if (k >= 10) ans[i] = '0' + k % 10, k /= 10;
			else         ans[i] = '0' + k, k = 0;
		}
		ans[r-N+1] = 0;
		putchar(ans[0]), putchar('.'), puts(ans+1);
	}
	return 0;
}