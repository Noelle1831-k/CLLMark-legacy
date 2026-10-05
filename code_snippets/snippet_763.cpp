	int result = 1;
	while (x != y) {
		if (x > y) {
			x = x - y;
		} else {
			y = y - x;
		}
	}
	result = x * y;
	return result;
}
<|endoftext|>