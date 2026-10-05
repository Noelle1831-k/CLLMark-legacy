int main() {
	int costs[100][100];
	int times[100][100];
	int a, ans, b, cost, time, i, j, k, n, m, r;
	while(scanf("%d %d", &m, &n)) {
		if(n == 0 && m == 0) break;
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				times[i][j] = costs[i][j] = 1e8;
		for(i = 0; i < m; i++) {
			scanf("%d %d %d %d", &a, &b, &cost, &time);
			a -= 1; b -= 1;
			times[a][b] = times[b][a] = cost;
			costs[a][b] = costs[b][a] = time;
		}
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				for(k = 0; k < n; k++) {
					times[j][k] = times[j][k] < times[j][i] + times[i][k] ? times[j][k] : times[j][i] + times[i][k];
					costs[j][k] = costs[j][k] < costs[j][i] + costs[i][k] ? costs[j][k] : costs[j][i] + costs[i][k];
				}
			}
		}
		scanf("%d", &k);
		for(i = 0; i < k; i++) {
			scanf("%d %d %d", &a, &b, &r);
			a -= 1; b -= 1;
			ans = r ? times[a][b] : costs[a][b];
			printf("%d\n", ans);
		}
	}
	return 0;
}