	if (n <= 0)
		return 0;
	else {
		if (n == 1)
			return 1;
		else {
			int fives = n / 5;
			int rest = n % 5;
			int result = fives * 5 * 5 * 5 * 5 + rest * 5 * 5 * 5;
			return result;
		}
	}
}
<|endoftext|>