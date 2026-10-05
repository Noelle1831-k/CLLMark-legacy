typedef struct { int x1, x2; } TABA;
TABA taba[2][10005]; int sz;
int k1, k2;
int split(int x)
{
	int s, i, k;
	for (s = 0, i = 0; ; i++) {
		k = taba[k1][i].x2 - taba[k1][i].x1 + 1;
		if (s + k == x) return i;
		if (s + k > x) break;
		s += k;
	}
	memcpy(taba[k1]+i+1, taba[k1]+i, sizeof(TABA)*(sz-i)), sz++;
	x = (x-s)+taba[k1][i].x1-1;
	taba[k1][i].x2 = x, taba[k1][i+1].x1 = x+1;
	return i;
}
void shuffle(int x, int y)
{
	int i, j, s;
	i = split(x), j = split(y);
	s = 0;
	memcpy(taba[k2],   taba[k1]+j+1, sizeof(TABA)*(sz-j-1)); s += sz - j - 1;
	memcpy(taba[k2]+s, taba[k1]+i+1, sizeof(TABA)*(j-i));    s += j-i;
	memcpy(taba[k2]+s, taba[k1],     sizeof(TABA)*(i+1));
	k1 = k2, k2 = !k2;
}
int main()
{
	int n, m, p, q, r, x, y;
	int i, ans;
	while (scanf("%d", &n) && n > 0) {
		scanf("%d%d%d%d", &m, &p, &q, &r);
		taba[0][0].x1 = 1, taba[0][0].x2 = n, k1 = 0, k2 = 1, sz = 1;
		while (m-- > 0) {
			scanf("%d%d", &x, &y);
			shuffle(x, y);
		}
		x = 0; if (p > 1) x = split(p-1) + 1;
		y = split(q);
		for (ans = 0, i = x; i <= y; i++) {
			if (taba[k1][i].x1 > r) continue;
			if (taba[k1][i].x2 <= r) ans += taba[k1][i].x2 - taba[k1][i].x1 + 1;
			else 			         ans += r - taba[k1][i].x1 + 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}