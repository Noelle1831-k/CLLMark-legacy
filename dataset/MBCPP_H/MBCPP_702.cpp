	if (n == 0 || k > arr[n - 1]) {
		return n - 1;
	}
	int i = 0;
	int j = n - 1;
	while (i < j) {
		int m = (i + j) / 2;
		if (arr[m] <= k) {
			i = m + 1;
		} else {
			j = m;
		}
	}
	return n - 1 - i;
}