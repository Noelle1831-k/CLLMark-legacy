	int i = 0, j = n - 1;
	while (i < j) {
		int mid = (i + j) / 2;
		if (ar[mid] > mid) {
			j = mid - 1;
		} else {
			i = mid + 1;
		}
	}
	return i;
}
int main() {
	int n;
	cin >> n;
	vector<int> ar(n);
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	cout << findMissing(ar, n);
	return 0;
}
<|endoftext|>