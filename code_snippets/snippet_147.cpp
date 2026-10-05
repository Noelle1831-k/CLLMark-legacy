	int count = 0;
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		m[arr[i]]++;
	}
	map<int, int>::iterator it;
	for (it = m.begin(); it != m.end(); it++) {
		count += (it->second * (it->second - 1)) / 2;
	}
	count /= 2;
	if (count >= k)
		return count - k;
	else
		return -1;
}
<|endoftext|>