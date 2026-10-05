	map<int, int> m;
	int count = 0;
	for (int i = 0; i < n; i++) {
		m[a[i]]++;
		count++;
		while (count > 0 && (m[a[i]] > 1 || (i > 0 && a[i] % a[i - 1]))) {
			m[a[i - count]]--;
			count--;
		}
	}
	return count;
}
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << largestSubset(a, n);
	return 0;
}
<|endoftext|>