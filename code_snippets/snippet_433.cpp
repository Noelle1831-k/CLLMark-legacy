	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		pq.push(nums[i]);
	}
	vector<int> res;
	while (n) {
		res.push_back(pq.top());
		pq.pop();
		n--;
	}
	return res;
}
int main(int argc, char** argv) {
	vector<int> testInput = {25, 35, 22, 85, 14, 65, 75, 25, 58};
	int n = 3;
	vector<int> res = heapQueueSmallest(testInput, n);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << "\n";
	return 0;
}
<|endoftext|>