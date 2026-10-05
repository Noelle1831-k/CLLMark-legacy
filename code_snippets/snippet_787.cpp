	int count = 1;
	while(true) {
		bool valid = true;
		for (int i = 2; i <= n; i++) {
			if (count % i != 0) {
				valid = false;
				break;
			}
		}
		if (valid) {
			return count;
		}
		count++;
	}
}
<|endoftext|>