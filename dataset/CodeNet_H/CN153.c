const double EPS = 1e-3;
int tx1, ty1, tx2, ty2, tx3, ty3;
int cx, cy, cr;
double
dot(int ax, int ay, int bx, int by)
{
	return ax * bx + ay * by;
}
double
cross(int ax, int ay, int bx, int by)
{
	return ax * by - ay * bx;
}
double
vabs(int x, int y)
{
	return sqrt(x * x + y * y);
}
double
getDistanceLP(int lx1, int ly1, int lx2, int ly2, int px, int py)
{
	return fabs(cross(lx2 - lx1, ly2 - ly1, px - lx1, py - ly1) / vabs(lx2 - lx1, ly2 - ly1));
}
double
getDistanceSP(int lx1, int ly1, int lx2, int ly2, int px, int py)
{
	if (dot(lx2 - lx1, ly2 - ly1, px - lx1, py - ly1) < 0.0)
		return vabs(px - lx1, py - ly1);
	if (dot(lx1 - lx2, ly1 - ly2, px - lx2, py - ly2) < 0.0)
		return vabs(px - lx2, py - ly2);
	return getDistanceLP(lx1, ly1, lx2, ly2, px, py);
}
char
solve()
{
	double r1 = vabs(tx1 - cx, ty1 - cy);
	double r2 = vabs(tx2 - cx, ty2 - cy);
	double r3 = vabs(tx3 - cx, ty3 - cy);
	if (r1 <= cr + EPS && r2 <= cr + EPS && r3 <= cr + EPS)
		return 'b';
	double th21 = atan2(tx2 - tx1, ty2 - ty1);
	double th31 = atan2(tx3 - tx1, ty3 - ty1);
	double th12 = atan2(tx1 - tx2, ty1 - ty2);
	double th32 = atan2(tx3 - tx2, ty3 - ty2);
	double thc1 = atan2(cx - tx1, cy - ty1);
	double thc2 = atan2(cx - tx2, cy - ty2);
	if (((th21 <= thc1 + EPS && thc1 <= th31 + EPS) || (th31 <= thc1 + EPS && thc1 <= th21 + EPS)) &&
	    ((th12 <= thc2 + EPS && thc2 <= th32 + EPS) || (th32 <= thc2 + EPS && thc2 <= th12 + EPS)))
	{
		r1 = getDistanceLP(tx1, ty1, tx2, ty2, cx, cy);
		r2 = getDistanceLP(tx3, ty3, tx2, ty2, cx, cy);
		r3 = getDistanceLP(tx3, ty3, tx1, ty1, cx, cy);
		if (r1 + EPS >= cr && r2 + EPS >= cr && r3 + EPS >= cr)
			return 'a';
		else
			return 'c';
	}
	else
	{
		r1 = getDistanceLP(tx1, ty1, tx2, ty2, cx, cy);
		r2 = getDistanceLP(tx3, ty3, tx2, ty2, cx, cy);
		r3 = getDistanceLP(tx3, ty3, tx1, ty1, cx, cy);
		if (r1 > cr + EPS && r2 > cr + EPS && r3 > cr + EPS)
			return 'd';
		else
			return 'c';
	}
}
int
main(int argc, char **argv)
{
	while (true)
	{
		scanf("%d%d", &tx1, &ty1);
		if (tx1 == 0 && ty1 == 0)
			break;
		scanf("%d%d", &tx2, &ty2);
		scanf("%d%d", &tx3, &ty3);
		scanf("%d%d", &cx, &cy);
		scanf("%d", &cr);
		printf("%c\n", solve());
	}
	return 0;
}