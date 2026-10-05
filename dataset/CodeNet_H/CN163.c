#define _CRT_SECURE_NO_WARNINGS
#define P(type,x) fprintf(stdout,"%"#type"\n",x)
int main() {
	int a, b, ans, h, hh, m, mm, t, c, tt;
	int d[7] = { 0,6,7,5,5,20,15 };
	int v[7][7] = { { 0,300,600,700,1350,1650 },{ 0,0,350,450,600,1150,1500 },{ 0,0,0,250,400,1000,1350 },
	{ 0,0,0,0,250,850,1300 },{ 0,0,0,0,0,600,1150 },{ 0,0,0,0,0,0,500 } };
	for (; ~fscanf(stdin, "%d", &a), a; P(d, ans)) {
		fscanf(stdin, "%d%d%d%d%d", &h, &m, &b, &hh, &mm);
		c = 0;
		if (a > b) t = a, a = b, b = t;
		t = h * 60 + m;
		tt = (hh * 60 + mm);
		ans = v[a - 1][b - 1];
		for (; a <= b; a++) c += d[a - 1];
		if (((17 * 60 + 30 <= t&&t <= 19 * 60 + 30) || (17 * 60 + 30 <= tt&& tt <= 19 * 60 + 30)) && c <= 40) {
			ans /= 2;
			ans = 50 * ((ans + 49) / 50);
		}
	}
	return 0;
}