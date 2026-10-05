int main(void) {
    int i, j, k, h, w;
    int m[500][500];
    int area, hmin;
    char str[501];
    while (scanf("%d %d", &h, &w), h + w) {
	area = 0;
	for (i = 0; i < h; i++) {
	    scanf("%s", str);
	    for (j = 0; j < w; j++) {
		int c;
		if (str[j] == '*') c = 0;
		else {
		    if (i == 0) c = 1;
		    else c = m[i-1][j]+1;
		}
		m[i][j] = c;
	    }
	}
	for (i = 0; i < h; i++) {
	    for (j = 0; j < w; j++) {
		hmin = 501;
		for (k = j; k < w && m[i][k] != 0; k++) {
		    if (m[i][k] < hmin) hmin = m[i][k];
		    if (area < hmin * (k-j+1)) area = hmin * (k-j+1);
		}
	    }
	}
	printf("%d\n", area);
    }
    return 0;
}