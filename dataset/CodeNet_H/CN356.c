int gcd(int a, int b) {
	while (b > 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int main(void) {
	int x, y;
	if (scanf("%d%d", &x, &y) != 2) return 1;
	printf("%d\n", (x + 1) + (y + 1) - (gcd(x, y) + 1));
	return 0;
}
