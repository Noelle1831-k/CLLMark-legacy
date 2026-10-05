#define MAX 200001
#define INF 0x11111111
typedef struct { int x, y, l; } T;
T tbl[MAX];
int seg[4][MAX], sz;
char buf[30], *p;
int in()
{
	int n = 0;
	while (*p >= '0') n = 10*n + (*p++ & 0xf);
	p++;
	return n;
}
#if 0
void segtree(int id, int n)
{
	int k;
	k = 1; while (k < n) k <<= 1;
	sz = k;
	memset(seg[id], INF, sizeof(seg[id]));
}
#endif
void update(int id, int k, int v)
{
	int t;
	k += sz-1;
	seg[id][k] = v;
	while (k > 0) {
		if (!(k & 1)) k--;
		t = k, k >>= 1;
		v = seg[id][t++]; if (v > seg[id][t]) v = seg[id][t];
		seg[id][k] = v;
	}
}
int query2(int id, int a, int b, int k, int l, int r) 
{
	int m, lmin, rmin;
	if (r <= a || b <= l) return INF;
    if (a <= l && r <= b) return seg[id][k];
	k <<= 1, m = (l + r) >> 1;
    lmin = query2(id, a, b, ++k, l, m);
    rmin = query2(id, a, b, ++k, m, r);
    if (lmin > rmin) lmin = rmin; 
    return lmin;
}
int query(int id, int a, int b)
{
	return query2(id, a, b, 0, 0, sz);
}
int cmp(T *a, T *b) { return a->l - b->l; }
int main()
{
	int n, d, i, j;
	long long ans, a;
	fgets(p=buf, 30, stdin);
	n = in(), d = in();
	for (i = 0; i < n; i++) {
		fgets(p=buf, 30, stdin);
		tbl[i].x = in(), tbl[i].y = in(), tbl[i].l = in();
	}
	qsort(tbl, n, sizeof(T), cmp);
	sz = 1; while (sz < n) sz <<= 1;
	memset(seg, INF, sizeof(seg));
	for (i = 0; i < n; i++) {
		update(0, i, -tbl[i].x), update(1, i, tbl[i].x);
		update(2, i, -tbl[i].y), update(3, i, tbl[i].y);
	}
	ans = 0;
	for (i = j = 0; j < n; j++) {
		while (j < n && tbl[j].l - tbl[i].l <= d) j++;
		if (j == n) j--;
		a = (((long long)query(0, i, j)) + query(1, i, j)) *
			(((long long)query(2, i, j)) + query(3, i, j));
		if (a > ans) ans = a;
		while (i < n && tbl[j].l - tbl[i].l > d) i++;
	}
	printf("%lld\n", ans);
	return 0;
}