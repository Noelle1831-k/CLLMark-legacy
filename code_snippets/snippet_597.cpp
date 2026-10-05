	int i = 2;
	while (i * i <= n) {
		if (n % i == 0)
			return i;
		i++;
	}
	return n;
}
<|endoftext|>