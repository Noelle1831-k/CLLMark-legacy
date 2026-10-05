	while (1) {
		a = a * 3 + b * 2;
		if (a == c) return true;
		if (a > c) return false;
	}
}
int main() {
	int a, b, c;
	while (1) {
		scanf("%d %d %d", &a, &b, &c);
		printf("%d\n", doesContainB(a, b, c));
	}
	return 0;
}
<|endoftext|>