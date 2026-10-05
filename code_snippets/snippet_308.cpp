	int count = 0;
	for(int i = n; i <= m; i++) {
		int f = sqrt(i);
		count += (i - f * f <= 1) * 1;
	}
	return count;
}
<|endoftext|>