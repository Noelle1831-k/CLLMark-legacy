int main(void) {
	int a, t, r;
	if (scanf("%d%d%d", &a, &t, &r) != 3) return 1;
	printf("%.15f\n", (double)t * r / a);
	return 0;
}
