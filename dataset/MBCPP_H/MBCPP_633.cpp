	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] ^ arr[j])
				sum += arr[i] ^ arr[j];
		}
	}
	return sum;
}