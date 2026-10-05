	if (k == 0)
		return 1;
	int result = 1;
	for (int i = 0; i < k; i++) {
		result = result * (n - i) / (i + 1);
	}
	return result;
}
<|endoftext|>