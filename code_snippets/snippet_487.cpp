	map<int, int> m;
	int count = 0;
	for (int i = 0; i < n; i++) {
		m[a[i]]++;
	}
	for (auto it = m.begin(); it != m.end(); it++) {
		if (it->second > 1) {
			count += (it->second * (it->second - 1)) / 2;
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
	cout << findOddPair(a, n);
	return 0;
}
<|endoftext|>