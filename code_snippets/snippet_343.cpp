	std::sort(arr.begin(), arr.end());
	int count = 0;
	int small = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] == small) {
			count++;
		}
	}
	return count;
}
<|endoftext|>