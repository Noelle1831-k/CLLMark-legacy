#define MAX 10000
typedef struct { double t; int node; } QUE;
QUE que[MAX]; int qsize;
#define PARENT(i) ((i)>>1)
#define LEFT(i)   ((i)<<1)
#define RIGHT(i)  (((i)<<1)+1)
void min_heapify(int i)
{
	int l, r, min;
	l = LEFT(i), r = RIGHT(i);
	if (l < qsize && que[l].t < que[i].t) min = l; else min = i;
	if (r < qsize && que[r].t < que[min].t) min = r;
	if (min != i) {
		QUE t = que[i]; que[i] = que[min]; que[min] = t;
		min_heapify(min);
	}
}
int deq(int *n)
{
	if (qsize == 0) return 0;
	*n = que[0].node;
	que[0] = que[--qsize];
	min_heapify(0);
	return 1;
}
void enq(int n, double t)
{
	int i, min;
	i = qsize++;
	que[i].node = n, que[i].t = t;
	while (i > 0 && que[min = PARENT(i)].t > que[i].t) {
		QUE tt = que[i]; que[i] = que[min]; que[min] = tt;
		i = min;
	}
}
#define INF 1e20
typedef struct { long long x, y; } PP;
typedef struct { int len, to[103]; double d[103]; } TBL;
TBL tbl[103];
double node[103]; int size;
char visited[103];
PP start, goal, pos[103];
double search(int start, int goal)
{
	int i, s, e;
	double k;
	TBL *tp;
	qsize = 0;
	for (i = 0; i < size; i++) node[i] = INF, visited[i] = 0;
	node[start] = 0;
	enq(start, 0);
	while(deq(&s)) {
		if (s == goal) break;
		if (visited[s]) continue;
		visited[s] = 1;
		tp = tbl + s;
		for (i = 0; i < tp->len; i++) {
			e = tp->to[i];
			if (visited[e]) continue;
			k = node[s] + tp->d[i];
			if (k < node[e]) node[e] = k, enq(e, k); 
		}
	}
	return node[goal];
}
int ppOnSeg(PP p, PP p1, PP p2)
{
	long long x1 = p1.x, y1 = p1.y, x2 = p2.x, y2 = p2.y;
	long long d;
	if (x1 > x2) { d = x1, x1 = x2, x2 = d; d = y1, y1 = y2, y2 = d; }
	return x1 <= p.x && p.x <= x2 &&
		((y1 <= y2 && y1 <= p.y && p.y <= y2) || (y1 > y2 && y2 <= p.y && p.y <= y1))
		&& (p.y - y1)*(x2 - x1) == (y2 - y1)*(p.x - x1);
}
int segCross(PP p1, PP p2, PP p3, PP p4)
{
	long long t1, t2, t3, t4;
	t1 = ((long long)(p1.y-p3.y))*(p3.x-p4.x)-((long long)(p1.x-p3.x))*(p3.y-p4.y);
	t2 = ((long long)(p2.y-p3.y))*(p3.x-p4.x)-((long long)(p2.x-p3.x))*(p3.y-p4.y);
	t3 = ((long long)(p3.y-p1.y))*(p1.x-p2.x)-((long long)(p3.x-p1.x))*(p1.y-p2.y);
	t4 = ((long long)(p4.y-p1.y))*(p1.x-p2.x)-((long long)(p4.x-p1.x))*(p1.y-p2.y);
	if ((t1 < 0 && t2 > 0 || t1 > 0 && t2 < 0) && (t3 < 0 && t4 > 0 || t3 > 0 && t4 < 0))
		return 1;
	t1 = ppOnSeg(p1, p3, p4), t2 = ppOnSeg(p2, p3, p4);
	t3 = ppOnSeg(p3, p1, p2), t4 = ppOnSeg(p4, p1, p2);
	return (t1 | t2 | t3 | t4) & 1;
}
double dist(PP p1, PP p2)
{
	return hypot((double)(p1.x-p2.x), (double)(p1.y-p2.y));
}
int main()
{
	int n, i, j, ks, kg, f;
	TBL *tps, *tpg;
	scanf("%lld%lld", &start.x, &start.y);
	scanf("%lld%lld", &goal.x, &goal.y);
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%lld%lld", &pos[i].x, &pos[i].y);
	memset(tbl, 0, sizeof(tbl));
	ks = kg = 0, tps = tbl, tpg = tbl+1;
	for (i = 0; i < n; i++) {
		int jj, k;
		for (f = 1, jj = 1, j = 0; j < n; j++, jj++)  {
			if (jj == n) jj = 0;
			if (j != i && jj != i &&
				segCross(start, pos[i], pos[j], pos[jj])) { f = 0; break; }
		}
		if (f) {
			tps->to[ks] = i+2, tps->d[ks] = dist(start, pos[i]);
			k = tbl[i+2].len, tbl[i+2].to[k] = 0, tbl[i+2].d[k] = tps->d[ks];
			ks++, tbl[i+2].len++;
		}
		for (f = 1, jj = 1, j = 0; j < n; j++, jj++) {
			if (jj == n) jj = 0;
			if (j != i && jj != i &&
			    segCross(goal, pos[i], pos[j], pos[jj])) { f = 0; break; }
		}
		if (f) {
			tpg->to[kg] = i+2, tpg->d[kg] = dist(goal, pos[i]);
			k = tbl[i+2].len, tbl[i+2].to[k] = 1, tbl[i+2].d[k] = tpg->d[kg];
			kg++, tbl[i+2].len++;
		}
	}
	tbl[0].len = ks, tbl[1].len = kg;
	for (j = 1, i = 0; i < n; i++, j++) {
		int ki, kj;
		if (j == n) j = 0;
		ki = tbl[i+2].len, tbl[i+2].to[ki] = j+2, tbl[i+2].d[ki] = dist(pos[i], pos[j]);
		kj = tbl[j+2].len, tbl[j+2].to[kj] = i+2, tbl[j+2].d[kj] = tbl[i+2].d[ki];
		tbl[i+2].len++, tbl[j+2].len++;
	}
	size = n + 2;
#if 0
for (i = 0; i < size; i++) {
	printf("[%d] len %d: ", i, tbl[i].len); 
	for (j = 0; j < tbl[i].len; j++) printf("->[%d]%lf ", tbl[i].to[j], tbl[i].d[j]);
	printf("\n");
}
printf("\n");
#endif
	printf("%.8lf\n", search(0, 1));
	return 0;
}