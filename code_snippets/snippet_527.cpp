	int count = 0;
	for (int i = 2; i < num; i++) {
		if (num % i == 0) count++;
		if (count > 0) break;
	}
	if (count > 0) return false;
	return true;
}
<|endoftext|>