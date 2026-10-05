#define MAX  1000000
#define SQRT 1000     
char prime[MAX + 5], *p, *q, *pmax = prime + MAX;
int main()
{
	int N, P, M;
	int k, a, b, ans, x;
	for (k = 3, p = prime + 3; k <= SQRT; k += 2, p += 2) {
		if (!*p) {
			for (q = p + k; q <= pmax; q += k) *q = 1;
		}
	}
	while (1) {
		scanf("%d", &N); if (!N) break;
		for (ans = 0, k = 0; k < N; k++) {
			scanf("%d%d", &P, &M);
			a = P - M, b = P + M, x = 0;
			if (a < 2) a = 2;
			if (a == 2) x++, a = 3;
			if (!(a & 1)) a++;
			if (b > 1000000) b = 1000000;
			for (p = prime + a; a <= b; a += 2, p += 2)	if (!(*p)) x++;
			ans += x - 1;
		}
		if (ans < 0) ans = 0;
		printf("%d\n", ans);
	}
	return 0;
}