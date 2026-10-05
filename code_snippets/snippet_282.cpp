	int start = 0;
	int end = a.size() - 1;
	int result = -1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (a[mid] == x) {
			result = mid;
			end = mid - 1;
		} else if (a[mid] > x) {
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}
	return result;
}
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int x;
	cin >> x;
	cout << findLastOccurrence(a, x);
}
<|endoftext|>