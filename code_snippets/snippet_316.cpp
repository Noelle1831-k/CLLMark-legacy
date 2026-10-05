	char arr[26] = {0};
	for (char c : str) {
		if (arr[c - 'a'] != 0) {
			return false;
		}
		arr[c - 'a']++;
	}
	return true;
}
<|endoftext|>