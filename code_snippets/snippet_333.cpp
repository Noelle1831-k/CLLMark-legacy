	priority_queue<int, vector<int>, greater<int>> heap; 
	for (int i = 0; i < nums.size(); i++) {
		heap.push(nums[i]);
	}
	while (!heap.empty()) {
		nums[nums.size() - 1] = heap.top();
		heap.pop();
	}
	return nums;
}
int main() {
	vector<int> nums = {18, 14, 10, 9, 8, 7, 9, 3, 2, 4, 1};
	nums = heapAssending(nums);
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
}
<|endoftext|>