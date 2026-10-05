	vector<int> res;
	for(int i = n-k; i<n; i++) {
		res.push_back(a[i]);
	}
	for(int i = 0; i<n-k; i++) {
		res.push_back(a[i]);
	}
	return res;
}
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i<n; i++) {
		cin >> a[i];
	}
	printArr(splitArr(a, n, k));
	return 0;
}
<|endoftext|>