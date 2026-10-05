	if (n <= 0 || m <= 0)
		return -1;
	return ((n * n) * m) / 2;
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	printf("%d", lobbNum(n, m));
	return 0;
}
<|endoftext|>