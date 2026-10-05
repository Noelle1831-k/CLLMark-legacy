	priority_queue<int> heap; 
	vector<int> res; 
	for(int i=0; i<n; i++) {
		heap.push(nums[i]);
	}
	for(int i=0; i<n; i++) {
		res.push_back(heap.top());
		heap.pop();
	}
	return res;
}
int main() {
	vector<int> nums = {25, 35, 22, 85, 14, 65, 75, 22, 58};
	int n = 3; 
	vector<int> res = heapQueueLargest(nums, n);
	for(int i=0; i<n; i++) {
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}
<|endoftext|>