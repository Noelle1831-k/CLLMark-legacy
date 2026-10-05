int main(void) {
	int N, R, T;
	int p[100];
	int haitteru[1000];
	int kara[1000];
	int i, j;
	int buin[100];
	int count = 0;
	if (scanf("%d%d%d", &N, &R, &T) != 3) return 1;
	for (i = 0; i < R; i++) haitteru[i] = kara[i] = 0;
	for (i = 0; i < N; i++) {
		if (scanf("%d", &p[i]) != 1) return 1;
		buin[i] = 0;
	}
	for (i = 0; i < T; i++) {
		for (j = 0; j < R; j++) {
			haitteru[j] += kara[j];
			kara[j] = 0;
		}
		for (j = 0; j < N; j++) {
			buin[j] = (buin[j] + p[j]) % R;
			if (i > 0) kara[buin[j]]++;
			if (haitteru[buin[j]] == 0) count++; else haitteru[buin[j]]--;
		}
	}
	printf("%d\n", count);
	return 0;
}