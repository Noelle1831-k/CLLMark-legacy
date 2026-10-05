#define LIM 40
#define EPS 1e-6
typedef struct { double x, y; } PP;
typedef struct { PP s, e; } SEG, LINE;
#define EQ(a,b)  (fabs((a)-(b))<EPS)
int dcmp(double x) { if (fabs(x) < EPS) return 0; return x <= 0 ? -1 : 1; }
PP vadd(PP p1, PP p2) { PP r; r.x = p1.x + p2.x, r.y = p1.y + p2.y; return r; }
PP vsub(PP p1, PP p2) { PP r; r.x = p1.x - p2.x, r.y = p1.y - p2.y; return r; }
PP vsmul(PP p, double k) { PP r; r.x = p.x * k, r.y = p.y * k; return r; }
PP vmul(PP p1, PP p2) { PP r;
	r.x = p1.x * p2.x - p1.y * p2.y, r.y = p1.x * p2.y + p1.y * p2.x; return r; }
double cross(PP a, PP b) { return a.x * b.y - a.y * b.x; }
double dot(PP a, PP b) { return a.x * b.x + a.y * b.y; }
double vabs(PP a) { return hypot(a.x, a.y); }
double distancePL(PP p, LINE ln) { PP a = vsub(ln.e, ln.s);
	return fabs(cross(vsub(p, ln.s), a)) / vabs(a);
}
PP crossPointS2P(SEG a, PP bs, PP be) { double a1, a2; PP r;
	a1 = cross(vsub(be, bs), vsub(a.s, bs));
	a2 = cross(vsub(be, bs), vsub(a.e, bs));
	r.x = (a.s.x*a2 - a.e.x*a1) / (a2-a1);
	r.y = (a.s.y*a2 - a.e.y*a1) / (a2-a1);
	return r;
}
int convex_cut(SEG u, int n, PP *p, PP *po)		
{
	int i, d1, d2, top = 0;
    for (i = 0; i < n; i++) {
        d1 = dcmp(cross(vsub(u.e, u.s), vsub(p[i],   u.s)));
        d2 = dcmp(cross(vsub(u.e, u.s), vsub(p[i+1], u.s)));
        if (d1 >= 0) po[top++] = p[i];
        if (d1*d2 < 0) po[top++] = crossPointS2P(u, p[i], p[i+1]);
    }
	po[top] = po[0];
    return top;
}
void unitnormalv(SEG *ans, SEG a) {
	PP t; double k = vabs(vsub(a.e, a.s));
	t.x = 0, t.y =  1; ans->s = vsmul(vmul(vsub(a.e, a.s), t), 1/k);
	t.x = 0, t.y = -1; ans->e = vsmul(vmul(vsub(a.e, a.s), t), 1/k);
}
void parallelShift(SEG *ans, SEG a, double d) {
	SEG r; unitnormalv(&r, a);
	ans[0].s = vadd(a.s, vsmul(r.s, d));
	ans[0].e = vadd(a.e, vsmul(r.s, d));
	ans[1].s = vadd(a.s, vsmul(r.e, d));
	ans[1].e = vadd(a.e, vsmul(r.e, d));
}
double poly_area(int n, PP *p)
{
   int i; double s;
   for (s = 0, i = 0; i < n; i++) s += (p[i].x-p[i+1].x) * (p[i].y+p[i+1].y);
   return fabs(s)/2;
}
int in()
{
	int n = 0, c = getchar_unlocked();
	if (c == '-') {	c = getchar_unlocked();
		do n = 10*n + (c & 0xf), c = getchar_unlocked(); while (c >= '0');
		return -n;
	}
	do n = 10*n + (c & 0xf), c = getchar_unlocked(); while (c >= '0');
	return n;
}
PP p[102], po[102];
int main()
{
	int n, d, V, i, j, lim, f;
	double S, s, a, lo, hi, mi, max, ans;
	LINE ln, cut[2];
	while (n = in()) {
		d = in(), V = in(), S = (double)V / d;
		for (i = 0; i < n; i++) p[i].x = in(), p[i].y = in(); p[n] = p[0];
		s = poly_area(n, p);
		max = 0;
		for (i = 0; i < n; i++) for (j = 0; j < n; j++) if (i != j && i != j+1) {
			ln.s = p[j], ln.e = p[j+1];
			if ((a = distancePL(p[i], ln)) > max) max = a;
		}
		if (EQ(s, S) || s <= S) { printf("%.8lf\n", max); continue; }
		ans = 0;
		for (i = n; i > 0; i--) {
			ln.s = p[i], ln.e = p[i-1];
			lo = 0, hi = max;
			lim = LIM; while (lim--) {
				mi = (lo + hi)*0.5;
				parallelShift(cut, ln, mi);
				j = convex_cut(cut[1], n, p, po);
				f = 0;
				if (j >= 3 && poly_area(j, po) >= S) f = 1; 
				else {
					j = convex_cut(cut[0], n, p, po);
					if (j >= 3 && poly_area(j, po) >= S) f = 1;
				}
				if (f) hi = mi; else lo = mi;
			}
			if (hi > ans) ans = hi;
		}
		printf("%.8lf\n", ans);
	}
	return 0;
}
