	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	while (sum % 2 != 0) {
		sum++;
	}
	return sum;
}
int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << minNum(arr, n);
	return 0;
}
<|endoftext|>