#define MAX 9999991
typedef unsigned long long UL;
typedef struct { UL s; char m; } HASH;
typedef struct { UL s; char b1, b2; } QUE;
#define HASHSIZ 9999991ULL   
HASH hash[HASHSIZ + 5], *hashend = hash + HASHSIZ;
QUE Q[MAX + 5], *top, *end, *qmax = Q + MAX;
int lookup(UL s)
{
	HASH *p = hash + s % HASHSIZ;
	while (p->s) {
		if (p->s == s) return p->m;
		if (++p == hashend) p = hash;
	}
	return -1;
}
int insert(UL s, char m)
{
	HASH *p = hash + s % HASHSIZ;
	while (p->s) {
		if (p->s == s) return 0;
		if (++p == hashend) p = hash;
	}
	p->s = s, p->m = m;
	return 1;
}
int move[13][5] = {
	{ 2, -1 },
	{ 2, 5, -1 },
	{ 0, 1, 3, 6, -1 },
	{ 2, 7, -1 },
	{ 5, -1 },
	{ 1, 4, 6, 9, -1 },
	{ 2, 5, 7, 10, -1 },
	{ 3, 6, 8, 11, -1 },
	{ 7, -1 },
	{ 5, 10, -1 },
	{ 6, 9, 11, 12, -1 },
	{ 7, 10, -1 },
	{ 10, -1 } };
UL swap(UL s, int p1, int sp)
{
	UL n1;
	p1 = (12 - p1) << 2, sp = (12 - sp) << 2;
	n1 = (s >> p1) & 0xf;
	s &= ~(0xfULL << p1);
	s |= (n1 << sp);
	return s;
}
void state(void)
{
	int i, j, k, x, step, b[2];
	UL s, s2;
	s = 0x123456789ab0ULL, insert(s, 0), step = 1;
	top = end = Q;
	end->s = s, end->b1 = 0, end->b2 = 12, end++, end->s = 0, end++;
	while (top < end) {
		s = top->s, b[0] = top->b1, b[1] = top->b2; if (++top >= qmax) top = Q;
		if (!s) {
			step++, end->s = 0;
			if (++end >= qmax) end = qmax;
			if (end == top) break;
			continue;
		}
		if (step > 20) break;
		if (b[0] >= b[1]) x = b[0], b[0] = b[1], b[1] = x;
		for (i = 0; i < 2; i++) {
			k = b[i];
			for (j = 0; (x = move[k][j]) >= 0; j++) {
				if (x == b[0] || x == b[1]) continue;
				s2 = swap(s, x, k);
				if (lookup(s2) < 0) {
					insert(s2, step);
					end->s = s2;
					if (i) end->b1 = b[0], end->b2 = x;
					else   end->b1 = x, end->b2 = b[1];
					if (++end >= qmax) end = Q;
				}
			}
		}
	}
}
int main()
{
	int i, p;
	UL s;
	state();
	while (1) {
		for (s = i = 0; i < 13; i++) {
			scanf("%d", &p);
			if (i == 0 && p < 0) return 0;
			s = (s << 4) | p;
		}
		if ((p = lookup(s)) >= 0) printf("%d\n", p);
		else puts("NA");
	}
	return 0;
}