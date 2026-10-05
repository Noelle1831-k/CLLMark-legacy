	int count = 0;
	for(int i = 0; i < n-1; i++) {
		for(int j = i+1; j < n; j++) {
			count += abs(arr[i] - arr[j]);
		}
	}
	return count;
}
int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << sumPairs(arr, n);
	return 0;
}
<|endoftext|>