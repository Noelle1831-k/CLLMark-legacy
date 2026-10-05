#define SQ(a) ((a) * (a))
#define EPS 1e-2
typedef struct {
	double x;
	double y;
} POINT;
double area(double a, double b, double c)
{
	double s;
	s = (a + b + c) / 2;
	return(sqrt(s * (s - a) * (s - b) * (s - c)));
}
int main(void)
{
    int n;
	POINT a, b, c, p, k;
	double ab, bc, ca, ap, bp, cp, ak, bk, ck;
    scanf("%d", &n);
	while (n--){
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y, &p.x, &p.y, &k.x, &k.y);
		ab = sqrt(SQ(a.x - b.x) + SQ(a.y - b.y));
		bc = sqrt(SQ(b.x - c.x) + SQ(b.y - c.y));
		ca = sqrt(SQ(c.x - a.x) + SQ(c.y - a.y));
		ap = sqrt(SQ(a.x - p.x) + SQ(a.y - p.y));
		bp = sqrt(SQ(b.x - p.x) + SQ(b.y - p.y));
		cp = sqrt(SQ(c.x - p.x) + SQ(c.y - p.y));
		ak = sqrt(SQ(a.x - k.x) + SQ(a.y - k.y));
		bk = sqrt(SQ(b.x - k.x) + SQ(b.y - k.y));
		ck = sqrt(SQ(c.x - k.x) + SQ(c.y - k.y));
		if ((fabs(area(ab ,bc ,ca) - area(ap, bp, ab) - area(ap, cp, ca) - area(bp, cp, bc)) < EPS && fabs(area(ab ,bc ,ca) - area(ak, bk, ab) - area(ak, ck, ca) - area(bk, ck, bc)) < EPS) || (fabs(area(ab ,bc ,ca) - area(ap, bp, ab) - area(ap, cp, ca) - area(bp, cp, bc)) > EPS && fabs(area(ab ,bc ,ca) - area(ak, bk, ab) - area(ak, ck, ca) - area(bk, ck, bc)) > EPS)){
			printf("NG\n");
		}
		else {
			printf("OK\n");
		}
	}
	return (0);
}