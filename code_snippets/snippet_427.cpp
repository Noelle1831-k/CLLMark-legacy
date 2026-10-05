	map<int, int> frequency;
	int largest = arr[0];
	for(int i = 0; i < n; i++){
		largest = max(largest, arr[i]);
	}
	for(int i = 0; i < n; i++){
		frequency[arr[i]]++;
	}
	return frequency[largest];
}
<|endoftext|>