int tbl[11] = { 0,0,10000,464,100,39,21,13,10,7,6 };
int sb(int a)
{
	int s = 0;
	while (a) {
		s += a % 10;
		a /= 10;
	}
	return s;
}
int main()
{
	int a, n, m;
	int x, y, lim, ans;
	scanf("%d%d%d", &a, &n, &m);
	lim = tbl[n] - a, ans = 0;
	for (y = 1; y <= lim; y++) {
		x = (int)pow(y + a, n);
		if (x > m) break;
		if (sb(x) == y) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
