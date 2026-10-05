typedef struct { int a, b; } T;
T tbl[300002];
long long sa[300002];
int n;
#define MAX 300002
int que[MAX]; int qsize;
#define PARENT(i) ((i)>>1)
#define LEFT(i)   ((i)<<1)
#define RIGHT(i)  (((i)<<1)+1)
void max_heapify(int i)
{
	int l, r, max;
	int qt;
	l = LEFT(i), r = RIGHT(i);
	if (l < qsize && que[l] > que[i]) max = l; else max = i;
	if (r < qsize && que[r] > que[max]) max = r;
	if (max != i) {
		qt = que[i], que[i] = que[max], que[max] = qt;
		max_heapify(max);
	}
}
int deq()
{
	int t;
	t = que[0];
	que[0] = que[--qsize];
	max_heapify(0);
	return t;
}
void enq(int t)
{
	int i, max;
	int qt;
	i = qsize++;
	que[i] = t;
	while (i > 0 && que[max = PARENT(i)] < que[i]) {
		qt = que[i]; que[i] = que[max], que[max] = qt;
		i = max;
	}
}
int in()
{
	int n = 0;
	int c = getchar_unlocked();
	do n = (n<<3)+(n<<1) + (c & 0xf), c = getchar_unlocked();
	while (c >= '0');
	return n;
}
int cmp(T *a, T *b) { if (b->b - a->b) return b->b - a->b; return a->a - b->a; }
int check(int k)
{
	int i;
	long long s;
	if (!k) return 1;
	qsize = 0;
	for (i = 0; i < k-1; i++) enq(tbl[i].a);
	s = sa[k-1];
	for ( ; i < n; i++) {
		if (s + tbl[i].a <= (long long)k*tbl[i].b) return 1;
		s += tbl[i].a, enq(tbl[i].a);
		s -= deq();
	}
	return 0;
}
int main()
{
	int i, lo, hi, m;
	n = in();
	for (i = 0; i < n; i++) tbl[i].a = in(), tbl[i].b = in();
	qsort(tbl, n, sizeof(T), cmp);
	for (i = 0; i < n; i++) sa[i+1] = sa[i] + tbl[i].a;
	lo = 0, hi = n+1;
	while (lo + 1 < hi) {
		m = (lo + hi) >> 1;
		if (check(m)) lo = m; else hi = m;
	}
	printf("%d\n", lo);
	return 0;
}
