#define _CRT_SECURE_NO_WARNINGS
#define P(type,x) fprintf(stdout,"%"#type"\n",x)
int main() {
	int abacus[8][5];
	int n,i,a,j;
	while (~fscanf(stdin, "%d", &n)) {
		memset(abacus, 0, sizeof(abacus));
		i = 5;
		while (i--) {
			a = n % 10;
			if (a >= 5) abacus[0][i] = 1, a -= 5;
			else abacus[1][i] = 1;
			abacus[3 + a][i] = 1;
			n /= 10;
		}
		for (i = 0; i < 8; i++, puts("")) {
			for (j = 0; j < 5; j++) {
				if (i == 2) putchar('=');
				else if (abacus[i][j]) putchar(' ');
				else putchar('*');
			}
		}
		puts("");
	}
	return 0;
}