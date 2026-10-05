#define QSIZE 1000
#define PARENT(i) ((i)>>1)
#define LEFT(i)   ((i)<<1)
#define RIGHT(i)  (((i)<<1)+1)
typedef struct { short s, t; } QUE;
QUE que[QSIZE+5]; int qsize;
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
int qmax;
void enq(int s, int t)
{
	int i, min;
	QUE qt;
	i = qsize++;	if (qsize > qmax) qmax = qsize;
	que[i].s = s, que[i].t = t;
	while (i > 0 && que[min = PARENT(i)].t > que[i].t) {
		qt = que[i], que[i] = que[min], que[min] = qt;
		i = min;
	}
}
#define INF 0x10101010
#define MAX 410
typedef struct { short to, cap, cost, rev; } E;
E   edge[MAX][MAX]; short hi[MAX];
int V;				
int potential[MAX], min_cost[MAX], prevv[MAX], preve[MAX];
void add_edge(int from, int to, int cap, int cost)
{
	int f = hi[from]++, t = hi[to]++;
	E *ep = &edge[from][f]; ep->to = to, ep->cap = cap, ep->cost = cost, ep->rev = t; 
	ep = &edge[to][t], ep->to = from, ep->cap = 0, ep->cost = -cost, ep->rev = f;
}
int minCost(int S, int T, int F)
{
	int i, s, ns, t, nt, ret;
	E *ep;
	ret = 0;
	memset(potential, 0, V << 2);
    while (F > 0) {
		memset(min_cost, INF, V << 2);
		qsize = 0;
		enq(S, 0), min_cost[S] = 0;
		while (qsize) {
			s = que[0].s, t = que[0].t, deq();
			if (min_cost[s] < t) continue;
			for (i = 0; i < hi[s]; i++) {
				ep = &edge[s][i], ns = ep->to;
				nt = min_cost[s] + ep->cost + potential[s] - potential[ns];
				if(ep->cap > 0 && min_cost[ns] > nt) {
					min_cost[ns] = nt;
					prevv[ns] = s, preve[ns] = i;
					enq(ns, nt);
				}
			}
		}
		if (min_cost[T] == INF) return -1;
		for (s = 0; s < V; s++) potential[s] += min_cost[s];
		t = F;
		for (s = T; s != S; s = prevv[s]) {
			ep = &edge[prevv[s]][preve[s]];
			if (t > ep->cap) t = ep->cap;
		}
		F -= t;
		ret += t * potential[T];
		for (s = T; s != S; s = prevv[s]) {
			ep = &edge[prevv[s]][preve[s]];
			ep->cap -= t;
			edge[s][ep->rev].cap += t;
		}
    }
	return ret;
}
int M, N, P;
int c[9][9];
int r[202], t[202];
int dp[1<<16];
int in()
{
	int n = 0;
	int c = getchar_unlocked();
	do n = (n<<3)+(n<<1) + (c & 0xf), c = getchar_unlocked();
	while (c >= '0');
	return n;
}
int main()
{
	int D, K, L, M, N, P, i, j, k, w;
	int a[9], source, sink, f;
	while(D = in()) {
		K = in(), L = in();
		for (i = 0; i < D; i++) for (j = 0; j < K; j++) c[i][j] = in();
		M = in(), N = in(), P = in();
		for (i = 0; i < M; i++) {
			for (j = 0; j < K; j++) a[j] = in();
			r[i] = 0; for (j = 0; j < K; j++) r[i] |= a[j]<<(j<<1);
		}
		for (i = 0; i < P; i++) {
			for (j = 0; j < K; j++) a[j] = in();
			t[i] = 0; for (j = 0; j < K; j++) t[i] |= a[j]<<(j<<1);
		}
		memset(dp, INF, sizeof(dp));
		dp[0] = 0;
		for (i = 0; i < D; i++) for (j = 0; j < L; j++) {
			for (k = (1<<(K<<1))-1; k >= 0; k--) {
				for (w = 0; w < K; w++) if (((k >> (w<<1)) & 3) < 2) {
					if (dp[k+(1<<(w<<1))] > dp[k] + c[i][w])
						dp[k+(1<<(w<<1))] = dp[k] + c[i][w];
				}
			}
		}
		source = M + P, sink = source + 1, V = sink + 1;
		memset(hi, 0, V << 1);
		for (i = 0; i < M; i++) {
			add_edge(source, i, 1, 0);
			if (dp[r[i]] != INF) add_edge(i, sink, 1, dp[r[i]]);
		}
		for (i = 0; i < M; i++) for (j = 0; j < P; j++) {
			f = 1; for (k = 0; k < K; k++) {
				if (((r[i]>>(k<<1))&3) < ((t[j]>>(k<<1))&3)) { f = 0; break; }
			}
			if (f && dp[r[i]-t[j]] != INF) add_edge(i, M+j, 1, dp[r[i]-t[j]]);
		}
		for (i = 0; i < P; i++) add_edge(M+i, sink, 1, 0);
		printf("%d\n", minCost(source, sink, N));
	}
	return 0;
}
