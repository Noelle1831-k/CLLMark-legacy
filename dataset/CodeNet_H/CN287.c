#define MAX 160010
int p[MAX], rank[MAX];
void make_set(int x) { p[x] = x, rank[x] = 0; }
void link(int x, int y) {
	if (rank[x] > rank[y]) p[y] = x;
	else { p[x] = y; if (rank[x] == rank[y]) rank[y] = rank[y] + 1;	}
}
int find_set(int x) { if (x != p[x]) p[x] = find_set(p[x]);	return p[x]; }
void union_set(int x, int y) { link(find_set(x), find_set(y)); }
#define QMAX 550000
typedef struct { int t, s; } QUE;
QUE que[QMAX]; int qsize;
#define PARENT(i) ((i)>>1)
#define LEFT(i)   ((i)<<1)
#define RIGHT(i)  (((i)<<1)+1)
void min_heapify(int i)
{
	int l, r, min;
	QUE qt;
	l = LEFT(i), r = RIGHT(i);
	if (l < qsize && que[l].t < que[i].t) min = l; else min = i;
	if (r < qsize && que[r].t < que[min].t) min = r;
	if (min != i) {
		qt = que[i], que[i] = que[min], que[min] = qt;
		min_heapify(min);
	}
}
void deq()
{
	que[0] = que[--qsize];
	min_heapify(0);
}
void enq(int s, int t)
{
	int i, min;
	QUE qt;
	i = qsize++;  if (qsize > 500000) while (1);
	que[i].s = s, que[i].t = t;
	while (i > 0 && que[min = PARENT(i)].t > que[i].t) {
		qt = que[i], que[i] = que[min], que[min] = qt;
		i = min;
	}
}
#define U 1
#define D 2
#define L 4
#define R 8
typedef struct { int px, py, qx, qy; } T;
T t[102];
int x[404], xs;
int y[404], ys;
char map[404][404];
int rel[404][404];			
int tbl[MAX][501]; int len[MAX];
int mv[4][3] = {{-1,0,D},{0,1,R},{1,0,U},{0,-1,L}};
char used[MAX];
char buf[50], *bp;
int in()
{
	int n = 0;
	while (*bp >= '0') n = 10*n + (*bp++ & 0xf);
	bp++;
	return n;
}
int cmp(int *a, int *b) { return *a - *b; }
int uniq(int *a, int n)
{
	int i, j;
	for (i = 0, j = 1; j < n; j++) {
		while (j < n && a[j] == a[i]) j++;
		if (j < n) if (++i != j) a[i] = a[j];
	}
	return i+1;
}
int bsch(int *a, int x, int r)
{
	int m, l = 0;
    while (l < r) {
        m = (l + r) >> 1;
		if (a[m] == x) return m;
        if (a[m] < x) l = m + 1; else r = m;
    }
	return l-1;
}
void pushback(int a, int b)
{
	int i;
	for (i = 0; i < len[a]; i++) {
		if (tbl[a][i] == b) return;
	}
	tbl[a][i] = b; len[a]++;
	if (len[a] >= 500) while (1){}
}
int dijkstra(int start, int goal)
{
	int i, s, d, e;
	memset(used, 0, sizeof(used));
	d = 0, qsize = 0;
	enq(start, 0);
	while (qsize) {
		s = que[0].s, d = que[0].t, deq();
		if (s == goal) break;
		if (used[s]) continue;
		used[s] = 1;
		for (i = 0; i < len[s]; i++) {
			e = tbl[s][i];
			if (used[e]) continue;
			enq(e, d+1);
		}
	}
	return d;
}
int main()
{
	int w, h, m, q, i, r, c, r2, c2, a, b;
	int px, py, qx, qy;
	fgets(bp=buf, 30, stdin);
	w = in(), h = in(), m = in();
	x[0] = y[0] = 0, xs = ys = 1;
	for (i = 0; i < m; i++) {
		fgets(bp=buf, 50, stdin);
		t[i].px = x[xs++] = in(), t[i].py = y[ys++] = in();
		t[i].qx = x[xs++] = in(), t[i].qy = y[ys++] = in();
	}
	x[xs++] = w, y[ys++] = h;
	qsort(x, xs, sizeof(int), cmp); xs = uniq(x, xs);
	qsort(y, ys, sizeof(int), cmp); ys = uniq(y, ys);
	w = bsch(x, w, xs);
	h = bsch(y, h, ys);
	for (i = 0; i < m; i++) {
		px = bsch(x, t[i].px, xs);
		py = bsch(y, t[i].py, ys);
		qx = bsch(x, t[i].qx, xs);
		qy = bsch(y, t[i].qy, ys);
		if (px == qx) {
			if (py > qy) r = py, py = qy, qy = r;
			for (r = py; r < qy; r++) {
				if (px >= 1) map[r][px-1] |= R;
				             map[r][px  ] |= L;
			}
		} else {
			if (px > qx) c = px, px = qx, qx = c;
			for (c = px; c < qx; c++) {
				if (py >= 1) map[py-1][c] |= U;
				             map[py  ][c] |= D;
			}
		}
	}
	i = 0;
	for (r = 0; r < h; r++) for (c = 0; c < w; c++) {
		p[i] = i, rel[r][c] = i++;
	}
	for (r = 0; r < h; r++) for (c = 0; c < w; c++) {
		for (i = 0; i < 4; i++) {
			r2 = r + mv[i][0], c2 = c + mv[i][1];
			if (r2 >= 0 && r2 < h && c2 >= 0 && c2 < w && !(map[r][c] & mv[i][2])) {
				union_set(rel[r][c], rel[r2][c2]);
			}
		}
	}
	for (r = 0; r < h; r++) for (c = 0; c < w; c++) {
		a = rel[r][c] = find_set(rel[r][c]);
		if (r+1 < h) {
			b = rel[r+1][c] = find_set(rel[r+1][c]);
			if (a != b) pushback(a, b), pushback(b, a);
		}
		if (c+1 < w) {
			b = rel[r][c+1] = find_set(rel[r][c+1]);
			if (a != b) pushback(a, b), pushback(b, a);
		}
	}
	fgets(bp=buf, 10, stdin), q = in();
	while (q--) {
		fgets(bp=buf, 50, stdin);
		px = bsch(x, in(), xs), py = bsch(y, in(), ys);
		a = rel[py][px];
		qx = bsch(x, in(), xs), qy = bsch(y, in(), ys);
		b = rel[qy][qx];
		printf("%d\n", dijkstra(a, b));
	}
	return 0;
}