int x[100002], y[100002];
int in()
{
	int n = 0;
	int c = getchar_unlocked();
	if (c == '-') {
		c = getchar_unlocked();
		do n = (n<<3)+(n<<1) + (c & 0xf), c = getchar_unlocked();
		while (c >= '0');
		return -n;
	}
	do n = (n<<3)+(n<<1) + (c & 0xf), c = getchar_unlocked();
	while (c >= '0');
	return n;
}
int main()
{
	int n, i, xx, yy, xmin, xmax, ymin, ymax, d1, d2, ans1, ans2;
	n = in();
	xx = in(), yy = in();
	x[0] = xx + yy, y[0] = xx - yy;
	xmin = xmax = x[0], ymin = ymax = y[0];
	for (i = 1; i < n; i++) {
		xx = in(), yy = in();
		x[i] = xx + yy, y[i] = xx - yy;
		if      (x[i] < xmin) xmin = x[i];
		else if (x[i] > xmax) xmax = x[i];
		if      (y[i] < ymin) ymin = y[i];
		else if (y[i] > ymax) ymax = y[i];
	}
	ans1 = ans2 = 0;
	for (i = 0; i < n; i++) {
		d1 = x[i]-xmin, yy = y[i]-ymin;	if (yy > d1) d1 = yy;
		d2 = xmax-x[i], yy = ymax-y[i]; if (yy > d2) d2 = yy;
		if (d1 > d2) d1 = d2;
		if (d1 > ans1) ans1 = d1;
		d1 = x[i]-xmin, yy = ymax-y[i];	if (yy > d1) d1 = yy;
		d2 = xmax-x[i], yy = y[i]-ymin; if (yy > d2) d2 = yy;
		if (d1 > d2) d1 = d2;
		if (d1 > ans2) ans2 = d1;
    }
	if (ans1 > ans2) ans1 = ans2;
    printf("%d\n", ans1);
    return 0;
}
