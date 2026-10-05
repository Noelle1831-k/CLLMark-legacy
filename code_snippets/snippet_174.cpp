	for (int i = 0; i < n; i++) {
		while (arr[i] > 0 && arr[i] <= n && arr[i] != arr[arr[i] - 1]) {
			int tmp = arr[i];
			arr[i] = arr[tmp - 1];
			arr[tmp - 1] = tmp;
		}
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] != i + 1)
			return i + 1;
	}
	return n + 1;
}
int main() {
	vector<int> arr{ 1, 2, 3, -1, 5 };
	int n = 5;
	cout << firstMissingPositive(arr, n);
	return 0;
}
<|endoftext|>