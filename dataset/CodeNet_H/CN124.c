struct TeamScore {
	char team_name[21];
	int win_n;
	int lose_n;
	int draw_n;
	int points;
};
int main(void) {
	int n;
	int i,j,k=0;
	while (1) {
		struct TeamScore data[10], *p, temp;
		p = data;
		scanf("%d",&n);
		if (n == 0)break;
		if (k++)putchar('\n');
		for (i = 0; i < n; i++) {
			scanf("%s %d %d %d", &data[i].team_name, &data[i].win_n, 
				&data[i].lose_n, &data[i].draw_n);
			data[i].points = data[i].win_n * 3 + data[i].draw_n;
		}
		for (i = 0; i < n; i++) {
			for (j = i; j < n; j++) {
				if ((p + i)->points < (p + j)->points) {
					temp = *(p + i);
					*(p + i) = *(p + j);
					*(p + j) = temp;
				}
			}
		}
		for (i = 0; i < n; i++)
			printf("%s,%d\n", (p + i)->team_name, (p + i)->points);
	}
	return 0;
}