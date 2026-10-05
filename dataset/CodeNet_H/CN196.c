typedef struct {
	char team[3];
	int win;
	int lose;
} DATA;
int main(void)
{
	int n;
	int i, j;
	DATA data[11], temp;
	int r;
	while (1){
		scanf("%d", &n);
		if (n == 0) break;
		for (i = 0; i < n; i++){
			data[i].win = data[i].lose = 0;
			scanf("%s", data[i].team);
			for (j = 0; j < n - 1; j++){
				scanf("%d", &r);
				if (r == 0){
					data[i].win++;
				}
				else if (r == 1){
					data[i].lose++;
				}
			}
		}
		for (i = 0; i < n; i++){
			for (j = 0; j < n - 1; j++){
				if (data[j].win < data[j + 1].win){
					temp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = temp;
				}
				else if (data[j].win == data[j + 1].win && data[j].lose > data[j + 1].lose){
					temp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = temp;
				}
			}
		}
		for (i = 0; i < n; i++){
			printf("%s\n", data[i].team);
		}
	}
	return (0);
}
