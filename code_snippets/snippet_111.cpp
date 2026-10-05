	map<int, int> mymap;
	for (int i = 0; i < n; i++) {
		mymap[arr[i]]++;
	}
	for (int i = 0; i < n; i++) {
		if (mymap[arr[i]] == 1)
			return arr[i];
	}
	return -1;
}
<|endoftext|>