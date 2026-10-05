int main(void) {
	int N, t;
	double asumikana = 0;
	int i;
	if (scanf("%d%d", &N, &t) != 2) return 1;
	for (i = 0; i < N; i++) {
		int x, h;
		double aoisyouta;
		if (scanf("%d%d", &x, &h) != 2) return 1;
		aoisyouta = (double)h / x;
		if (aoisyouta > asumikana) asumikana = aoisyouta;
	}
	printf("%.15f\n", asumikana * t);
	return 0;
}
