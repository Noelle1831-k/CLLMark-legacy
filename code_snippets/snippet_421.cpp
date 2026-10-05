	int count = 0;
	while (1) {
		count++;
		if (factorial(count) % x == 0) {
			return count;
		}
	}
}
int factorial(int n) {
	if (n <= 1)
		return 1;
	else
		return n * factorial(n - 1);
}
<|endoftext|>