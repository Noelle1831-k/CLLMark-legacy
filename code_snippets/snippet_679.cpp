	string even = "Even";
	string odd = "Odd";
	int count = 0;
	for (int i = 1; i < n; i++) {
		if (n % i == 0) count++;
	}
	if (count % 2 == 0)
		return even;
	else
		return odd;
}
<|endoftext|>