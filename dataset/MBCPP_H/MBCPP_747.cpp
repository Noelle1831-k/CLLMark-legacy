	int L[100][100][100];
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k <= o; k++) {
				if (i == 0 || j == 0 || k == 0)
					L[i][j][k] = 0;
				else if (x[i-1] == y[j-1] &&
					x[i-1] == z[k-1])
					L[i][j][k] = L[i-1][j-1][k-1] + 1;
				else
					L[i][j][k] = max(max(L[i-1][j][k], L[i][j-1][k]), L[i][j][k-1]);
			}
		}
	}
	return L[m][n][o];
}