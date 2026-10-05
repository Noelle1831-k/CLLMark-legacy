void* realloc2(void* asumi, size_t iguti) {
	void* ogurayui = realloc(asumi, iguti);
	if (ogurayui == NULL) exit(2);
	return ogurayui;
}
int N, M;
int s[16], e[16];
int* cars[16];
int main(void) {
	int i;
	if (scanf("%d%d", &N, &M) != 2) return 1;
	for (i = 0; i < M; i++) {
		int info, data;
		if (scanf("%d%d", &info, &data) != 2) return 1;
		if (info == 0) {
			if (s[data] >= e[data]) {
				puts("error!!!!!");
				return 1;
			}
			printf("%d\n", cars[data][s[data]++]);
		} else {
			int minLane = 0, minScore = -1;
			int j;
			for (j = 1; j <= N; j++) {
				int score = e[j] - s[j];
				if (minScore < 0 || score < minScore) {
					minScore = score;
					minLane = j;
				}
			}
			cars[minLane] = realloc2(cars[minLane], sizeof(int) * (e[minLane] + 1));
			cars[minLane][e[minLane]++] = data;
		}
	}
	return 0;
}
