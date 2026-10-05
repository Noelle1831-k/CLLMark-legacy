	int low = 0;
	int high = n - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] == x) {
			if (mid == 0 || arr[mid - 1] != x)
				return mid;
			high = mid - 1;
		} else if (arr[mid] > x) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	return -1;
}
int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int x;
	cin >> x;
	cout << first(arr, x, n);
	return 0;
}
<|endoftext|>