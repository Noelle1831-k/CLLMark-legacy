	int low = 0, high = n - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] > x) {
			high = mid - 1;
		} else if (arr[mid] < x) {
			low = mid + 1;
		} else {
			while (mid < high && arr[mid] == x) {
				mid++;
			}
			return mid - 1;
		}
	}
	return -1;
}
int main() {
	int n, x;
	cin >> n >> x;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << last(arr, x, n);
	return 0;
}
<|endoftext|>