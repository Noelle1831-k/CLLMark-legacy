char nori[2048][2048];
int main(void) {
	int i, j;
	int menseki = 0;
	for (i = 0; i < 2; i++) {
		int x, y, w, h;
		if (scanf("%d%d%d%d", &x, &y, &w, &h) != 4) return 1;
		nori[y][x]++;
		nori[y + h][x]--;
		nori[y][x + w]--;
		nori[y + h][x + w]++;
	}
	for (i = 0; i < 2048; i++) {
		for (j = 1; j < 2048; j++) {
			nori[i][j] += nori[i][j - 1];
		}
	}
	for (i = 1; i < 2048; i++) {
		for (j = 0; j < 2048; j++) {
			nori[i][j] += nori[i - 1][j];
		}
	}
	for (i = 0; i < 2048; i++) {
		for (j = 0; j < 2048; j++) {
			if (nori[i][j] == 1) menseki++;
		}
	}
	printf("%d\n", menseki);
	return 0;
}
