	map<int, int> sums;
	int count = 0;
	for (int i = 0; i < n; i++) {
		count += arr[i];
		count %= m;
		if (count == 0) {
			return true;
		}
	}
	return false;
}
<|endoftext|>