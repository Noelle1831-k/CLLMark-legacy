	s = abs(s);
	int result = 0;
	for (int i = 0; i < s / 3; i++) {
		for (int j = 0; j < s / 2; j++) {
			for (int k = 0; k < s / 2; k++) {
				if (i * i + j * j == k * k) {
					result = max(result, i * j * k);
				}
			}
		}
	}
	return result;
}
<|endoftext|>