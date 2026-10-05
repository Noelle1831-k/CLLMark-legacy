int main(void)
{
	int array[16][16];
	int h, w;
	int i, j;
	int x, y;
	int a, b;
	int n;
	while (scanf("%d %d", &a, &b)){
		if (a == 0 && b == 0){
			break;
		}
		scanf("%d", &n);
		for (i = 0; i < 16; i++){
			array[0][i] = 1;
			array[i][0] = 1;
		}
		for (i = 0; i < n; i++){
			scanf("%d %d", &x, &y);
			array[x - 1][y - 1] = 0;
		}
		for (i = 1; i <= 15; i++){
			for (j = 1; j <= 15; j++){
				if (array[i][j] != 0){
					array[i][j] = array[i][j - 1] + array[i - 1][j];
				}
			}
		}
		printf("%d\n", array[a - 1][b - 1]);
	}
	return (0);
}