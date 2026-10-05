	int i = 1;
	int sum = 0;
	while (i <= n) {
		sum += (i * i * i * i);
		i += 2;
	}
	return sum;
}
<|endoftext|>