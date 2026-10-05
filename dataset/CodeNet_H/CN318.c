#define LIM		30
#define MAX		1000002
#define EPS		1e-8
typedef struct { int x, r; long long r2; } T;
T tbl[100002];
int n;
int in()
{
	int n = 0;
	int c = getchar_unlocked();
	do n = (n<<3)+(n<<1) + (c & 0xf), c = getchar_unlocked();
	while (c >= '0');
	return n;
}
int check(double d)
{
	int i;
	double xmin, xmax, xx, d2;
	d2 = d*d;
	xmin = -MAX, xmax = MAX;
	for (i = 0; i < n; i++) {
		if (tbl[i].r < d) return 0;
		xx = sqrt(tbl[i].r2 - d2);
		if (tbl[i].x - xx > xmin) xmin = tbl[i].x - xx;
		if (tbl[i].x + xx < xmax) xmax = tbl[i].x + xx;
		if (xmin > xmax) return 0;
	}
	return 1;
}
int cmp(T *a, T *b) { if (a->r - b->r) return a->r - b->r; return a->x - b->x; }
int main()
{
	int i;
	double hi, lo, mi;
	n = in();
	for (i = 0; i < n; i++) {
		tbl[i].x = in(), tbl[i].r = in();
		tbl[i].r2 = (long long)tbl[i].r * tbl[i].r;
	}
	if (i == 1) { printf("%.6lf\n", (double)tbl[0].r); return 0; }
	qsort(tbl, n, sizeof(T), cmp);
	lo = 0, hi = MAX;
	for (i = 0; i < LIM; i++) {
		mi = 0.5*(lo + hi);
		if (check(mi)) lo = mi; else hi = mi;
	}
	printf("%.6lf\n", lo);
	return 0;
}
