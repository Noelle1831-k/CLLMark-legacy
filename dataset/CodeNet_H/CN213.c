#define NOMARK 100
typedef struct { int id, x, y, k; } T;
T tbl[16]; 
int X, Y, n;
char map[10][10];
char ans[10][10], cnt;
int pair[101][5][2], plen[101];
int cmp(T *a, T *b) { if (a->y - b->y) return a->y - b->y; return a->x - b->x; }
void mark(int c, int x, int y, int w, int h)
{
	int yy;
	for (yy = 0; yy < h; yy++) memset(map[y+yy]+x, c, w);
}
int check(int c, int x, int y, int w, int h)
{
	int xx, yy;
	for (yy = 0; yy < h; yy++) for (xx = 0; xx < w; xx++) 
		if (map[y+yy][x+xx] > 0 && map[y+yy][x+xx] != c) return 0;
	return 1;
}
int combi(int i)
{
	int x, y, x0, y0, id, x1, y1, h, w, j, k;
	char tmp[10][10];
	if (i == n+1) {
		if (++cnt > 1) return 0;
		memcpy(ans, map, sizeof(map));
		return 1;
	}
	k = tbl[i].k;
	if (k == 1) return combi(i+1);
	x0 = tbl[i].x, y0 = tbl[i].y, id = tbl[i].id;
	for (j = 0; j < plen[k]; j++) {
		w = pair[k][j][0], h = pair[k][j][1];
		if (x0 != NOMARK) {
			x1 = x0 - w + 1, y1 = y0 - h + 1;
			if (x1 < 0) x1 = 0; if (y1 < 0) y1 = 0;
			for (y = y1; y <= y0 && y + h <= Y; y++) {
				for (x = x1; x <= x0 && x + w <= X; x++) {
					if (!check(id, x, y, w, h)) continue;
					memcpy(tmp, map, sizeof(tmp));
					mark(id, x, y, w, h);
					if (!combi(i+1)) return 0;
					memcpy(map, tmp, sizeof(tmp));
				}
			}
		} else {
			for (y = 0; y + h <= Y; y++) {
				for (x = 0; x + w <= X; x++) {
					if (!check(id, x, y, w, h)) continue;
					memcpy(tmp, map, sizeof(tmp));
					mark(id, x, y, w, h);
					if (!combi(i+1)) return 0;
					memcpy(map, tmp, sizeof(tmp));
				}
			}
		}
	}
	return 1;
}
int main()
{
    int i, b, t, s, x, y, f;
	for (x = 1; x <= 10; x++) for (y = 1; y <= 10; y++) {
		t = x * y;
		pair[t][plen[t]][0] = x, pair[t][plen[t]++][1] = y;
	}
	while (scanf("%d%d%d", &X, &Y, &n) && n > 0) {
		for (s = f = i = 0; i < n; i++) {
			scanf("%d%d", &b, &t);
			tbl[b].k = t, tbl[b].id = b, tbl[b].x = tbl[b].y = NOMARK;
			s += t; if (plen[t] == 0) f = 1;
		}
		for (y = 0; y < Y; y++) for (x = 0; x < X; x++) {
			scanf("%d", &b), map[y][x] = b;
			if (b > 0) tbl[b].x = x, tbl[b].y = y;
		}
		if (f || s != X*Y) { puts("NA"); continue; }
		qsort(tbl+1, n, sizeof(T), cmp);
		cnt = 0;
		combi(1);
		if (cnt != 1) puts("NA");
		else for (y = 0; y < Y; y++) {
			printf("%d", ans[y][0]);
			for (x = 1; x < X; x++) printf(" %d", ans[y][x]);
			printf("\n");
		}
	}
	return 0;
}