	int result = 1;
	while (n) {
		result *= n % 10;
		n /= 10;
	}
	return result % 100;
}
<|endoftext|>