	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		pq.push(arr[i]);
		if (pq.size() > k)
			pq.pop();
	}
	return pq.top();
}
int main() {
	int arr[] = { 12, 3, 5, 7, 19 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 2;
	cout << kthElement(vector<int>(arr, arr + n), n, k);
	return 0;
}
<|endoftext|>