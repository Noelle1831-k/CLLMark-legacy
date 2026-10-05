	priority_queue<int> heap;
	vector<int> res;
	for (int i = 0; i < arr.size(); i++) {
		heap.push(arr[i]);
	}
	while (!heap.empty()) {
		res.push_back(heap.top());
		heap.pop();
	}
	return res;
}
<|endoftext|>