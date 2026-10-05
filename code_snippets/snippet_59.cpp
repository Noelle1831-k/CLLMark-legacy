	int size = xs.size();
	int i;
	for (i = 0; i < size; i++) {
		if (xs[i] > xs[i + 1]) {
			break;
		}
	}
	return xs[i];
}
<|endoftext|>