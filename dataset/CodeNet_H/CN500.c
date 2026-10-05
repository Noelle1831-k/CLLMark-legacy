int main(void)
{
	int i, j, k, N, f, array[200][3], score[200] = {0};
	scanf("%d", &N);
	for (i = 0; i < N; i++){
		for (j = 0; j < 3; j++){
			scanf("%d", &array[i][j]);
		}
	}
	for (k = 0; k < 3; k++){
		for (i = 0; i < N; i++){
			f = 0;
			for (j = i + 1; j < i + N; j++){
				if (array[i][k] == array[j % N][k]){
					f = 1;
					break;
				}
			}
			if (f != 1){
				score[i] += array[i][k];
			}
		}
	}
	for (i = 0; i < N; i++){
		printf("%d\n", score[i]);
	}
	return (0);
}