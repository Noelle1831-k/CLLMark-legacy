int main(void)
{
	int a[10][10];
	int n;
	int i, j, k, l;
	int kami = 0;
	int kami2[100];
	scanf("%d", &n);
	while (n != 0) {
		for (i = 0; i < 50; i++) {
			kami2[i] = 0;
			kami = 0;
		}
		for (j = 0; j < 10; j++) {
			for (i = 0; i < 10; i++) {
				a[i][j] = 0;
			}
		}
		for (j = 0; j < n; j++) {
			for (i = 0; i < n; i++) {
				scanf("%d", &a[i][j]);
			}
		}
		for (j = 0; j < n + 1; j++) {
			if (j < n) {
				for (i = 0; i < n; i++) {
					printf("%5d ", a[i][j]);
				}
				for (i = 0; i < n; i++) {
					kami += a[i][j];
				}
				printf("%5d", kami);
				a[n][j] = kami;
				kami = 0;
				printf("\n");
			}
			else {
				for (k = 0; k <= n; k++) {
					for (l = 0; l < n; l++) {
						kami2[k] += a[k][l];
					}
				}
				for (k = 0; k < n; k++) {
					printf("%5d ", kami2[k]);
				}
				for (k = 0; k < n; k++) {
					kami += a[4][k];
				}
				printf("%5d\n", kami);
			}
		}
		scanf("%d", &n);
	}
	return (0);
}