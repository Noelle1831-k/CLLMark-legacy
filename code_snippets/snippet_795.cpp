	priority_queue<int, vector<int>, greater<int>> pq; 
	for (int i = 0; i < nums.size(); i++) {
		pq.push(nums[i]);
		if (pq.size() > 3) pq.pop();
	}
	int p1 = pq.top(), p2 = pq.top(), p3 = pq.top();
	pq.pop();
	p2 = pq.top();
	pq.pop();
	p3 = pq.top();
	return max(p1 * p2 * p3, p1 * p2 * nums[nums.size() - 1], p1 * nums[nums.size() - 1] * nums[nums.size() - 2]);
}
int main(int argc, char const *argv[]) {
	vector<int> test = {25, 35, 22, 85, 14, 65, 75, 25, 58};
	cout << maximumProduct(test) << endl;
	return 0;
}
<|endoftext|>