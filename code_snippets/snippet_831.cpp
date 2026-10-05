	int count = 0;
	sort(ar.begin(), ar.end());
	for (int i = 0; i < n; i++) {
		count += (ar[i] > 0);
		for (int j = i + 1; j < n; j++) {
			if (ar[i] > ar[j])
				count++;
		}
	}
	return count;
}
<|endoftext|>