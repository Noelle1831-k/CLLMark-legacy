int PERMUTATION[24][4] = {
	{0,1,2,3}, {0,1,3,2}, {0,2,1,3}, {0,2,3,1}, {0,3,1,2}, {0,3,2,1},
	{1,0,2,3}, {1,0,3,2}, {1,2,0,3}, {1,2,3,0}, {1,3,0,2}, {1,3,2,0},
	{2,1,0,3}, {2,1,3,0}, {2,0,1,3}, {2,0,3,1}, {2,3,1,0}, {2,3,0,1},
	{3,1,2,0}, {3,1,0,2}, {3,2,1,0}, {3,2,0,1}, {3,0,1,2}, {3,0,2,1}
};
void init_operators(char ops[27][3]) {
	int i, j, k, n = 0;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			for (k = 0; k < 3; k++) {
				ops[n][0] = "+-*"[i];
				ops[n][1] = "+-*"[j];
				ops[n][2] = "+-*"[k];
				n++;
			}
		}
	}
}
int calc(char op, int a, int b) {
	if (op == '+')
		return a + b;
	if (op == '-')
		return a - b;
	return a * b;
}
void solve(int data[4], char op[27][3]) {
	int i, j;
	int a, b ,c, d;
	char x, y, z;
	for (i = 0; i < 24; i++) {
		a = data[PERMUTATION[i][0]];
		b = data[PERMUTATION[i][1]];
		c = data[PERMUTATION[i][2]];
		d = data[PERMUTATION[i][3]];
		for (j = 0; j < 27; j++) {
			x = op[j][0];
			y = op[j][1];
			z = op[j][2];
			if (calc(z, calc(x, a, calc(y, b, c)), d) == 10) {
				printf("((%d %c (%d %c %d)) %c %d)\n",
						a, x, b, y, c, z, d);
				return;
			}
			if (calc(z, calc(x, a, b), calc(y, c, d)) == 10) {
				printf("((%d %c %d) %c (%d %c %d))\n",
						a, x, b, y, c, z, d);
				return;
			}
		}
	}
	puts("0");
}
int main() {
	int d[4];
	char ops[27][3];
	init_operators(ops);
	while (1) {
		scanf("%d %d %d %d ", d, d+1, d+2, d+3);
		if (!d[0] && !d[1] && !d[2] && !d[3])
			break;
		solve(d, ops);
	}
	return 0;
}