	int i = 1, c = 0;
	while (i * i <= n) {
		while (n % i == 0) {
			n /= i;
			c += 1;
		}
		i += 1;
	}
	if (n != 1)
		c += 1;
	return c;
}
<|endoftext|>