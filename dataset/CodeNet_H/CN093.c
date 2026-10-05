int leap_year(int a, int b)
{
	b = b - b % 4;
	if (a % 4 == 0) {
		a -= 4;
	}
	else {
		a = a - a % 4;
	}
	return (b - a) / 4;
}
int main(void)
{
	while (1) {
		static int first_space = 1;
		int a, b;
		scanf("%d %d", &a, &b);
		if (a == 0 && b == 0) {
			break;
		}
		if (first_space == 0) {
			printf("\n");
		}
		if (first_space == 1) {
			first_space = 0;
		}
		int n = leap_year(a, b) + 1;
		if (n == 1) {
			printf("NA\n");
		}
		if (!a == 0 || ! b == 0) {
			if (a % 4 == 0) {
				a -= 4;
			}
			int i;
			for (i = 1; i < n; i++) {
				int year = a - a % 4 + 4 * i;
				if (year % 100 == 0 && !(year % 400 == 0)) {
					continue;
				}
				printf("%d\n", year);
			}
		}
	}
	return 0;
}