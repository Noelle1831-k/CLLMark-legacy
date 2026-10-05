int main(void) {
	int n, m;
	while (scanf("%d%d", &n, &m), n) {
		int k[30000], i, j, max = 0;
		for (i = 0; i < n; ++i) {
			scanf("%d", &k[i]);
			k[i] %= m;
		}
		for (i = 0; i < n; ++i) {
			int s = 0;
			for (j = i; j < n; ++j) {
				int t = s + k[j];
				s = t >= m ? t - m : t;
				max = max < s ? s : max;
			}
		}
		printf("%d\n", max);
	}
	return 0;
}