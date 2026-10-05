	int count = 0;
	map<int, int> mymap;
	for (int i = 0; i < n; i++) {
		mymap[a[i]] = 1;
	}
	for (int i = 0; i < n; i++) {
		count += mymap[a[i]^a[i-1]];
	}
	return count;
}
<|endoftext|>