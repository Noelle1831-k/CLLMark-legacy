#define ABS(a)	((a)>=0?(a):-(a))
typedef struct { char r, c, d, k; } STACK;
STACK sk[3000]; int top;
char map[10][10];
char mk[10][10];
int mv[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int check(int h, int w, int sr, int sc, int goal)
{
	int i, r, c, d, k, nr, nc;
	memset(mk, 0, sizeof(mk));
	sk[0].r = sr, sk[0].c = sc, sk[0].d = 1, sk[0].k = 0, top = 1;
	while (top) {
		r = sk[--top].r, c = sk[top].c, d = sk[top].d, k = sk[top].k;
		if (k == goal && ABS(r-sr)+ABS(c-sc) == 1) return 1;
		if (mk[r][c]) continue;
		mk[r][c] = 1;
		d += 2; if (d >= 4) d -= 4;
		for (i = 0; i < 4; i++) {
			if (++d == 4) d = 0; 
			nr = r + mv[d][0], nc = c + mv[d][1];
			if (map[nr][nc] && !mk[nr][nc]) {
				sk[top].r = nr, sk[top].c = nc, sk[top].d = d, sk[top++].k = k+1;
			}
		}
	}
	return 0;
}
int main()
{
	int w, h, r, c, sr, sc, cnt;
	char buf[30], *p;
	while (fgets(buf, 10, stdin) && *buf != '0') {
		sscanf(buf, "%d%d", &w, &h);
		memset(map, 0, sizeof(map));
		cnt = 0, sr = 0;
		for (r = 1; r <= h; r++) {
			fgets(p=buf, 30, stdin);
			for (c = 1; c <= w; c++, p+=2) if (*p == '0') {
				map[r][c] = 1, cnt++;
				if (!sr) sr = r, sc = c;
			}
			*(p-1) = 0;
		}
		puts(w > 1 && h > 1 && check(h, w, sr, sc, cnt-1)? "Yes": "No");
	}
	return 0;
}
