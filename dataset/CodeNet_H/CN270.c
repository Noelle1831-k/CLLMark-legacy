#define QMAX 205000
typedef struct { int t, node; } QUE;
QUE que[QMAX+2]; int qsize;
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
void enq(int n, int t)
{
	int i, min;
	QUE qt;
	i = qsize++;
	que[i].node = n, que[i].t = t;
	while (i > 0 && que[min = PARENT(i)].t > que[i].t) {
		qt = que[i], que[i] = que[min], que[min] = qt;
		i = min;
	}
}
#define INF 0x55555555
#define MAX 100000
typedef struct { int to[10], d[10]; } TBL;
TBL tbl[MAX+1]; int size;
int len[MAX+1];
int c[40001], d[40001];
int node[MAX+1];
char visited[MAX+1];
void dijkstra(int start)
{
	int i, s, d;
	qsize = 0;
	memset(node, INF, sizeof(int)*size);
	enq(start, 0);
	while(qsize) {
		s = que[0].node, d = que[0].t, deq();
		if (visited[s]) continue;
		visited[s] = 1;
		node[s] = d;
		for (i = 0; i < len[s]; i++) {
			if (visited[tbl[s].to[i]]) continue;
			enq(tbl[s].to[i], d+tbl[s].d[i]);
		}
	}
}
int tq[MAX+1], top, tail;
TBL tbl2[MAX+1];
int len2[MAX+1];
unsigned long long dp[MAX+1];
void topologicalSort(int goal)
{
    int s, e, i;
	memset(visited, 0, size);
	tq[0] = goal, top = 0, tail = 1;
	while (top < tail) {
		s = tq[top++];
		if (visited[s]) continue;
		for (i = 0; i < len[s]; i++) {
			e = tbl[s].to[i];
			if (node[s] == node[e] + tbl[s].d[i]) {
				tq[tail++] = e;
				tbl2[e].to[len2[e]++] = s;
			}
		}
		visited[s] = 1;
	}
}
char buf[30], *p;
int getint()
{
	int n = 0;
	while (*p >= '0') n = (n<<3) + (n<<1) + (*p++ & 0xf);
	return n;
}
int main()
{
	int r, q, u, v, w, a, b, i, j, ii, jj, k;
	fgets(p=buf, 30, stdin);
	size = getint(), p++, r = getint();
	for (i = 0; i < r; i++) {
		fgets(p=buf, 30, stdin);
		u = getint()-1, p++, v = getint()-1, p++, w = getint();
		k = len[u], tbl[u].to[k] = v, tbl[u].d[k] = w, len[u]++;
		k = len[v], tbl[v].to[k] = u, tbl[v].d[k] = w, len[v]++;
	}
	fgets(p=buf, 30, stdin);
	a = getint()-1, p++, b = getint()-1, p++, q = getint();
	for (i = 0; i < q; i++) {
		fgets(p=buf, 30, stdin), c[i] = getint()-1, p++, d[i] = getint()-1;
	}
	dijkstra(a);
	topologicalSort(b);
    for (ii = (q+63)>>6, i = 0; i < ii; i++){
        memset(dp, 0, sizeof(dp));
		jj = (i+1)<<6; if (q < jj) jj = q;
        for (j = i << 6; j < jj; j++) dp[c[j]] |= (1LL << (j & 63));
        for (j = 0; j < size; j++) {
            for (k = 0; k < len2[j]; k++) {
                dp[tbl2[j].to[k]] |= dp[j];
            }
        }
        for (j = i << 6; j < jj; j++)
            puts(((dp[d[j]] >> (j & 63)) & 1) ? "Yes" : "No");
    }
	return 0;
}