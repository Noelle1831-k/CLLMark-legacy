	map<int, int> mymap;
	int count = 0;
	for (int i = 0; i < n; i++) {
		mymap[arr[i]]++;
	}
	for (int i = 0; i < n; i++) {
		int y = sum - arr[i];
		if (mymap.find(y) != mymap.end() && (arr[i] != y)) {
			count += mymap[y];
		}
	}
	return count;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int A[N];
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		cout << Sum(A, N) << endl;
	}
	return 0;
}
