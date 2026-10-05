#define MAX 100
typedef struct { int s, e; } CAR; CAR car[MAX + 5]; int N, top;
int park[25][2], M, used;
int go[MAX + 5], len;
int go2[MAX + 5], len2;
int cmp(int *a, int *b) { return *a - *b; }
int main()
{
	int i, t, f, first;
	while (1) {
		scanf("%d%d", &M, &N); if (!M) break;
		for (i = 1; i <= N; i++) {
			scanf("%d", &t);
			car[i].s = (i - 1) * 10, car[i].e = t;
		}
		used = 0; for (i = 0; i < M; i++) park[i][0] = park[i][1] = 0;
		for (first = f = top = 1, t = 0; f; t++) {
			f = 0;
			for (len = len2 = i = 0; i < M; i++) {
				int c1, c2;
				if (park[i][0] == 0 && park[i][1] == 0) continue;
				f = 1;
				c1 = park[i][0], c2 = park[i][1];
				if (c1 > 0 && car[c1].e > 0) car[c1].e--;
				if (c2 > 0 && car[c2].e > 0) car[c2].e--;
				if (c2 > 0 && car[c2].e == 0) {
					if (c1 == 0) go[len++] = c2, park[i][1] = 0, used--;
					else if (car[c1].e == 0)  go2[len2++] = c2, park[i][1] = 0, used--;
				}
				if (c1 > 0 && car[c1].e == 0) go[len++] = c1, park[i][0] = 0, used--;
			}
			if (len > 0) {
				qsort(go, len, sizeof(int), cmp);
				for (i = 0; i < len; i++) {
					if (first) first = 0;
					else putchar(' ');
					printf("%d", go[i]);
				}
			}
			if (len2 > 0) {
				qsort(go2, len2, sizeof(int), cmp);
				for (i = 0; i < len2; i++) {
					if (first) first = 0;
					else putchar(' ');
					printf("%d", go2[i]);
				}
			}
			while (top <= N && used < 2*M) {
				int p1, p2, p3, d, c, c2, min;
				c = top;
				if (t < car[c].s) { f = 1; break; }
				for (i = 0; i < M; i++)
					if (park[i][0] == 0 && park[i][1] == 0) { park[i][0] = c; goto DONE; }
				for (min = 10000, p1 = -1, i = 0; i < M; i++) {
					if (park[i][0] > 0 && park[i][1] > 0) continue;
					if (park[i][0] == 0) c2 = park[i][1], p3 = 0;
					else                 c2 = park[i][0], p3 = 1;
					if ((d = car[c2].e - car[c].e) >= 0 && d < min) min = d, p1 = i, p2 = p3;
				}
				if (p1 >= 0) goto SET;
				for (min = 10000, p1 = -1, i = 0; i < M; i++) {
					if (park[i][0] > 0 && park[i][1] > 0) continue;
					if (park[i][0] == 0) c2 = park[i][1], p3 = 0;
					else                 c2 = park[i][0], p3 = 1;
					if ((d = car[c].e - car[c2].e) >= 0 && d < min) min = d, p1 = i, p2 = p3;
				}
SET:			if (p2 == 1) park[p1][1] = park[p1][0];
				park[p1][0] = c;
DONE:			used++, top++, f = 1;
			}
		}
		putchar('\n');
	}
	return 0;
}